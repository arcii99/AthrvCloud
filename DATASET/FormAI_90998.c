//FormAI DATASET v1.0 Category: Random ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int i, n;
    time_t t;
 
    // Initialization of random number generator
    srand((unsigned) time(&t));
 
    printf("Enter the number of random numbers you want: ");
    scanf("%d", &n);
 
    printf("Random numbers between 1 and 100:\n");
 
    // Generating n random numbers between 1 and 100
    for(i = 0; i < n; i++)
    {
        printf("%d\n", (rand() % 100) + 1);
    }
 
    return 0;
}