//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int num1 = rand() % 10; // generate random number between 0 and 9
    int num2 = rand() % 10;
    int result;

    printf("Welcome to the Math Exercise Program!\n");
    printf("Let's practice addition and multiplication!\n\n");

    printf("Question 1:\n");
    printf("What is %d + %d?\n", num1, num2);
    scanf("%d", &result);
    if (result == (num1 + num2)) {
        printf("Correct! Good job!\n");
    } else {
        printf("Incorrect. The correct answer is %d\n", num1 + num2);
    }

    printf("\nQuestion 2:\n");
    printf("What is %d * %d?\n", num1, num2);
    scanf("%d", &result);
    if (result == (num1 * num2)) {
        printf("Correct! You're doing great!\n");
    } else {
        printf("Incorrect. The correct answer is %d\n", num1 * num2);
    }

    printf("\nQuestion 3:\n");
    printf("Let's switch it up. What is %d * %d + %d?\n", num1, num2, num1);
    scanf("%d", &result);
    if (result == (num1 * num2 + num1)) {
        printf("Awesome! You're a Math Genius!\n");
    } else {
        printf("Sorry, the correct answer is %d\n", num1 * num2 + num1);
    }

    printf("\nThank you for practicing with us. Come back anytime!\n");

    return 0;
}