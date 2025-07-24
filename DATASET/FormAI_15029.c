//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    char response;
    int num1, num2;

    printf("Welcome to the hilarious Error Handling program!\n");

    printf("Please input two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) { // checking if two integers were scanned.
        printf("Uh oh, looks like someone can't follow instructions! Here's a code for you to copy and paste into Google:\n");
        printf("%s", "how to learn counting for beginners\n");
        exit(1); // exiting program
    }

    if (num2 == 0) { // handling division by zero error.
        printf("Oopsie! You can't divide by zero! No worries, I have a solution: just divide it by itself! Here, I'll fix it for you:\n");
        num2 = num2 + num2; // fixing input error
    }

    int result = num1 / num2;
    if (result < 0) { // handling negative result error.
        printf("Oh no! Your math skills need some polishing up! You can't get a negative result in integer division! Don't worry, I got your back!\n");
        result = abs(result); // fixing error by converting result to absolute value.
    }

    printf("The result of the division is: %d\n", result);
    printf("Would you like to try again? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') { // restarting program.
        printf("Alright, let's try again! I hope you don't mess up this time!\n");
        main(); // calling main again
    } else {
        printf("Thanks for playing with me! Until next time!\n");
        return 0;
    }
}