//FormAI DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUESTIONS 10 // Maximum number of questions in the exam
#define MAX_OPTIONS 4 // Maximum number of options for each question

int score = 0; // Global variable to keep track of the user's score

// Struct to represent a question in the exam
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
} Question;

// Function to initialize a question with the specified values
void initializeQuestion(Question *q, char *question, char *option1, char *option2, char *option3, char *option4, int answer) {
    strcpy(q->question, question);
    strcpy(q->options[0], option1);
    strcpy(q->options[1], option2);
    strcpy(q->options[2], option3);
    strcpy(q->options[3], option4);
    q->answer = answer;
}

// Function to display a question to the user and get their answer
int askQuestion(Question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, q->options[i]);
    }
    int userAnswer;
    printf("Enter your answer: ");
    scanf("%d", &userAnswer);
    return userAnswer;
}

// Function to grade the user's answers and display their score
void gradeExam(Question *questions, int numQuestions) {
    printf("\n\n*** Exam Results ***\n");
    for (int i = 0; i < numQuestions; i++) {
        if (askQuestion(&questions[i]) == questions[i].answer) {
            printf("Question %d: Correct!\n", i + 1);
            score++;
        }
        else {
            printf("Question %d: Incorrect. The correct answer is %d.\n", i + 1, questions[i].answer);
        }
    }
    printf("Total score: %d out of %d\n", score, numQuestions);
}

// Main function to run the online exam system
int main() {
    Question questions[MAX_QUESTIONS];

    // Initialize the questions
    initializeQuestion(&questions[0], "What is the capital of India?", "New Delhi", "Mumbai", "Kolkata", "Chennai", 1);
    initializeQuestion(&questions[1], "Which planet is known as the Red Planet?", "Mars", "Venus", "Jupiter", "Mercury", 1);
    initializeQuestion(&questions[2], "What is the highest mountain peak in the world?", "Mount Everest", "K2", "Kangchenjunga", "Lhotse", 1);
    initializeQuestion(&questions[3], "What is the smallest country in the world by land area?", "Vatican City", "Monaco", "Nauru", "Tuvalu", 1);
    initializeQuestion(&questions[4], "What is the largest river in the world by volume?", "Amazon River", "Nile River", "Yangtze River", "Congo River", 1);

    // Get the number of questions to ask from the user
    int numQuestions;
    printf("Enter the number of questions to include in the exam (up to %d): ", MAX_QUESTIONS);
    scanf("%d", &numQuestions);

    // Make sure the specified number of questions is valid
    if (numQuestions < 1 || numQuestions > MAX_QUESTIONS) {
        printf("Invalid number of questions. Exiting.\n");
        return 1;
    }

    // Grade the exam
    gradeExam(questions, numQuestions);

    return 0;
}