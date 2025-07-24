//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));

    int num1 = rand() % 50 + 1;
    int num2 = rand() % 50 + 1;

    printf("Welcome to the Math Exercise game!\n");
    printf("Your first number is %d.\n", num1);
    printf("Your second number is %d.\n", num2);
    printf("What is the result of %d multiplied by %d?\n", num1, num2);

    int user_answer;
    scanf("%d", &user_answer);

    int correct_answer = num1 * num2;

    if (user_answer == correct_answer) {
        printf("Correct! Great job!\n");
    } else {
        printf("Sorry, that is incorrect. The correct answer is %d.\n", correct_answer);
    }

    printf("Let's try another one!\n");

    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;

    printf("Your first number is %d.\n", num1);
    printf("Your second number is %d.\n", num2);
    printf("What is the result of %d to the power of %d?\n", num1, num2);

    scanf("%d", &user_answer);

    correct_answer = pow(num1, num2);

    if (user_answer == correct_answer) {
        printf("Correct! Way to go!\n");
    } else {
        printf("Sorry, that is incorrect. The correct answer is %d.\n", correct_answer);
    }

    printf("Thanks for playing Math Exercise. Have a great day!\n");

    return 0;
}