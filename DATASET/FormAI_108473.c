//FormAI DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate two random numbers
    srand(time(NULL));
    int num1 = rand() % 100;
    int num2 = rand() % 100;

    // Determine operation
    int operation = rand() % 3; // 0 = addition, 1 = subtraction, 2 = multiplication
    char symbol;
    int answer;
    switch (operation) {
        case 0:
            symbol = '+';
            answer = num1 + num2;
            break;
        case 1:
            symbol = '-';
            answer = num1 - num2;
            break;
        case 2:
            symbol = '*';
            answer = num1 * num2;
            break;
    }

    // Present problem
    printf("What is %d %c %d?\n", num1, symbol, num2);

    // Collect user's answer
    int userAnswer;
    scanf("%d", &userAnswer);

    // Validate answer
    if (userAnswer == answer) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct answer was %d.\n", answer);
    }

    return 0;
}