//FormAI DATASET v1.0 Category: Random ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n;
    time_t t;
    
    // Initialize random number generator
    srand((unsigned) time(&t));
    
    // Get user input for number of random numbers to generate
    printf("Enter how many random numbers you want to generate: ");
    scanf("%d", &n);
    
    // Generate n random numbers and print them
    printf("The random numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", rand());
    }
    
    return 0;
}