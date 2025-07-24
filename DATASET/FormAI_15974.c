//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up random number generator
    srand(time(NULL));

    // Generate two random numbers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    // Output the two numbers to the user
    printf("What is the result of %d + %d?\n", num1, num2);

    // Get user input
    int userAnswer;
    scanf("%d", &userAnswer);

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Check user's answer
    if (userAnswer == correctAnswer) {
        printf("Congratulations! That's correct.\n");
    } else {
        printf("Sorry, that's incorrect. The correct answer is %d.\n", correctAnswer);
    }

    return 0;
}