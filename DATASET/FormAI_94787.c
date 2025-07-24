//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and the maximum number of characters per question/answer
#define MAX_QUESTIONS 10
#define MAX_CHARS 50

// Declare the Question struct which contains the question and its answers
typedef struct {
    char question[MAX_CHARS];
    char choices[4][MAX_CHARS];
    char correctAnswer[MAX_CHARS];
} Question;

// Declare the Exam struct which contains the exam questions and answers
typedef struct {
    Question questions[MAX_QUESTIONS];
    int numQuestions;
} Exam;

// Function to print questions with its choices
void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i, q.choices[i]);
    }
}

// Function to create new question
Question createQuestion() {
    Question q;
    printf("Enter question: ");
    fgets(q.question, MAX_CHARS, stdin);
    printf("Enter choice A: ");
    fgets(q.choices[0], MAX_CHARS, stdin);
    printf("Enter choice B: ");
    fgets(q.choices[1], MAX_CHARS, stdin);
    printf("Enter choice C: ");
    fgets(q.choices[2], MAX_CHARS, stdin);
    printf("Enter choice D: ");
    fgets(q.choices[3], MAX_CHARS, stdin);
    printf("Enter correct choice (A, B, C, D): ");
    fgets(q.correctAnswer, MAX_CHARS, stdin);
    return q;
}

// Function to add a question to the exam
void addQuestionToExam(Exam *e, Question q) {
    if (e->numQuestions < MAX_QUESTIONS) {
        e->questions[e->numQuestions++] = q;
    } else {
        printf("Exam is already at maximum capacity.\n");
    }
}

// Function to display the exam
void displayExam(Exam e) {
    printf("Exam Questions:\n");
    for (int i = 0; i < e.numQuestions; i++) {
        displayQuestion(e.questions[i]);
    }
}

// Function to grade the exam
void gradeExam(Exam e) {
    char userAnswer[MAX_CHARS];
    int correctAnswers = 0;
    printf("Answer the following questions:\n");
    for (int i = 0; i < e.numQuestions; i++) {
        displayQuestion(e.questions[i]);
        printf("Enter your answer: ");
        fgets(userAnswer, MAX_CHARS, stdin);
        if (strcmp(userAnswer, e.questions[i].correctAnswer) == 0) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. Answer is %s\n", e.questions[i].correctAnswer);
        }
    }
    printf("Final score: %d / %d\n", correctAnswers, e.numQuestions);
}

// Main function
int main() {
    Exam e;
    char userCmd[MAX_CHARS];
    e.numQuestions = 0;
    do {
        printf("Enter command (add, display, grade, quit): ");
        fgets(userCmd, MAX_CHARS, stdin);
        if (strcmp(userCmd, "add\n") == 0) {
            Question q = createQuestion();
            addQuestionToExam(&e, q);
        } else if (strcmp(userCmd, "display\n") == 0) {
            displayExam(e);
        } else if (strcmp(userCmd, "grade\n") == 0) {
            gradeExam(e);
        }
    } while (strcmp(userCmd, "quit\n") != 0);

    return 0;
}