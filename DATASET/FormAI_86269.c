//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, userAnswer, correct = 0;
    char operator;

    printf("Welcome to the Math Challenge!\n");
    printf("In this game, you will be given a set of math problems to solve.\n");
    printf("Let's begin!\n\n");

    srand(time(0)); // set random number seed

    for (int i = 0; i < 10; i++) {
        num1 = rand() % 10 + 1; // generate random number 1-10
        num2 = rand() % 10 + 1; // generate random number 1-10
        operator = (rand() % 2 == 0) ? '+' : '-'; // randomly select between addition and subtraction

        printf("Problem %d: what is %d %c %d?\n", i+1, num1, operator, num2);
        answer = (operator == '+') ? num1 + num2 : num1 - num2; // calculate answer

        scanf("%d", &userAnswer); // get user's answer

        if (userAnswer == answer) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect! The correct answer is %d.\n", answer);
        }
    }

    printf("\nCongratulations! You've completed the Math Challenge.\n");
    printf("You got %d out of 10 questions correct.\n", correct);

    return 0;
}