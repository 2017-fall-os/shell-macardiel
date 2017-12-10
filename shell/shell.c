#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include "MyToc.h"
#include "EnvpOps.h"
#include "shellExecution.h"

int main(int arcgc, char *argv[], char **envp )
{
    char **lines;
    char **args;
    char *input;
    int dontExit = 1;
    
    while( dontExit )
    {
        // read input
        input = shellInput( envp );
        //printf( "%s\n", input );
        
        // check if we must exit
        dontExit = strncmp(input, "exit\0", 5);
        if( !dontExit ) goto EXIT_REQUEST;
        
        lines = mytoc( input, '\n' );
        
        while( *lines )
        {
            args = mytoc( *lines, ' ' );
            lines++;
            
            executeCommand( args, envp );
        }
    }
    
    EXIT_REQUEST:;
    exit(1);
}
