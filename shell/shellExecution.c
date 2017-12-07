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
    int i;
    
    //printf( "currPID = %d\n", currPID );
    
    if( currPID < 0 ) {
        fprintf( stderr, "Error during fork process\n" );
        return -1;
    }
    
    else if( currPID == 0 ) {
        printf( "--Child: Doing shellExecution.c else if\n" );
        //freopen( "output.txt", "w", stdout );
        //printf( "output.txt", "w", stdout );
        for( i=0 ; envp ;)
        {
            char *currArg = (char *)malloc(sizeof(args[0])+sizeof(envp)+1);
            strcpy( currArg, *envp );
            strcat( currArg, "/" );
            strcat( currArg, args[0] );
            printf( "currArg=%s, *envp=%s\n\n", currArg, *envp );
            int check = execve( currArg, args, envp );
            //free(currArg);
            envp++;
        }
        exit(1);
    }
    
    else
    {
        wait(NULL);
        printf( "--Parent: Doing shellExecution.c else\n" );
    }
    
    return 0;
}
