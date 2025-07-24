//FormAI DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char options[4][50];
    int correctAns;
};

int main() {
    // Array of Questions
    struct Question questions[5];

    // Question 1
    strcpy(questions[0].question, "What is the output of 2+3?");
    strcpy(questions[0].options[0], "4");
    strcpy(questions[0].options[1], "5");
    strcpy(questions[0].options[2], "6");
    strcpy(questions[0].options[3], "7");
    questions[0].correctAns = 1;

    // Question 2
    strcpy(questions[1].question, "What is the keyword used for declaring a constant in C?");
    strcpy(questions[1].options[0], "var");
    strcpy(questions[1].options[1], "let");
    strcpy(questions[1].options[2], "const");
    strcpy(questions[1].options[3], "final");
    questions[1].correctAns = 3;

    // Question 3
    strcpy(questions[2].question, "What is the size of int data type in C?");
    strcpy(questions[2].options[0], "2 bytes");
    strcpy(questions[2].options[1], "4 bytes");
    strcpy(questions[2].options[2], "8 bytes");
    strcpy(questions[2].options[3], "Depends on the compiler");
    questions[2].correctAns = 2;

    // Question 4
    strcpy(questions[3].question, "Which keyword is used to exit from a loop in C?");
    strcpy(questions[3].options[0], "stop");
    strcpy(questions[3].options[1], "quit");
    strcpy(questions[3].options[2], "break");
    strcpy(questions[3].options[3], "exit");
    questions[3].correctAns = 3;

    // Question 5
    strcpy(questions[4].question, "What is the output of the following code?\nint x = 10;\nint *ptr = &x;\nprintf(\"%d\", *ptr);");
    strcpy(questions[4].options[0], "10");
    strcpy(questions[4].options[1], "0");
    strcpy(questions[4].options[2], "Address of x");
    strcpy(questions[4].options[3], "Garbage value");
    questions[4].correctAns = 1;

    int score = 0;

    printf("Welcome to the Online Examination System for C Programming!\n");

    for (int i = 0; i < 5; i++) {
        // Display Question
        printf("\n%d. %s\n", i+1, questions[i].question);
        
        // Display Options
        for (int j = 0; j < 4; j++) {
            printf("%c) %s\n", 'a'+j, questions[i].options[j]);
        }

        // Get User Input
        printf("\nEnter your choice (a/b/c/d): ");
        char userAns;
        scanf(" %c", &userAns);

        // Check User Answer
        if (userAns == 'a' + questions[i].correctAns - 1) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect!\n");
        }
    }

    // Display Final Score
    printf("\nYour score is: %d/5", score);

    return 0;
}