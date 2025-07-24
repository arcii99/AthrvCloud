//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    int answer, userAnswer;

    printf("Welcome to the wacky world of math!\n\n");
    printf("What is %d + %d? ", num1, num2);
    scanf("%d", &userAnswer);

    answer = num1 + num2;

    if (userAnswer == answer) {
        printf("\nYou're totally rad!\n\n");
    } else {
         printf("\nYou're about as useful as a calculator with no batteries.\n");
         printf("The correct answer is %d\n\n", answer);
    }

    return 0;
}