//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    int i;

    printf("Run the race to initialize the game..\n\n");
    printf("Ready to start? Go!\n");
  
    printf("Enter your input: ");

    fgets(input, MAX_INPUT_SIZE, stdin);

    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            input[i] = tolower(input[i]);
        }
        else {
            input[i] = ' ';
        }

        if (i == (MAX_INPUT_SIZE - 1)) {
            input[i] = '\0';
        }
    }

    printf("Your sanitized input is: %s\n\n", input);

    printf("Congratulations on crossing the finish line!\n");

    return 0;
}