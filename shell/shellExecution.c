#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "EnvpOps.h"
#include "MyToc.h"

char *shellInput( char **envp )
{
    int len;
    int bufferSize = 256;
    char *input = malloc( sizeof(char) * bufferSize );
    char *prompt = "[macardiel test shell]$ ";
    int printPrompt = 1;
        
    printPrompt = checkPS1( envp );
    if( printPrompt )
        write( 1, prompt, 24 );
        
    len = read( 0, input, 256 );
    
    if( len == 0 ) exit(0);
    
    input[ len-1] = '\0';
    
    return input;
}

int executeCommand( char **args, char **envp )
{
    pid_t currPID;
    currPID = fork();
    char *currArg = (char *) malloc(sizeof(char*) );
    char **envPathVec;
    int i;
    
    //printf( "currPID = %d\n", currPID );
    
    if( currPID < 0 ) {
        printf( "Error during fork process\n" );
        return -1;
    }
    
    else if( currPID == 0 ) {
        //printf("\nchild: fork returned %d\n\n", currPID);
        
        execve( args[0], args, envp );
        
        envPathVec = mytoc( getEnv( envp ), ':' );
    
        while( *envPathVec )
        {
            strcpy( currArg, *envPathVec );
            strcat( currArg, "/" );
            strcat( currArg, args[0] );
            
            int retVal = execve( currArg, args, envp );
            
            //fprintf(stderr, "%s: exec returned %d\n", args[0], retVal);
            envPathVec++;
        }
        printf( "Error: Command not recognized\n" );
        exit(2);
    }
    
    else
    {
        wait(NULL);
        //printf("\nparent: child's pid=%d\n", currPID);
        free( currArg );
        return 0;
    }
    
    return 0;
}

int executePipes( char **pipeVec, char **envp )
{
    char **args;
    int pid;
    int *pipeFds;
    pipeFds = (int *) calloc(2, sizeof(int));
    pipe(pipeFds);

    pid = fork();
    if (pid == 0) {		/* child */
        printf("child: fork returned %d\n", pid);
        
        args = mytoc( pipeVec[0], ' ' );
        printTokens( args );
        
        close(1);
        dup(pipeFds[1]);
        close(pipeFds[0]); close(pipeFds[1]);

        executeCommand( args, envp );
        
        exit(2);

    } else { 			/* parent */

        int waitVal, waitStatus;
        char buf[100];
        int childStatus; 
        printf("parent: child's pid=%d\n", pid);

        close(0);
        dup(pipeFds[0]);
        close(pipeFds[0]); close(pipeFds[1]);

        fgets(buf, 100, stdin);
        strcat( pipeVec[1], " " );
        strcat( pipeVec[1], buf );
        
        fgets(buf, 100, stdin);
        sprintf("parent read:\n <%s> \n", buf);

        waitVal = waitpid(pid, &waitStatus, 0);
        
        if (waitVal == pid) {
            printf("child exited with value %d, %d\n", waitStatus, WEXITSTATUS(waitStatus));
        } 
        
        else {
            printf("strange: waitpid returned %d\n", waitVal);
        }
        return 0;
    }
}
