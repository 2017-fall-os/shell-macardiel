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
    char **envPathVec;
    char *envPathStr = (char *) malloc(sizeof(char *));
    char *input;
    int dontExit = 1;
    
    while( dontExit )
    {
        envPathStr = getEnv( envp );
        //printf( "%s\n\n", envPathStr );
        
        // read input
        input = shellInput( envp );
        //printf( "%s\n", input );
        
        // check if we must exit
        dontExit = strncmp(input, "exit\0", 5);
        
        //Time to execute!
        executeCommand( mytoc( input, ' ' ), mytoc( envPathStr, ':' ) );
    }
    exit(1);
}
