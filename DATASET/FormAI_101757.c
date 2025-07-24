//FormAI DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum length of the answer
#define MAX_ANSWER_LENGTH 50

// Declare the structure of a question
typedef struct {
    char prompt[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Declare the structure of a user's answer
typedef struct {
    char answer[MAX_ANSWER_LENGTH];
} UserAnswer;

// Declare the function to display a question and get the user's answer
void displayQuestion(Question* question, UserAnswer* userAnswer);

int main() {
    // Declare an array of questions
    Question questions[NUM_QUESTIONS];

    // Initialize the questions array
    strcpy(questions[0].prompt, "What is the capital of France?");
    strcpy(questions[0].answer, "Paris");

    strcpy(questions[1].prompt, "What is the largest country in the world?");
    strcpy(questions[1].answer, "Russia");

    // ... and so on for the other questions ...

    // Declare an array of user's answers
    UserAnswer userAnswers[NUM_QUESTIONS];

    // Display each question and get the user's answer
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        displayQuestion(&questions[i], &userAnswers[i]);
        printf("\n");
    }

    // Grade the exam and display the results
    printf("********** Results **********\n");
    int numCorrect = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].answer, userAnswers[i].answer) == 0) {
            printf("Question %d: Correct\n", i+1);
            numCorrect++;
        } else {
            printf("Question %d: Incorrect\n", i+1);
        }
    }
    printf("*****************************\n");
    printf("You got %d out of %d questions correct.\n", numCorrect, NUM_QUESTIONS);

    return 0;
}

void displayQuestion(Question* question, UserAnswer* userAnswer) {
    printf("%s\n", question->prompt);
    printf("Answer: ");
    fgets(userAnswer->answer, MAX_ANSWER_LENGTH, stdin);
    // Remove the newline character from the end of the input
    userAnswer->answer[strcspn(userAnswer->answer, "\n")] = 0;
}