//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
// Ada's Trivia Game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUESTIONS 5

// Struct to hold question and answer data
typedef struct {
    char question[50];
    char answer[20];
} Question;

// Questions and answers
Question questions[MAX_QUESTIONS] = {
    {"What was Ada Lovelace's occupation?", "Mathematician"},
    {"What was Ada Lovelace's father's occupation?", "Poet"},
    {"What was Ada Lovelace's mother's name?", "Anne Isabella Milbanke"},
    {"What was Ada Lovelace's contribution to computing?", "First computer programmer"},
    {"What language was Ada Lovelace's programming code written in?", "Analytical Engine Ordering"}
};

// Function to display question and prompt for answer
void askQuestion(Question q) {
    char userAnswer[20];
    printf("%s\n", q.question);
    printf("Your Answer: ");
    scanf("%s", userAnswer);
    if (strcmp(userAnswer, q.answer) == 0) {
        printf("Correct!\n\n");
    } else {
        printf("Incorrect. The correct answer is: %s\n\n", q.answer);
    }
}

int main() {
    int i;
    printf("Welcome to Ada's Trivia Game!\n\n");
    for (i = 0; i < MAX_QUESTIONS; i++) {
        askQuestion(questions[i]);
    }
    printf("Thanks for playing!\n");
    return 0;
}