//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    /* Welcome message */
    printf("Welcome to the Math Exercise game! Get ready to test your math skills!\n");

    /* Generate two random numbers */
    int num1, num2;
    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    /* Create variables for answer and user input */
    int answer, user_input;

    do {
        /* Display Math question and prompt user for answer */
        printf("What is %d + %d? ", num1, num2);
        scanf("%d", &user_input);

        /* Calculate correct answer */
        answer = num1 + num2;

        /* Check if answer is correct */
        if (user_input == answer) {
            printf("Congratulations! You got it right!\n");
            printf("Next question:\n");

            /* Generate new random numbers */
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
        } else {
            printf("Sorry, that is incorrect. Please try again.\n");
        }
    } while (1);

    return 0;
}