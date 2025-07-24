//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printErrorMessage(char *errorMessage) {
    printf("[Error] %s. Sorry, I can't fix stupid.\n", errorMessage);
}

void fixProblem(char *problem) {
    printf("[Info] Fixing %s...\n", problem);
}

int main() {
    char *problem = malloc(100 * sizeof(char));
    printf("Hey there! Welcome to the System Administrator Bot!\n");
    printf("What seems to be the problem?\n");
    scanf("%s", problem);

    if (strcmp(problem, "printer") == 0) {
        fixProblem(problem);
        printf("Problem fixed! Happy printing!\n");
    } else if (strcmp(problem, "Internet") == 0) {
        fixProblem(problem);
        printf("Problem fixed! Enjoy your browsing!\n");
    } else if (strcmp(problem, "email") == 0) {
        fixProblem(problem);
        printf("Problem fixed! Keep on emailing!\n");
    } else {
        printErrorMessage("Sorry, I don't know how to fix that.");
        exit(1);
    }

    free(problem);
    return 0;
}