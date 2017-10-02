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
    char test1[] = "Hello my dog's name is Darwin";
    char test2[] = "     Hello   World!    ";
    char test3[] = "";
    char test4[] = "          ";
    char test5[] = " HelloWorld";
    char input[100];
        
    printf( "\nTest1: \"%s\"\n", test1 );
    tokenV = mytoc( test1, ' ');
    printTokens( tokenV );
    
    printf( "Test2: \"%s\"\n", test2 );
    tokenV = mytoc( test2, ' ');
    printTokens( tokenV );
    
    printf( "Test3: \"%s\"\n", test3 );
    tokenV = mytoc( test3, ' ');
    printTokens( tokenV );
    
    printf( "Test4: \"%s\"\n", test4 );
    tokenV = mytoc( test4, ' ');
    printTokens( tokenV );
    
    printf( "Test5: \"%s\"\n", test5 );
    tokenV = mytoc( test5, ' ');
    printTokens( tokenV );
    
    printf("----------\n\n");
    
    int exitKey = 1;
    
LOOP:;
    printf( "$ " );
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
