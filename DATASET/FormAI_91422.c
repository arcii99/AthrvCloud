//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate two random numbers
    srand(time(NULL));
    int num1 = rand() % 50 + 1;
    int num2 = rand() % 50 + 1;

    // Print the math problem for the user to solve
    printf("What is %d + %d?\n", num1, num2);

    // Get the user's answer
    int userAnswer;
    scanf("%d", &userAnswer);

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Check if the user's answer is correct
    if (userAnswer == correctAnswer) {
        printf("Well done! That's correct!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", correctAnswer);
    }

    return 0;
}