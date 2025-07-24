//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4

// Struct for each question
typedef struct {
    int id;
    char prompt[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
} Question;

// Struct for the entire exam
typedef struct {
    char title[50];
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

// Function to display the exam title and all questions
void display_exam(Exam exam) {
    printf("Title: %s\n\n", exam.title);
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Question %d: %s\n", i+1, exam.questions[i].prompt);
        printf("Options:\n");
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", j+65, exam.questions[i].options[j]);
        }
        printf("\n");
    }
}

// Function to grade the exam and display the score
void grade_exam(Exam exam, int student_answers[]) {
    int score = 0;
    for (int i = 0; i < exam.num_questions; i++) {
        if (student_answers[i] == exam.questions[i].correct_option) {
            score++;
        }
    }
    printf("You scored %d out of %d.\n", score, exam.num_questions);
}

int main() {
    // Create exam object
    Exam exam;
    strcpy(exam.title, "C Programming Exam");

    // Add questions to exam object
    exam.num_questions = 3;

    Question q1;
    q1.id = 1;
    strcpy(q1.prompt, "What is the output of 'printf(\"%d\", sizeof(long int))'?");

    strcpy(q1.options[0], "4");
    strcpy(q1.options[1], "8");
    strcpy(q1.options[2], "16");
    strcpy(q1.options[3], "32");

    q1.correct_option = 1;

    exam.questions[0] = q1;


    Question q2;
    q2.id = 2;
    strcpy(q2.prompt, "What is the value of 'x' after the following code is executed? \n int x = 10; \n x++;");

    strcpy(q2.options[0], "9");
    strcpy(q2.options[1], "10");
    strcpy(q2.options[2], "11");
    strcpy(q2.options[3], "12");

    q2.correct_option = 2;

    exam.questions[1] = q2;

    Question q3;
    q3.id = 3;
    strcpy(q3.prompt, "What is the value of 'y' after the following code is executed? \n int y = 5; \n y*=3;");

    strcpy(q3.options[0], "15");
    strcpy(q3.options[1], "8");
    strcpy(q3.options[2], "24");
    strcpy(q3.options[3], "2");

    q3.correct_option = 0;

    exam.questions[2] = q3;

    // Display exam questions
    display_exam(exam);

    // Get user answers
    int student_answers[exam.num_questions];
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Enter your answer for question %d: ", i+1);
        char answer[10];
        scanf("%s", answer);
        student_answers[i] = answer[0] - 65;
    }

    // Grade the exam and display score
    grade_exam(exam, student_answers);

    return 0;
}