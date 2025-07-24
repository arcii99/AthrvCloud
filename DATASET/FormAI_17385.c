//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_ANSWER_LENGTH 50
#define MAX_NAME_LENGTH 50

typedef struct question {
    int question_number;
    char question_text[MAX_ANSWER_LENGTH];
    char correct_answer[MAX_ANSWER_LENGTH];
} question;

typedef struct exam {
    char exam_name[MAX_NAME_LENGTH];
    int total_questions;
    question questions[MAX_QUESTIONS];
} exam;

void display_question(question q) {
    printf("Question %d: %s \n", q.question_number, q.question_text);
}

void display_exam(exam e) {
    printf("Exam Name: %s \n", e.exam_name);
    printf("Total Questions: %d \n", e.total_questions);
    for(int i=0; i<e.total_questions; i++) {
        display_question(e.questions[i]);
    }
}

int main() {
    exam e;
    strcpy(e.exam_name, "C Programming Exam");
    e.total_questions = 2;

    question q1;
    q1.question_number = 1;
    strcpy(q1.question_text, "What is the result of 1+2");
    strcpy(q1.correct_answer, "3");

    question q2;
    q2.question_number = 2;
    strcpy(q2.question_text, "What is the keyword used to declare a constant in C");
    strcpy(q2.correct_answer, "const");

    e.questions[0] = q1;
    e.questions[1] = q2;

    display_exam(e);

    return 0;
}