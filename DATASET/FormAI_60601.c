//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUESTION_MAX_LENGTH 100
#define ANSWER_MAX_LENGTH 50

typedef struct {
    char question[QUESTION_MAX_LENGTH];
    char answer[ANSWER_MAX_LENGTH];
} Question;

int main() {
    Question table[118];

    // Initialize questions and answers
    strcpy(table[0].question, "What is the symbol for Hydrogen?");
    strcpy(table[0].answer, "H");

    strcpy(table[1].question, "What is the symbol for Helium?");
    strcpy(table[1].answer, "He");

    strcpy(table[2].question, "What is the symbol for Lithium?");
    strcpy(table[2].answer, "Li");

    strcpy(table[3].question, "What is the symbol for Beryllium?");
    strcpy(table[3].answer, "Be");

    strcpy(table[4].question, "What is the symbol for Boron?");
    strcpy(table[4].answer, "B");

    // ... and so on

    int score = 0;
    int totalQuestions = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to test your knowledge of the elements?\n");

    char answer[ANSWER_MAX_LENGTH];
    int i;
    for (i = 0; i < 118; i++) {
        printf("\nQuestion %d:\n", (i+1));
        printf("%s\n", table[i].question);

        scanf("%s", answer);

        if (strcmp(answer, table[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s\n", table[i].answer);
        }

        totalQuestions++;
    }

    printf("\nCongratulations! You have completed the quiz!\n");
    printf("Your final score is %d out of %d\n", score, totalQuestions);

    return 0;
}