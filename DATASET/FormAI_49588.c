//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, user_answer;
    int score = 0;
    char choice;

    printf("Hello there! Let's practice some Math!\n");
    printf("Are you ready? (Y/N) ");
    scanf("%c", &choice);

    while(choice == 'Y' || choice == 'y') {
        printf("\nGreat! Here is your first question:\n");

        // Generate random numbers
        srand(time(NULL));
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Display the question
        printf("What is %d + %d?\n", num1, num2);

        // Calculate the answer
        answer = num1 + num2;

        // Get user's answer
        printf("Your answer: ");
        scanf("%d", &user_answer);

        // Check if answer is correct
        if(user_answer == answer) {
            printf("You got it! Good job!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        // Give user the option to continue or quit
        printf("Do you want to continue? (Y/N) ");
        scanf(" %c", &choice);
    }

    printf("\nThanks for playing! Your final score is %d.\n", score);

    return 0;
}