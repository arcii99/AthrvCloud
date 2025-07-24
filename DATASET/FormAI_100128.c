//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num1, num2, answer, userAnswer, correctCount = 0, wrongCount = 0;

int main() {

    printf("Welcome to the Quick Math Practice Program!\n");

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        printf("\nWhat is %d + %d ?\n", num1, num2);
        scanf("%d", &userAnswer);
        answer = num1 + num2;

        if (answer == userAnswer) {
            printf("Correct Answer!\n");
            correctCount++;
        } else {
            printf("Wrong Answer!\n");
            wrongCount++;
        }
    }

    printf("\nYou have answered %d questions correctly and %d questions incorrectly.\n", correctCount, wrongCount);
    printf("Thanks for using Quick Math Practice Program!\n");

    return 0;
}