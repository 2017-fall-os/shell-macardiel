#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int executeCommand( char **args )
{
    pid_t currPID;
    
    currPID = fork();
    
    if( currPID < 0 ) {
        fprintf( stderr, "Error during fork process\n" );
        return -1;
    }
    
    else if( currPID == 0 ) {
        freopen( "output.txt", "w", stdout );
        execvp( args[0], args );
    }
    
    else
    {
        ;
    }
    
    return 0;
}
