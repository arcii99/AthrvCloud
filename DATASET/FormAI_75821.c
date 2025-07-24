//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, num;
    int upper_bound = 10;
    int lower_bound = 1;
    
    srand(time(0));
    
    printf("Generating 10 random numbers between 1 and 10:\n");
    for(i = 0; i < 10; i++)
    {
        num = (rand() % (upper_bound - lower_bound + 1)) + lower_bound; // Generate random number between 1 and 10
        printf("%d ", num);
    }
    printf("\n");
    
    return 0;
}