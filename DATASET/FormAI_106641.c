//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    
    printf("Generating 10 random numbers between 1 and 100:\n");
    
    for(int i=1; i<=10; i++)
    {
        int rand_num = rand() % 100 + 1; // generate random number between 1 and 100
        printf("Random Number %d: %d\n", i, rand_num);
    }
    
    printf("\nGenerating 5 even numbers between 10 and 50:\n");
    
    int even_count = 0;
    while(even_count < 5)
    {
        int rand_num = rand() % 41 + 10; // generate random number between 10 and 50
        if(rand_num % 2 == 0) // check if number is even
        {
            even_count++; // increment even count
            printf("Even Number %d: %d\n", even_count, rand_num);
        }
    }
    
    return 0;
}