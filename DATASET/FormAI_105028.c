//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000
#define NUM_TESTS 100

double benchmark( void )
{
    int i, j;
    double sum;
    clock_t start, end;

    start = clock();

    // Perform 1000 iterations of summation
    for ( j = 0; j < NUM_TESTS; j++ ) {
        sum = 0.0;
        for ( i = 0; i < ARRAY_SIZE; i++ ) {
            sum += (double)rand() / RAND_MAX;
        }
    }
    
    end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main( int argc, char *argv[] ) 
{
    srand( time(NULL) );
    double time_spent;
    int i;

    printf( "%-10s%s\n", "ARRAY SIZE", "TIME (s)" );

    for ( i = 10; i <= ARRAY_SIZE; i *= 10 ) {
        time_spent = benchmark();

        printf( "%-10d%.6f\n", i, time_spent );
    }

    return 0;
}