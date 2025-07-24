//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define the maximum number of questions that can be stored in the system */
#define MAX_QUESTIONS 50

/* Struct to store a single question */
struct Question {
    char text[100]; /* The question text */
    char options[4][50]; /* An array to store up to 4 options */
    int correct_answer; /* The index of the correct option */
};

/* Function to display the menu */
void show_menu() {
    printf("\n\n");
    printf("----- ONLINE EXAMINATION SYSTEM -----\n");
    printf("1. Add a question\n");
    printf("2. Take the exam\n");
    printf("3. Exit\n");
    printf("\n");
}

/* Function to add a question to the system */
void add_question(struct Question questions[], int *num_questions) {
    char input[50];
    struct Question new_question;
    
    /* Ask for the question text */
    printf("Enter the question:\n");
    fgets(new_question.text, 100, stdin);
    new_question.text[strlen(new_question.text) - 1] = '\0'; /* Remove the newline character */
    
    /* Ask for the options */
    printf("Enter option 1:\n");
    fgets(new_question.options[0], 50, stdin);
    new_question.options[0][strlen(new_question.options[0]) - 1] = '\0';
    
    printf("Enter option 2:\n");
    fgets(new_question.options[1], 50, stdin);
    new_question.options[1][strlen(new_question.options[1]) - 1] = '\0';
    
    printf("Enter option 3 (or type 'N/A' if there are only 2 options):\n");
    fgets(new_question.options[2], 50, stdin);
    new_question.options[2][strlen(new_question.options[2]) - 1] = '\0';
    
    printf("Enter option 4 (or type 'N/A' if there are only 3 options):\n");
    fgets(new_question.options[3], 50, stdin);
    new_question.options[3][strlen(new_question.options[3]) - 1] = '\0';
    
    /* Ask for the correct answer */
    printf("Enter the index of the correct answer (1-4):\n");
    fgets(input, 50, stdin);
    new_question.correct_answer = atoi(input) - 1; /* Subtract 1 to convert from 1-based index to 0-based index */
    
    /* Add the new question to the array */
    questions[*num_questions] = new_question;
    (*num_questions)++;
    
    printf("Question added successfully!\n");
}

/* Function to take the exam */
void take_exam(struct Question questions[], int num_questions) {
    int i, j, num_correct = 0;
    char input[50];
    
    /* Loop through each question */
    for (i = 0; i < num_questions; i++) {
        /* Display the question text and options */
        printf("\nQuestion %d:\n", i + 1);
        printf("%s\n", questions[i].text);
        for (j = 0; j < 4 && strcmp(questions[i].options[j], "N/A") != 0; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        
        /* Ask for the user's answer */
        printf("Enter your answer (1-4):\n");
        fgets(input, 50, stdin);
        int user_answer = atoi(input) - 1; /* Subtract 1 to convert from 1-based index to 0-based index */
        printf("\n");
        
        /* Check if the answer is correct */
        if (user_answer == questions[i].correct_answer) {
            printf("Correct!\n\n");
            num_correct++;
        } else {
            printf("Sorry, that's incorrect.\n\n");
        }
    }
    
    /* Display the user's score */
    printf("\nYou scored %d out of %d.\n", num_correct, num_questions);
}

int main() {
    struct Question questions[MAX_QUESTIONS]; /* Array to store the questions */
    int num_questions = 0; /* Number of questions currently stored in the system */
    char input[50];
    int option;
    
    /* Display the menu until the user chooses to exit */
    do {
        show_menu();
        fgets(input, 50, stdin);
        option = atoi(input);
        printf("\n");
        
        switch (option) {
            case 1:
                add_question(questions, &num_questions);
                break;
            case 2:
                if (num_questions == 0) {
                    printf("No questions found in the system. Please add some questions first.\n");
                } else {
                    take_exam(questions, num_questions);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);
    
    return 0;
}