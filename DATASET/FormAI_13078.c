//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main()
{
    int i;
    int random_numbers[ARRAY_SIZE];
    
    srand(time(NULL)); //seed the random number generator

    //generate random numbers and store them in the array
    for(i=0; i<ARRAY_SIZE; i++)
    {
        random_numbers[i] = rand() % 100;
    }

    //print out the random numbers
    printf("Random Numbers:\n");
    for(i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d ", random_numbers[i]);
    }
    printf("\n");

    //find and print the max number
    int max_number = random_numbers[0];
    for(i=1; i<ARRAY_SIZE; i++)
    {
        if(random_numbers[i] > max_number)
        {
            max_number = random_numbers[i];
        }
    }
    printf("Max Number: %d\n", max_number);

    //find and print the min number
    int min_number = random_numbers[0];
    for(i=1; i<ARRAY_SIZE; i++)
    {
        if(random_numbers[i] < min_number)
        {
            min_number = random_numbers[i];
        }
    }
    printf("Min Number: %d\n", min_number);

    return 0;
}