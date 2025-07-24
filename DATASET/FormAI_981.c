//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
// C Online Examination System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Online Examination!\n");
    int score = 0; // initialize score to zero
    
    // Ask the user for their name
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Good luck, %s!\n", name);
    
    // Generate 5 random math questions
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < 5; i++) {
        int num1 = rand() % 10 + 1; // generate a random number between 1 and 10
        int num2 = rand() % 10 + 1;
        int answer = num1 + num2;
        
        // Ask the user the question
        int userAnswer;
        printf("What is %d + %d? ", num1, num2);
        scanf("%d", &userAnswer);
        
        // Check if the user's answer is correct
        if (userAnswer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %d.\n", answer);
        }
    }

    // Print the final score
    printf("You scored %d out of 5.\n", score);
    
    return 0;
}