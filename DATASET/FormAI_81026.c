//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int answer;
    int attempts = 0;

    printf("Welcome to Retro Math!\n");
    printf("Can you solve this problem?\n");
    printf("%d + %d = ?\n", num1, num2);

    while(attempts < 3) {
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if(answer == num1 + num2) {
            printf("Correct! You are a mathematical genius!\n");
            return 0;
        } else {
            printf("Incorrect answer, try again!\n");
            attempts++;
        }
    }

    printf("Sorry, you have used all 3 attempts. Better luck next time!\n");

    return 0;
}