//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int score = 0;
    printf("Welcome to the Sherlock Holmes Terminal Game!\n");
    printf("Enter 'help' for a list of commands\n\n");

    while (1) {
        printf("Type your command: ");
        scanf("%s", input);

        if (strcmp(input, "score") == 0) {
            printf("Your current score is %d\n", score);
        } else if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("solve - solve the current mystery\n");
            printf("hints - get a hint about the mystery\n");
            printf("score - view your current score\n");
            printf("exit - quit the game\n");
        } else if (strcmp(input, "solve") == 0) {
            printf("You attempt to solve the mystery...\n");
            printf("Unfortunately, you are incorrect.\n");
            score--;
        } else if (strcmp(input, "hints") == 0) {
            printf("You ask for a hint...\n");
            printf("Sherlock Holmes says, 'The key to solving this mystery is in the details.'\n");
            score--;
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting game...\n");
            break;
        } else {
            printf("Invalid command. Enter 'help' for a list of commands.\n");
        }

        printf("\n");
    }

    return 0;
}