//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed random number generator with time
    srand(time(NULL));

    // Introduce the program
    printf("Welcome to the Random Number Generator!\n");
    printf("Please enter the range of numbers you'd like to generate, separated by a space: ");

    // Get user input for range of numbers
    int min, max;
    scanf("%d %d", &min, &max);

    // Ensure that max is greater than or equal to min
    if (max < min) {
        int temp = max;
        max = min;
        min = temp;
    }

    // Introduce the generated number
    printf("Your randomly generated number is: ");

    // Generate random number within the specified range
    int num = rand() % (max - min + 1) + min;

    // Print the generated number
    printf("%d", num);

    return 0;
}