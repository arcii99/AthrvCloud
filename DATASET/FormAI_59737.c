//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main() {
    int n = 5;
    int i, j, k;

    //Printing upper pattern
    for ( i = 1; i <= n; i++ ) {
        //Printing spaces
        for ( j = n; j > i; j-- ) {
            printf( " " );
        }
        //Printing stars
        for ( k = 1; k <= i; k++ ) {
            printf( "*" );
        }
        //Printing newline
        printf( "\n" );
    }

    //Printing lower pattern
    for ( i = 1; i <= n; i++ ) {
        //Printing spaces
        for ( j = 1; j < i; j++ ) {
            printf( " " );
        }
        //Printing stars
        for ( k = n; k >= i; k-- ) {
            printf( "*" );
        }
        //Printing newline
        printf( "\n" );
    }

    return 0;
}