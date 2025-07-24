//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed random number generator with current time
    srand(time(NULL));

    // Generate two random numbers between 0 and 10
    int num1 = rand() % 10;
    int num2 = rand() % 10;

    // Create the math problem string
    char problem[50];
    sprintf(problem, "What is %d multiplied by %d?", num1, num2);

    // Print the problem
    printf("%s\n", problem);

    // Get the user's answer
    int userAnswer;
    scanf("%d", &userAnswer);

    // Calculate the correct answer
    int correctAnswer = num1 * num2;

    // Check if the user's answer is correct
    if (userAnswer == correctAnswer) {
        printf("Correct! You have earned 10 survival points.\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", correctAnswer);
    }

    return 0;
}