//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUESTION_AMOUNT 10 // Amount of questions the user has to answer

int main() {
    int score = 0; // Number of correct answers
    
    srand(time(NULL)); // Initialize random seed
    
    printf("Welcome to the Math Exercise Program!\n");
    printf("You will be asked %d questions.\n", QUESTION_AMOUNT);
    
    for (int i = 0; i < QUESTION_AMOUNT; i++) {
        int num1 = rand() % 11; // Generate a random number between 0 and 10
        int num2 = rand() % 11;
        int answer;
        
        printf("\nQuestion %d:\n", i+1);
        printf("What is %d + %d? ", num1, num2);
        scanf("%d", &answer);
        
        if (answer == num1 + num2) { // Check if answer is correct
            printf("Correct!");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.", num1 + num2);
        }
    }
    
    printf("\n\nYou answered %d out of %d questions correctly.\n", score, QUESTION_AMOUNT);
    
    return 0;
}