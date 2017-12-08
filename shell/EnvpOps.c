#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "MyToc.h"
#include "EnvpOps.h"

char *getEnv( char **envp )
{
    char **tempTok;
    char *environmentPath;
    int i;
    
    environmentPath = 0;
    
    for( i=0 ; envp[i] ; i++ ) // looking for 'PATH'
    {
        tempTok = mytoc( envp[i], '=' ); // tokenizing current element
        
        if( strcmp( tempTok[0], "PATH" ) == 0 ) // have we found PATH?
        {
            if( tempTok[1] ) // Does PATH have anything in it?
                return tempTok[1];
        }
    }
    
    return environmentPath;
}

int checkPS1( char **envp )
{
    char **tempTok;
    int PS1NotEmpty = 0;
    int i;
    
    for( i=0 ; envp[i] ; i++ ) // looking for 'PATH'
    {
        tempTok = mytoc( envp[i], '=' ); // tokenizing current element
        
        if( strcmp( tempTok[0], "PS1" ) == 0 ) // have we found PATH?
        {
            if( tempTok[1] ) // Does PATH have anything in it?
                PS1NotEmpty = 1;
        }
    }
    //printf( "PS1 = %s\n", PS1NotEmpty );
    return PS1NotEmpty;
}
