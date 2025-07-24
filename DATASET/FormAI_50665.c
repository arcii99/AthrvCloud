//FormAI DATASET v1.0 Category: Random ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Random Number Generator!\n");

    // Generate a random seed using the current time
    srand(time(NULL));
    
    // Initialize variables
    int min, max, num;
    char choice;

    // Prompt user for minimum and maximum values
    printf("Enter a minimum value: ");
    scanf("%d", &min);
    printf("Enter a maximum value: ");
    scanf("%d", &max);

    // Check for valid input range
    if (min >= max) {
        printf("Error: Invalid input range.\n");
        return 1;
    }

    // Prompt user to generate a number
    printf("Would you like to generate a random number? (y/n)\n");
    scanf(" %c", &choice);

    // User input loop
    while (choice == 'y' || choice == 'Y') {

        // Generate random number within input range
        num = min + rand() % (max - min + 1);

        // Print result to console
        printf("Your random number is: %d\n", num);

        // Prompt user to generate another number
        printf("Would you like to generate another random number? (y/n)\n");
        scanf(" %c", &choice);
    }

    printf("Thanks for using the Random Number Generator!\n");

    return 0;
}