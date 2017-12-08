#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#include "MyToc.h"
#include "EnvpOps.h"
#include "shellExecution.h"

#define TRUE 1
#define FALSE 0

int main(int arcgc, char *argv[], char **envp )
{
    char **envPathVec;
    char *envPathStr = (char *) malloc(sizeof(char *));
    char *prompt = "[macardiel test shell]$ ";
    int printPrompt = TRUE;
    char input[100];
    int dontExit = 1;
    
LOOP:;
    printf( "----------\n" );
    
    envPathStr = getEnv( envp );
    printf( "%s\n\n", envPathStr );
    
    if( checkPS1( envp ) )
        printPrompt = FALSE;
    
    // Print prompt if appropriate
    if( printPrompt )
    printf( "%s", prompt );
    
    // read input
    fgets( input, 100, stdin );
    
    // check if we must exit
    dontExit = strncmp(input, "exit\n", 5);
    if( !(dontExit) )
    {
        goto EXIT_SHELL;
    }
    
    //Time to execute!
    executeCommand( mytoc( input, ' ' ), mytoc( envPathStr, ':' ) );
    
    goto LOOP;
    
EXIT_SHELL:;
    exit(1);
}
