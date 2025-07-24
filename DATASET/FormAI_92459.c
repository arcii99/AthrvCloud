//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10  // Maximum number of questions
#define MAX_OPTIONS 4     // Maximum number of options per question

// Structure for storing a question
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
} Question;

// Function to display the menu
void display_menu() {
    printf("Online Examination System\n");
    printf("-------------------------\n\n");
    printf("1. Start Exam\n");
    printf("2. View Score\n");
    printf("3. Exit\n\n");
}

// Function to start the exam
void start_exam(Question questions[], int num_questions) {
    int score = 0;
    int answer_given;
    
    printf("Start Exam\n");
    printf("-----------\n\n");

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d\n\n", i+1);
        printf("%s\n", questions[i].question);
        
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }
        
        printf("Enter your answer: ");
        scanf("%d", &answer_given);
        
        if (answer_given == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect!\n");
        }
        
        printf("\n");
    }
    
    printf("Your final score is %d/%d\n\n", score, num_questions);
}

// Function to view the score
void view_score() {
    printf("View Score\n");
    printf("----------\n\n");
    printf("This feature is not implemented yet!\n\n");
}

int main() {
    Question questions[MAX_QUESTIONS];
    int choice = 0;
    int num_questions = 0;

    // Initialize the questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "Paris");
    strcpy(questions[0].options[1], "Berlin");
    strcpy(questions[0].options[2], "London");
    strcpy(questions[0].options[3], "Madrid");
    questions[0].answer = 1;
    
    strcpy(questions[1].question, "What is the largest planet in our solar system?");
    strcpy(questions[1].options[0], "Jupiter");
    strcpy(questions[1].options[1], "Saturn");
    strcpy(questions[1].options[2], "Mars");
    strcpy(questions[1].options[3], "Venus");
    questions[1].answer = 1;
    
    num_questions = 2;
    
    // Loop to display the menu and take input
    while (choice != 3) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                start_exam(questions, num_questions);
                break;
            case 2:
                view_score();
                break;
            case 3:
                printf("Thank you for using the Online Examination System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}