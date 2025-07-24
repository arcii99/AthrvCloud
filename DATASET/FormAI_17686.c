//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, userAnswer;
    int numQuestions, numCorrect = 0;
    srand(time(NULL)); // Seed for random numbers

    printf("Welcome to the peaceful Math exercise program!\n");
    printf("How many questions would you like to answer today? ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        // Generate two random numbers between 1 and 20
        num1 = rand() % 20 + 1;
        num2 = rand() % 20 + 1;

        printf("\nQuestion %d:\n", i+1);
        printf("%d + %d = ", num1, num2);
        scanf("%d", &userAnswer);

        answer = num1 + num2;

        if (userAnswer == answer) {
            numCorrect++;
            printf("Correct! :) ");
        } else {
            printf("Incorrect! :( ");
        }

        printf("The answer is %d.\n", answer);
    }

    printf("\nYou answered %d out of %d questions correctly!\n", numCorrect, numQuestions);
    return 0;
}