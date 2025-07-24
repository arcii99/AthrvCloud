//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int answer = num1 + num2;

    printf("Welcome to the Addition Game!\n");
    printf("You will be given two numbers, please add them together and enter your answer.\n");
    printf("You have 3 attempts to get the correct answer, good luck!\n\n");
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n\n", num2);

    int guess, attempts = 0;
    while (attempts < 3) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &guess);
        if (guess == answer) {
            printf("\nCongratulations! You got the correct answer in %d attempt(s).\n", attempts + 1);
            break;
        } else {
            printf("Incorrect answer, please try again.\n\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("\nSorry, you have used all your attempts. The correct answer is %d.\n", answer);
    }

    return 0;
}