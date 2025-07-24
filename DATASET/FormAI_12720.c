//FormAI DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a question
typedef struct {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

int main() {
    // Define an array of questions
    Question questions[5];

    // Populate the questions array with sample questions
    strcpy(questions[0].question, "What is the capital of the United States?");
    strcpy(questions[0].options[0], "New York");
    strcpy(questions[0].options[1], "Los Angeles");
    strcpy(questions[0].options[2], "Washington D.C.");
    strcpy(questions[0].options[3], "Chicago");
    questions[0].correct_option = 2;

    strcpy(questions[1].question, "What is the largest country in the world?");
    strcpy(questions[1].options[0], "Russia");
    strcpy(questions[1].options[1], "China");
    strcpy(questions[1].options[2], "United States");
    strcpy(questions[1].options[3], "India");
    questions[1].correct_option = 0;

    strcpy(questions[2].question, "What is the smallest planet in our solar system?");
    strcpy(questions[2].options[0], "Mars");
    strcpy(questions[2].options[1], "Venus");
    strcpy(questions[2].options[2], "Mercury");
    strcpy(questions[2].options[3], "Jupiter");
    questions[2].correct_option = 2;

    strcpy(questions[3].question, "What is the largest ocean in the world?");
    strcpy(questions[3].options[0], "Atlantic Ocean");
    strcpy(questions[3].options[1], "Indian Ocean");
    strcpy(questions[3].options[2], "Pacific Ocean");
    strcpy(questions[3].options[3], "Arctic Ocean");
    questions[3].correct_option = 2;

    strcpy(questions[4].question, "What is the largest desert in the world?");
    strcpy(questions[4].options[0], "Sahara Desert");
    strcpy(questions[4].options[1], "Arabian Desert");
    strcpy(questions[4].options[2], "Gobi Desert");
    strcpy(questions[4].options[3], "Antarctica Desert");
    questions[4].correct_option = 0;

    int score = 0;

    printf("Welcome to the online examination system!\n");
    printf("You will be presented with 5 multiple choice questions.\n");
    printf("Please choose the correct option from the available choices (1-4).\n");

    // Loop through each question in the questions array
    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);

        // Loop through each option for the current question
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        // Ask the user to input their answer
        int user_answer;
        printf("Your answer (1-4): ");
        scanf("%d", &user_answer);

        // Check if the user's answer is correct
        if (user_answer-1 == questions[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", questions[i].correct_option+1);
        }
    }

    // Print the user's score
    printf("\nYour score is %d/5.\n", score);

    return 0;
}