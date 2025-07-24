//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char userInput[100];
    int i, j, flag;

    printf("Enter your input: ");
    fgets(userInput, 100, stdin);

    printf("Your original input: %s\n", userInput);

    // Removing leading and trailing whitespaces
    i = 0;
    while (userInput[i] == ' ') {
        i++;
    }
    j = strlen(userInput) - 1;
    while (userInput[j] == ' ' || userInput[j] == '\n') {
        j--;
    }
    userInput[j+1] = '\0';
    strcpy(userInput, &userInput[i]);

    printf("Input after removing leading/trailing whitespaces: %s\n", userInput);

    // Checking for non-alphanumeric characters
    for (i = 0; i < strlen(userInput); i++) {
        flag = 0;
        if ((userInput[i] >= 'a' && userInput[i] <= 'z') || (userInput[i] >= 'A' && userInput[i] <= 'Z') || (userInput[i] >= '0' && userInput[i] <= '9')) {
            flag = 1;
        }
        if (!flag) {
            printf("Input contains non-alphanumeric characters!\n");
            exit(0);
        }
    }

    printf("Input is alphanumeric!\n");

    return 0;
}