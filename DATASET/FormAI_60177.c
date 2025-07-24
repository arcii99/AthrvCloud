//FormAI DATASET v1.0 Category: Math exercise ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialize random seed using current time

    int num1 = rand() % 100; // generate a random number from 0-99
    int num2 = rand() % 100; // generate another random number from 0-99

    printf("What is the result of %d + %d? ", num1, num2);

    int userAnswer;
    scanf("%d", &userAnswer);

    int correctAnswer = num1 + num2;

    if (userAnswer == correctAnswer) {
        printf("Congratulations! You solved the equation like a true mathematical genius!\n");
    } else {
        printf("Sorry, but your answer is incorrect. The correct answer is %d.\n", correctAnswer);
    }

    return 0;
}