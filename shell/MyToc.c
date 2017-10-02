#include <stdio.h>
#include <stdlib.h>

#define IN 1 /* Inside a word */
#define OUT 0 /* outside a 'd */

char ** mytoc( char *paragraph, char delim ){
    
    int n, i, currChar, numWords, state, pIndex; 
    // number, index, current character, number of words, and state (in or out), pointer index
    
    state = OUT; // By default, we are not inside a word until the loop starts
    numWords = 0;
    
    for( n = 0; paragraph[n]; n++ ) {
        currChar = paragraph[n];
        // if current char is a deliminator, we are not in a word
        if( currChar == delim || currChar == '\n' || currChar == '\t' )
            state = OUT;
        // otherwise we are in a word and count up
        else if( state == OUT ) {
            state = IN;
            ++numWords;
        }
    }
    
    // knowing the number of workds, we can allocate enough space for the token vector
    char **tokens = calloc( numWords+2, sizeof(char*));
    
    // clever solution: rather than copying the string or individual words and counting the number
    // of characters each has, we can modify the existing string such that instances of the deliminator
    // are turned into the null character (indicating the end of that string), and point each element 
    // of the token vector to the address of the first element of each individual word!
    
    char temp = delim;
    pIndex = 0;
    
    for( i = 0; paragraph[i]; i++ ) {
        if( paragraph[i] == delim || paragraph[i] == '\n' || paragraph[i] == '\t' ) {
            temp = paragraph[i];
            paragraph[i] = '\0';
        }
        else if( paragraph[i] != '\0' && ( temp == delim || temp == '\n' || temp == '\t' ) ) {
            tokens[ pIndex++ ] = &paragraph[i];
            temp = paragraph[i];
        }
    }
    return tokens;
}
