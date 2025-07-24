//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

    printf("Welcome to the Random Number Generator!\n\n");
    printf("In this program, we will be generating random numbers. You will specify the range\n");
    printf("in which you want to generate the numbers, and how many numbers you want to generate.\n\n");

    int min, max, num;
    printf("Please enter the minimum value of the range: ");
    scanf("%d", &min);
    printf("Please enter the maximum value of the range: ");
    scanf("%d", &max);
    printf("Please enter the number of random numbers to generate: ");
    scanf("%d", &num);

    // Seed the RNG with the current time
    srand(time(NULL));

    printf("\nGenerating %d random numbers between %d and %d...\n\n", num, min, max);

    for (int i = 0; i < num; i++) {
        int random_num = (rand() % (max - min + 1)) + min;
        printf("%d\n", random_num);
    }

    printf("\nThank you for using the Random Number Generator! Goodbye!\n");

    return 0;
}