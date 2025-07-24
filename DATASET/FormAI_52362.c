//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two random numbers between 1 and 20
    int num1 = rand() % 20 + 1;
    int num2 = rand() % 20 + 1;

    // Print the calculation prompt
    printf("Calculate %d + %d\n", num1, num2);

    // Read in user's input
    int userAnswer;
    scanf("%d", &userAnswer);

    // Calculate the correct answer
    int correctAnswer = num1 + num2;

    // Check user's answer and output result
    if (userAnswer == correctAnswer) {
        printf("Correct!\n");
    } else {
        printf("Wrong.\n");
        printf("The correct answer is %d\n", correctAnswer);
    }

    return 0;
}