//FormAI DATASET v1.0 Category: Random ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, random_num;
    srand(time(NULL));

    printf("Welcome to the C Random Example Program!\n");
    printf("Generating 10 random numbers between 1 and 100....\n");

    for(i = 0; i < 10; i++)
    {
        random_num = rand() % 100 + 1; // generate a number between 1 and 100
        printf("Random Number %d: %d\n", i+1, random_num);
    }

    printf("\nGenerating a random decimal number between 0 and 1....\n");

    float random_float = (float)rand() / (float)RAND_MAX; // generate a random decimal number between 0 and 1
    printf("Random Float: %f\n", random_float);

    printf("\nGenerating a random character....\n");

    char random_char = 'A' + (rand() % 26); // generate a random character between A and Z
    printf("Random Character: %c\n", random_char);

    printf("\nThank you for using the C Random Example Program!\n");

    return 0;
}