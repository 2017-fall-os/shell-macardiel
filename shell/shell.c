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
    char **lines, **cdVec, **args, **directories;
    char *input, currWD[256];
    int i, dontExit = 1;
    
    SKIP_EXEC:;
    while( dontExit )
    {
        // read input
        input = shellInput( envp );
        //printf( "%s\n", input );
        
        // check if we must exit
        dontExit = strncmp(input, "exit\0", 5);
        if( !dontExit ) goto EXIT_REQUEST;
        
        lines = mytoc( input, '\n' );
        
        // check if changing directory
        if( strncmp( *lines, "cd ", 3 ) == 0 )
        {
            //printf( "we got to cd\n" );
            
            cdVec = mytoc( input, ' ' );
            
            // if input is ".." then we go back one directory
            if( strncmp(cdVec[1], "..\0", 3 ) == 0 )
            {
                //printf( "we got to .., \n" );
                getcwd( currWD, sizeof( currWD ) );
                directories = mytoc( currWD, '/' );
                
                strcpy( input, "" );
                for( i=1 ; ( directories[i] && directories[i-1] ); i++ )
                {
                    strcat( input, "/" );
                    strcat( input, directories[i-1] );
                }
                
                //printf( "input=%s\n", input );
                chdir( input );
                input = cdVec[1];
            }
            
            else
            {
                chdir( cdVec[1] ) == 0;
            }
            
            lines++;
            if( !lines )
                goto SKIP_EXEC;
        }
        
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
