//FormAI DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for maximum number of questions and answers
#define MAX_QUESTIONS 50
#define MAX_ANSWERS 4
#define MAX_QUESTION_LENGTH 100
#define MAX_CHOICE_LENGTH 50

// define struct for question
typedef struct {
    char question[MAX_QUESTION_LENGTH]; // store the question
    char choices[MAX_ANSWERS][MAX_CHOICE_LENGTH]; // store the choices
    int correctAnswer; // store the index of the correct answer
} Question;

// function to display menu and take user choice
int menu() {
    int choice;
    printf("***Welcome to Online Examination***\n");
    printf("1. Take the test\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to display a single question and take user answer
int askQuestion(Question *q) {
    int answer;
    printf("%s\n", q->question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i + 1, q->choices[i]);
    }
    printf("Enter your answer: ");
    scanf("%d", &answer);
    return answer;
}

// function to grade the test and display results
void gradeTest(Question *questions, int numQuestions) {
    int score = 0;
    printf("***Results***\n");
    for (int i = 0; i < numQuestions; i++) {
        int answer = askQuestion(&questions[i]);
        if (answer == questions[i].correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d\n", questions[i].correctAnswer);
        }
    }
    printf("***You scored %d out of %d***\n", score, numQuestions);
}

int main() {
    // define array to store questions
    Question questions[MAX_QUESTIONS];
    int numQuestions = 0;

    // add first question
    Question q;
    strcpy(q.question, "What is the capital of France?");
    strcpy(q.choices[0], "Paris");
    strcpy(q.choices[1], "London");
    strcpy(q.choices[2], "Berlin");
    strcpy(q.choices[3], "Madrid");
    q.correctAnswer = 1;
    questions[numQuestions++] = q;

    // add second question
    strcpy(q.question, "What is the highest mountain in the world?");
    strcpy(q.choices[0], "Mount Everest");
    strcpy(q.choices[1], "K2");
    strcpy(q.choices[2], "Matterhorn");
    strcpy(q.choices[3], "Denali");
    q.correctAnswer = 0;
    questions[numQuestions++] = q;

    // add third question
    strcpy(q.question, "What is the largest ocean in the world?");
    strcpy(q.choices[0], "Atlantic Ocean");
    strcpy(q.choices[1], "Indian Ocean");
    strcpy(q.choices[2], "Southern Ocean");
    strcpy(q.choices[3], "Pacific Ocean");
    q.correctAnswer = 3;
    questions[numQuestions++] = q;

    // display menu and handle user choice
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                gradeTest(questions, numQuestions);
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);
    
    return 0;    
}