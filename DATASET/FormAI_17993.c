//FormAI DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int question_numbers = 10;
    char questions[question_numbers][255];
    char answers[question_numbers][5];
    char student_answers[question_numbers][5];
    int i, j;
    int correct_answers = 0;
    int incorrect_answers = 0;

    // Populate questions and answers
    strcpy(questions[0], "What is the capital of France?");
    strcpy(answers[0], "b");
    strcpy(questions[1], "What is the largest ocean?");
    strcpy(answers[1], "a");
    strcpy(questions[2], "What is the smallest country in the world?");
    strcpy(answers[2], "c");
    strcpy(questions[3], "What is the highest peak in the world?");
    strcpy(answers[3], "d");
    strcpy(questions[4], "What is the currency of Japan?");
    strcpy(answers[4], "a");
    strcpy(questions[5], "What is the chemical symbol for gold?");
    strcpy(answers[5], "c");
    strcpy(questions[6], "What is the freezing point of water?");
    strcpy(answers[6], "b");
    strcpy(questions[7], "What is the largest continent?");
    strcpy(answers[7], "a");
    strcpy(questions[8], "What is the longest river in the world?");
    strcpy(answers[8], "b");
    strcpy(questions[9], "What is the coldest continent?");
    strcpy(answers[9], "d");
    
    // Display instructions
    printf("Welcome to the C Online Examination System!\n");
    printf("You will be presented with %d multiple-choice questions.\n", question_numbers);
    printf("Please select the letter corresponding to your chosen answer and press enter.\n");

    // Display questions
    for (i = 0; i < question_numbers; i++) {
        printf("\nQ%d: %s\n", i+1, questions[i]);
        printf("a) Option A\n");
        printf("b) Option B\n");
        printf("c) Option C\n");
        printf("d) Option D\n");

        // Get student answers
        printf("Your answer: ");
        scanf("%s", &student_answers[i]);   
    }

    // Check answers
    for (i = 0; i < question_numbers; i++) {
        if (strcmp(student_answers[i], answers[i]) == 0) {
            correct_answers++;
        } else {
            incorrect_answers++;
        }
    }

    // Display results
    printf("\n\nRESULTS:\n");
    printf("Number of correct answers: %d\n", correct_answers);
    printf("Number of incorrect answers: %d\n", incorrect_answers);

    if (correct_answers >= 5) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("We're sorry, but you did not pass the exam. Please try again.\n");
    }

    return 0;
}