//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int score = 0;
    char answer[10];

    printf("Welcome to the Periodic Table Quiz! Answer each question by typing in the correct element symbol.\n");

    // Question 1
    printf("\nQuestion 1: What is the symbol for carbon? ");
    scanf("%s", answer);
    if (strcmp(answer, "C") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is C.\n");
    }

    // Question 2
    printf("\nQuestion 2: What is the symbol for iron? ");
    scanf("%s", answer);
    if (strcmp(answer, "Fe") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Fe.\n");
    }

    // Question 3
    printf("\nQuestion 3: What is the symbol for sodium? ");
    scanf("%s", answer);
    if (strcmp(answer, "Na") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Na.\n");
    }

    // Question 4
    printf("\nQuestion 4: What is the symbol for gold? ");
    scanf("%s", answer);
    if (strcmp(answer, "Au") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Au.\n");
    }

    // Question 5
    printf("\nQuestion 5: What is the symbol for mercury? ");
    scanf("%s", answer);
    if (strcmp(answer, "Hg") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Hg.\n");
    }

    // Calculate final score
    printf("\nCongratulations on finishing the quiz! Your final score is %d out of 5.\n\n", score);

    return 0;
}