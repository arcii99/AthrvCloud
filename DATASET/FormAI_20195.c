//FormAI DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for array sizes
#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 20
#define MAX_NAME_LENGTH 50

// Define struct for questions
typedef struct {
    int question_number;
    char question_text[MAX_ANSWER_LENGTH];
    char correct_answer[MAX_ANSWER_LENGTH];
    int points;
} question;

// Define struct for student results
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} result;

// Declare array of questions and results
question exam_questions[MAX_QUESTIONS];
result exam_results[MAX_QUESTIONS];

// Declare function to print exam questions
void print_exam_questions() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", exam_questions[i].question_number, exam_questions[i].question_text);
    }
}

// Declare function to grade exam
void grade_exam() {
    // Prompt for student name
    char name[MAX_NAME_LENGTH];
    printf("Please enter your name: ");
    scanf("%[^\n]%*c", name);
    
    // Declare variables for grading
    int total_score = 0;
    int num_correct = 0;
    
    // Loop through each question
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        // Prompt for answer
        printf("Question %d: %s\n", exam_questions[i].question_number, exam_questions[i].question_text);
        printf("Enter your answer: ");
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        
        // Check if answer is correct
        if (strcmp(answer, exam_questions[i].correct_answer) == 0) {
            printf("Correct!\n");
            total_score += exam_questions[i].points;
            num_correct++;
        } else {
            printf("Incorrect.\n");
        }
    }
    
    // Save student results
    strcpy(exam_results[num_correct].name, name);
    exam_results[num_correct].score = total_score;
    
    // Display results
    printf("You answered %d questions correctly for a total score of %d.\n", num_correct, total_score);
}

int main() {
    // Initialize exam questions
    memset(exam_questions, 0, sizeof(exam_questions));
    exam_questions[0].question_number = 1;
    strcpy(exam_questions[0].question_text, "What is the capital of France?");
    strcpy(exam_questions[0].correct_answer, "Paris");
    exam_questions[0].points = 1;
    
    exam_questions[1].question_number = 2;
    strcpy(exam_questions[1].question_text, "What is the largest continent?");
    strcpy(exam_questions[1].correct_answer, "Asia");
    exam_questions[1].points = 1;
    
    exam_questions[2].question_number = 3;
    strcpy(exam_questions[2].question_text, "What color is the sky?");
    strcpy(exam_questions[2].correct_answer, "Blue");
    exam_questions[2].points = 1;
    
    exam_questions[3].question_number = 4;
    strcpy(exam_questions[3].question_text, "What is the square root of 64?");
    strcpy(exam_questions[3].correct_answer, "8");
    exam_questions[3].points = 1;
    
    exam_questions[4].question_number = 5;
    strcpy(exam_questions[4].question_text, "What is 2 + 2?");
    strcpy(exam_questions[4].correct_answer, "4");
    exam_questions[4].points = 1;
    
    // Print exam questions
    print_exam_questions();
    
    // Grade exam
    grade_exam();
    
    return 0;
}