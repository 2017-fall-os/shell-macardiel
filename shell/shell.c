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
    char **tokenV, **envPathVec;
    char *envPathStr;
    char *prompt = "[macardiel test shell]$ ";
    int printPrompt = TRUE;
    char input[100];
    int dontExit = 1;
    
    // Debug Code
    printf( "\n----------Use to debug----------\n" );
    
    envPathStr = getEnv( envp );
    
    printf( "%s\n", envPathStr );
    
    // Check if PS1 has something, else we dont print the prompt
    if( checkPS1( envp ) )
        printPrompt = FALSE;
    printf( "----------end debug----------\n\n" );
    //End debug code
    
LOOP:;
    // Tokenize env path to get all possible directories
    envPathVec = mytoc( envPathStr, ':' );
    
    // Print prompt if appropriate
    if( printPrompt )
    printf( "%s", prompt );
    
    // read input
    fgets(input, 100, stdin );
    
    // check if we must exit
    dontExit = strncmp(input, "exit\n", 5);
    if( !(dontExit) )
    {
        printf( "\tGood Bye!\n\n" );
        goto EXIT_SHELL;
    }
    
    tokenV = mytoc( input, ' ' );
    
    //printTokens( tokenV );
    
    /*
    printf( "command: %s\narguments:\n", *tokenV );
    tokenV++;
    printTokens( tokenV );
    */
    
    //char *envp[] = { "PATH=/bin:/usr/bin", (char *)0 };
    
    //executing commands
    executeCommand( tokenV, envPathVec );
    
    goto LOOP;
    
EXIT_SHELL:;
    //printf( "----------exiting macardiel shell----------\n\n" );
    exit(1);
}
