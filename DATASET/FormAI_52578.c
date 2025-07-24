//FormAI DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Generate two random numbers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    // Display the two numbers to the user
    printf("What is %d + %d?\n", num1, num2);

    // Get the user's answer
    int userAnswer;
    scanf("%d", &userAnswer);

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Check if the user's answer is correct
    if (userAnswer == correctAnswer) {
        printf("Correct!");
    } else {
        // Give the user another chance
        printf("Incorrect. Please try again:\n");
        scanf("%d", &userAnswer);
        if (userAnswer == correctAnswer) {
            printf("Correct!");
        } else {
            // Display the correct answer
            printf("Incorrect. The correct answer is %d.", correctAnswer);
        }
    }

    return 0;
}