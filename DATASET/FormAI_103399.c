//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Linus Torvalds Style C Periodic Table Quiz*/

int main()
{
    int score = 0; 
    char answer[20];

    printf("Welcome to the C Periodic Table Quiz! \n");
    printf("----------------------------------- \n");

    printf("Question 1: What is the symbol for Hydrogen? \n");
    scanf("%s", answer);

    if (strcmp(answer, "H") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is H. \n");
    }

    printf("Question 2: What is the symbol for Carbon? \n");
    scanf("%s", answer);

    if (strcmp(answer, "C") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is C. \n");
    }

    printf("Question 3: What is the symbol for Oxygen? \n");
    scanf("%s", answer);

    if (strcmp(answer, "O") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is O. \n");
    }

    printf("Question 4: What is the symbol for Iron? \n");
    scanf("%s", answer);

    if (strcmp(answer, "Fe") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Fe. \n");
    }

    printf("Question 5: What is the symbol for Gold? \n");
    scanf("%s", answer);

    if (strcmp(answer, "Au") == 0) {
        printf("Correct! \n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Au. \n");
    }

    printf("You scored %d out of 5. \n", score);

    return 0;
}