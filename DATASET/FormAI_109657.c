//FormAI DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Declare variables
int num_questions = 3;
int num_choices = 4;
char answer_key[] = {'A', 'B', 'C'};

int main() {
    // Display welcome message
    printf("Welcome to the online exam!\n");
    printf("Please answer all questions by typing the letter of the correct choice.\n");

    // Loop through questions
    for (int i = 0; i < num_questions; i++) {
        // Display question and choices
        printf("\nQuestion %d:\n", i+1);
        printf("What is the meaning of life?\n");
        printf("A. 42\n");
        printf("B. Love\n");
        printf("C. Pizza\n");
        printf("D. Sleep\n");

        // Prompt user for answer and check if it's correct
        char user_answer;
        printf("Enter your answer: ");
        scanf(" %c", &user_answer);
        if (user_answer == answer_key[i]) {
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is %c.\n", answer_key[i]);
        }
    }

    // Display final score
    printf("\nYou have completed the exam!\n");
    printf("Your score is %d out of %d.\n", num_questions, num_questions);

    return 0;
}