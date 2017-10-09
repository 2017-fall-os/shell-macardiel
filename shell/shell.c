#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#include "MyToc.h"
#include "shellExecution.h"

int main() {
    char **tokenV;
    char input[100];
    int exitKey = 1;
    
    //printf( "\n----------entering macardiel shell----------\n" );
    
LOOP:;
    printf( "[macardiel test shell]$ " );
    fgets(input, 100, stdin );
    
    exitKey = strncmp(input, "exit\n", 5);
    //printf( "exitkey = %d\n", exitKey );
    
    if( !(exitKey) ) goto EXIT_SHELL;
    
    tokenV = mytoc( input, ' ' );
    
    printTokens( tokenV );
    
    /*
    printf( "command: %s\narguments:\n", *tokenV );
    tokenV++;
    printTokens( tokenV );
    */
    
    executeCommand( tokenV );
    
    goto LOOP;
    
EXIT_SHELL:;
    //printf( "----------exiting macardiel shell----------\n\n" );
    exit(1);
}
