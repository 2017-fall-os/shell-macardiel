#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int executeCommand( char **args )
{
    pid_t currPID;
    currPID = fork();
    
    //printf( "currPID = %d\n", currPID );
    
    if( currPID < 0 ) {
        fprintf( stderr, "Error during fork process\n" );
        return -1;
    }
    
    else if( currPID == 0 ) {
        //printf( "Doing shellExecution.c else if\n" );
        //freopen( "output.txt", "w", stdout );
        //printf( "output.txt", "w", stdout );
        execvp( args[0], args );
    }
    
    else
    {
        wait(NULL);
        //printf( "Doing shellExecution.c else\n" );
    }
    
    return 0;
}
