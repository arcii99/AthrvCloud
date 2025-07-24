//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int numOfQuestions = 5; // Number of questions in the exam
int numOfStudents = 3; // Number of students taking the exam
int correctAnswers[] = {1, 2, 3, 4, 5}; // Correct answers for the questions

// Struct for the questions
typedef struct Question {
    char content[100];
    char options[4][50];
    int answer;
} Question;

// Struct for the student's answer sheet
typedef struct AnswerSheet {
    char name[50];
    int answers[5];
    int score;
} AnswerSheet;

// Function to display the questions
void displayQuestions(Question *questions) {
    printf("----------- Exam Questions -----------\n\n");
    for (int i = 0; i < numOfQuestions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].content);
        printf("A. %s\n", questions[i].options[0]);
        printf("B. %s\n", questions[i].options[1]);
        printf("C. %s\n", questions[i].options[2]);
        printf("D. %s\n", questions[i].options[3]);
        printf("Enter your answer [A, B, C, or D]: ");
    }
}

// Function to grade the student's answer sheet
void gradeAnswers(AnswerSheet *answerSheet) {
    for (int i = 0; i < numOfQuestions; i++) {
        if (answerSheet->answers[i] == correctAnswers[i]) {
            answerSheet->score++;
        }
    }
}

int main() {
    // Initialize questions
    Question questions[numOfQuestions];
    strcpy(questions[0].content, "What is the output of 2 + 2?");
    strcpy(questions[0].options[0], "3");
    strcpy(questions[0].options[1], "4");
    strcpy(questions[0].options[2], "5");
    strcpy(questions[0].options[3], "6");
    questions[0].answer = 2;

    strcpy(questions[1].content, "What is the capital of Japan?");
    strcpy(questions[1].options[0], "Beijing");
    strcpy(questions[1].options[1], "Seoul");
    strcpy(questions[1].options[2], "Tokyo");
    strcpy(questions[1].options[3], "Shanghai");
    questions[1].answer = 2;

    strcpy(questions[2].content, "What is the largest planet in our solar system?");
    strcpy(questions[2].options[0], "Venus");
    strcpy(questions[2].options[1], "Mercury");
    strcpy(questions[2].options[2], "Jupiter");
    strcpy(questions[2].options[3], "Mars");
    questions[2].answer = 3;

    strcpy(questions[3].content, "What is the color of the sky on a clear day?");
    strcpy(questions[3].options[0], "Green");
    strcpy(questions[3].options[1], "Blue");
    strcpy(questions[3].options[2], "Red");
    strcpy(questions[3].options[3], "Yellow");
    questions[3].answer = 1;

    strcpy(questions[4].content, "What is the largest organ in the human body?");
    strcpy(questions[4].options[0], "Liver");
    strcpy(questions[4].options[1], "Lungs");
    strcpy(questions[4].options[2], "Heart");
    strcpy(questions[4].options[3], "Skin");
    questions[4].answer = 4;

    // Initialize answer sheets for each student
    AnswerSheet answerSheets[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        printf("Enter the name of Student %d: ", i+1);
        scanf("%s", answerSheets[i].name);
        displayQuestions(questions);
        for (int j = 0; j < numOfQuestions; j++) {
            char answer[1];
            scanf("%s", answer);
            if (strcmp(answer, "A") == 0) {
                answerSheets[i].answers[j] = 1;
            } else if (strcmp(answer, "B") == 0) {
                answerSheets[i].answers[j] = 2;
            } else if (strcmp(answer, "C") == 0) {
                answerSheets[i].answers[j] = 3;
            } else {
                answerSheets[i].answers[j] = 4;
            }
        }
        gradeAnswers(&answerSheets[i]);
        printf("Student %s score: %d out of %d\n", answerSheets[i].name, answerSheets[i].score, numOfQuestions);
        printf("--------------------------------------\n");
    }

    return 0;
}