//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void displayMenu();
void takeExam();
void showResults();

// global variables
int correctAnswers = 0;
int totalQuestions = 0;

// main function
int main() {

    // welcome message
    printf("Welcome to the Online Exam System!\n");

    // loop through the menu until user chooses to exit
    while (1) {

        // display the main menu
        displayMenu();

        // get user input
        char choice[10];
        printf("Enter your choice: ");
        scanf("%s", choice);

        // execute user's choice
        if (strcmp(choice, "1") == 0) {
            takeExam();
        }
        else if (strcmp(choice, "2") == 0) {
            showResults();
        }
        else if (strcmp(choice, "3") == 0) {
            printf("Exiting Online Exam System...\n");
            exit(0);
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// function to display the main menu
void displayMenu() {
    printf("\nMain Menu:\n");
    printf("1. Take Exam\n");
    printf("2. Show Results\n");
    printf("3. Exit\n");
}

// function to take the exam
void takeExam() {

    // clear the total questions and correct answers
    totalQuestions = 0;
    correctAnswers = 0;

    // ask user for the number of questions
    printf("\nEnter the number of questions in the exam: ");
    scanf("%d", &totalQuestions);

    // loop through each question
    for (int i = 1; i <= totalQuestions; i++) {

        char answer[5];

        // ask the question
        printf("\nQuestion %d: What is 2 + 2?\n", i);
        printf("a. 3\n");
        printf("b. 4\n");
        printf("c. 5\n");
        printf("d. 6\n");

        // get user's answer
        printf("Enter your answer: ");
        scanf("%s", answer);

        // check if the answer is correct
        if (strcmp(answer, "b") == 0) {
            printf("Correct!\n");
            correctAnswers++;
        }
        else {
            printf("Incorrect!\n");
        }
    }

    // show the user's score
    printf("\nYou answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);
}

// function to show the user's results
void showResults() {
    printf("\nYour total correct answers: %d\n", correctAnswers);
    printf("Your total questions attempted: %d\n", totalQuestions);
}