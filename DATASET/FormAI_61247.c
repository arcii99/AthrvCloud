//FormAI DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // set up variables
    int num1, num2, userAnswer, correctAnswer;
    char operation;
    char redo = 'y'; // initialize to 'y' to start the loop

    // seed random number generator
    srand(time(NULL));

    // loop until user wants to stop
    while (redo == 'y') {
        // randomly generate two numbers between 1 and 10
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // randomly determine the operation
        if (rand() % 2 == 0) {
            operation = '+';
            correctAnswer = num1 + num2;
        } else {
            operation = '-';
            correctAnswer = num1 - num2;
        }

        // ask the user for their answer
        printf("What is %d %c %d? ", num1, operation, num2);
        scanf("%d", &userAnswer);

        // check the answer and give feedback
        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer is %d.\n", correctAnswer);
        }

        // ask the user if they want to go again
        printf("Would you like to try again? (y/n) ");
        scanf(" %c", &redo); // space before %c to remove newline character
    }

    return 0;
}