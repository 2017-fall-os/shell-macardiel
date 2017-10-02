#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "MyToc.h"

void printTokens( char **tVector ) {
    char **tvTemp;
    int n;
    
    tvTemp = tVector;
    
    for( n = 0; *tvTemp != '\0'; n++ ) {
        printf( "%d: \"%s\"\n", n, *tvTemp );
        tvTemp++;
    }
    printf( "\n" );
}

int main() {
    char **tokenV;
    char input[100];
    int exitKey = 1;
    
LOOP:;
    printf( "[macardiel test shell]$ " );
    fgets(input, 100, stdin );
    
    exitKey = strncmp(input, "exit", 4);
    //printf( "exitkey = %d\n", exitKey );
    
    if( !(exitKey) ) goto EXIT_TEST;
    
    tokenV = mytoc( input, ' ' );
    printTokens( tokenV );
    
    goto LOOP;
    
EXIT_TEST:;
    exit(1);
}
