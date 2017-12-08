#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int executeCommand( char **args, char **envp )
{
    pid_t currPID;
    currPID = fork();
    char *currArg = (char *) malloc(sizeof(char*) );
    int i;
    
    printf( "currPID = %d\n", currPID );
    
    if( currPID < 0 ) {
        printf( "Error during fork process\n" );
        return -1;
    }
    
    else if( currPID == 0 ) {
        printf("\nchild: fork returned %d\n\n", currPID);
        
        while( envp )
        {
            strcpy( currArg, *envp );
            strcat( currArg, "/" );
            strcat( currArg, args[0] );
            int retVal = execve( currArg, args, envp );
            
            fprintf(stderr, "%s: exec returned %d\n", args[0], retVal);
            envp++;
        }
        printf( "Command not recognized\n" );
        exit(2);
    }
    
    else
    {
        wait(NULL);
        printf("\nparent: child's pid=%d\n", currPID);
        free( currArg );
        return 0;
    }
    
    return 0;
}
