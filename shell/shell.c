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
    int cdRet = 0;
    
    SKIP_EXEC:;
    while( dontExit )
    {
        
        // read input
        input = shellInput( envp );
        //printf( "%s\n", input );
        
        // check if we must exit
        dontExit = strncmp(input, "exit\0", 5);
        if( !dontExit ) goto EXIT_REQUEST;
        
        // check if changing directory
        if( strncmp(input, "cd ", 3 ) == 0 )
        {
            printf( "we got to cd\n" );
            
            lines = mytoc( input, ' ' );
            printf( "tokens:\n" );
            printTokens( lines );
            
            cdRet = chdir( lines[1] );
            
            if( cdRet == 0 )
                write( 1, "Error: Failed Directory Change\n", 32 );
            goto SKIP_EXEC;
        }
        
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
