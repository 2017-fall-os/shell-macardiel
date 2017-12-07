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
    char **tokenV;
    char *envPath;
    char *prompt = "[macardiel test shell]$ ";
    int printPrompt = TRUE;
    char input[100];
    int exitKey = 1;
    
    printf( "\n----------Use to debug----------\n" );
    
    //printf( "\nenvpPATH ---> %s\n", envp[3] );
    //envPath = mytoc( getEnv("PATH"), ':' );
    //printTokens( envPath );
    printf( "All good up till line 28\n" );
    
    envPath = getEnv( envp );
    
    printf( "got envPath\n" );
    
    printf( "%s\n", envPath );
    
    if( checkPS1( envp ) )
        printPrompt = FALSE;
    printf( "\n----------end debug----------\n\n" );
LOOP:;
    if( printPrompt )
    printf( "%s", prompt );
    
    fgets(input, 100, stdin );
    
    exitKey = strncmp(input, "exit\n", 5);
    //printf( "exitkey = %d\n", exitKey );
    
    if( !(exitKey) ) goto EXIT_SHELL;
    
    tokenV = mytoc( input, ' ' );
    
    //printTokens( tokenV );
    
    /*
    printf( "command: %s\narguments:\n", *tokenV );
    tokenV++;
    printTokens( tokenV );
    */
    
    //char *envp[] = { "PATH=/bin:/usr/bin", (char *)0 };
    
    //executing commands
    executeCommand( tokenV, envp );
    
    goto LOOP;
    
EXIT_SHELL:;
    //printf( "----------exiting macardiel shell----------\n\n" );
    exit(1);
}
