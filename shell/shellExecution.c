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
    
    //printf( "currPID = %d\n", currPID );
    
    if( currPID < 0 ) {
        fprintf( stderr, "Error during fork process\n" );
        return -1;
    }
    
    else if( currPID == 0 ) {
        printf( "Doing shellExecution.c else if\n" );
        //freopen( "output.txt", "w", stdout );
        //printf( "output.txt", "w", stdout );
        int check = execve( args[0], args, envp );
        
        //if( check ) printf( "command not recognized; execution failed\n" );
        if( check ) 
        {   
            exit(1);
            char *BIN_Path[] = { "PATH=/bin:/usr/bin", (char *)0 };
                
            int checkPath = execve( args[0], args, BIN_Path );
            
            if( checkPath ) printf( "command not recognized; execution failed\n" );
        }
    }
    
    else
    {
        wait(NULL);
        printf( "Doing shellExecution.c else\n" );
    }
    
    return 0;
}
