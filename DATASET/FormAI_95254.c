//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QUESTIONS 20

// Definition of Question struct
typedef struct {
    char question[100];
    char options[4][100];
    int answer_index;
} Question;

// Function to initialize questions and their answers
void initialize_questions(Question questions[]) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        Question q;
        sprintf(q.question, "Question %d: What is the capital of India?", i+1);
        sprintf(q.options[0], "A. New Delhi");
        sprintf(q.options[1], "B. Mumbai");
        sprintf(q.options[2], "C. Chennai");
        sprintf(q.options[3], "D. Kolkata");
        q.answer_index = 0;
        questions[i] = q;
    }
}

// Function to display questions and get user answers
void ask_questions(Question questions[]) {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\n%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        char user_answer[1];
        printf("Enter your answer (A/B/C/D): ");
        scanf("%s", user_answer);
        int answer_index = (int)user_answer[0] - 'A';
        if (answer_index == questions[i].answer_index) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Incorrect answer! Correct answer is %s\n", questions[i].options[questions[i].answer_index]);
        }
    }
    printf("\nYour score is %d/%d\n", score, MAX_QUESTIONS);
}

int main() {
    Question questions[MAX_QUESTIONS];
    initialize_questions(questions);
    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with %d multiple choice questions.\n", MAX_QUESTIONS);
    printf("Please select one of the given options (A/B/C/D).\n");
    ask_questions(questions);
    return 0;
}