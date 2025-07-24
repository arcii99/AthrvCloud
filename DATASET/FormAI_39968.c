//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare struct for questions
struct question {
    char text[100];
    char choices[4][50];
    int correct_choice;
};

int main() {
    // Initialize question bank
    struct question bank[10];
    strcpy(bank[0].text, "What is the capital of France?");
    strcpy(bank[0].choices[0], "A. Paris");
    strcpy(bank[0].choices[1], "B. London");
    strcpy(bank[0].choices[2], "C. Berlin");
    strcpy(bank[0].choices[3], "D. Madrid");
    bank[0].correct_choice = 0;

    // Add more questions to the bank
    // ...

    // Declare variables
    int score = 0;
    int response;
    char name[50];

    // Get user's name
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    // Ask each question and get user's response
    // Then check if response is correct
    for (int i = 0; i < 10; i++) {
        printf("\n%d. %s\n", i+1, bank[i].text);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", bank[i].choices[j]);
        }
        printf("Enter your response (A/B/C/D): ");
        scanf(" %c", &response);
        if (response == 'A' && bank[i].correct_choice == 0) {
            printf("Correct!\n");
            score++;
        } else if (response == 'B' && bank[i].correct_choice == 1) {
            printf("Correct!\n");
            score++;
        } else if (response == 'C' && bank[i].correct_choice == 2) {
            printf("Correct!\n");
            score++;
        } else if (response == 'D' && bank[i].correct_choice == 3) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect!\n");
        }
    }

    // Print user's score
    printf("\nCongratulations, %s! You scored %d out of 10.\n", name, score);

    return 0;
}