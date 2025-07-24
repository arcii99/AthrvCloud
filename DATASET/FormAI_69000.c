//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

// Struct to hold question and answer
typedef struct {
    char question[100];
    char answer[100];
} question_t;

// Populate questions and answers
void populate_questions(question_t* questions) {
    strcpy(questions[0].question, "What is the symbol for magnesium?");
    strcpy(questions[0].answer, "Mg");

    strcpy(questions[1].question, "What is the symbol for gold?");
    strcpy(questions[1].answer, "Au");

    strcpy(questions[2].question, "What is the symbol for oxygen?");
    strcpy(questions[2].answer, "O");

    strcpy(questions[3].question, "What is the symbol for sulfur?");
    strcpy(questions[3].answer, "S");

    strcpy(questions[4].question, "What is the symbol for carbon?");
    strcpy(questions[4].answer, "C");

    strcpy(questions[5].question, "What is the symbol for nitrogen?");
    strcpy(questions[5].answer, "N");

    strcpy(questions[6].question, "What is the symbol for chlorine?");
    strcpy(questions[6].answer, "Cl");

    strcpy(questions[7].question, "What is the symbol for helium?");
    strcpy(questions[7].answer, "He");

    strcpy(questions[8].question, "What is the symbol for lithium?");
    strcpy(questions[8].answer, "Li");

    strcpy(questions[9].question, "What is the symbol for iron?");
    strcpy(questions[9].answer, "Fe");
}

// Shuffle the questions array using Fisher-Yates algorithm
void shuffle_questions(question_t* questions, int size) {
    for (int i = size - 1; i >= 1; i--) {
        int j = rand() % i;
        question_t temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    question_t questions[MAX_QUESTIONS];
    populate_questions(questions);

    int score = 0;

    // Shuffle the questions
    srand(time(NULL));
    shuffle_questions(questions, MAX_QUESTIONS);

    // Ask each question
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d) %s\n", i+1, questions[i].question);

        char answer[100];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s\n", questions[i].answer);
        }
    }

    printf("Your final score is %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}