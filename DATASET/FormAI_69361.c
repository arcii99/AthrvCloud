//FormAI DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum length of each question and each answer
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 20

// Define the maximum number of characters in a given answer choice
#define MAX_CHOICE_LENGTH 30

// Define the maximum allowed time for the exam
#define MAX_TIME 300

// Declare a global array to hold all the exam questions and their answer choices
char exam_questions[NUM_QUESTIONS][MAX_QUESTION_LENGTH];
char exam_answers[NUM_QUESTIONS][4][MAX_ANSWER_LENGTH];

// Define a function to load the exam questions and answer choices from a file
void load_exam_questions(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open exam file.\n");
        exit(1);
    }
    int i, j;
    for (i = 0; i < NUM_QUESTIONS; i++) {
        fgets(exam_questions[i], MAX_QUESTION_LENGTH, fp);
        for (j = 0; j < 4; j++) {
            fgets(exam_answers[i][j], MAX_ANSWER_LENGTH, fp);
        }
    }
    fclose(fp);
}

// Define a function to take the exam
void take_exam() {
    int i, j;
    int score = 0;
    int answer;
    int time_remaining = MAX_TIME;
    char response[MAX_CHOICE_LENGTH];
    time_t start_time = time(NULL);
    printf("Welcome to the Online Exam!\nYou have %d minutes to complete the exam.\n", MAX_TIME/60);
    for (i = 0; i < NUM_QUESTIONS; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("%s", exam_questions[i]);
        for (j = 0; j < 4; j++) {
            printf("%d) %s", j+1, exam_answers[i][j]);
        }
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        fgets(response, MAX_CHOICE_LENGTH, stdin);
        if (answer < 1 || answer > 4) {
            printf("Invalid answer. Please choose a number between 1 and 4.\n");
            i--;
            continue;
        }
        if (strcmp(exam_answers[i][answer-1], "Correct\n") == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
        time_t current_time = time(NULL);
        int time_diff = current_time - start_time;
        time_remaining = MAX_TIME - time_diff;
        if (time_remaining < 0) {
            break;
        }
    }
    printf("\nYour final score is: %d/%d\n", score, NUM_QUESTIONS);
    if (time_remaining <= 0) {
        printf("Time's up!\n");
    }
}

int main() {
    load_exam_questions("exam_questions.txt");
    take_exam();
    return 0;
}