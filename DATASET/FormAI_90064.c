//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome message
    printf("Welcome to the Math Exercise program!\n");
    printf("You will be asked 10 addition questions. Let's get started!\n");

    // Seed the random number generator
    srand(time(NULL));

    // Keep track of the score
    int score = 0;

    // Loop through 10 questions
    for (int i = 1; i <= 10; i++) {
        
        // Generate two random numbers between 1 and 10
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;

        // Ask the question
        printf("Question %d: What is %d + %d?\n", i, num1, num2);
        
        // Get the user's answer
        int answer;
        scanf("%d", &answer);
        
        // Check if the answer is correct
        if (answer == num1 + num2) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 + num2);
        }
    }

    // Display the final score
    printf("Your score is %d out of 10. Well done!\n", score);

    return 0;
}