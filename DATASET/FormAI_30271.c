//FormAI DATASET v1.0 Category: Random ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h> // for rand() function

// function to generate random numbers in range [a, b]
int generateRandomNumber(int a, int b)
{
    int num = (rand() % (b - a + 1)) + a; // generates a random number in [a, b]
    return num;
}

int main()
{
    // initializing parameters
    int lower = 1, upper = 10, i, num;

    printf("Generating 10 random numbers between 1 and 10:\n");

    for (i = 0; i < 10; i++) {
        num = generateRandomNumber(lower, upper);
        printf("%d ", num);
    }

    return 0;
}