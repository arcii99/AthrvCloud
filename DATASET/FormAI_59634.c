//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 1000

int main() {
    char userInput[MAX_SIZE], sanitizedInput[MAX_SIZE];
    int len, i, j;

    // Welcome user
    printf("Hello! This is a user input sanitizer program.\n");
    printf("Please input a string:\n");

    // User inputs string
    fgets(userInput, MAX_SIZE, stdin);

    // Remove newline character at the end of userInput
    len = strlen(userInput);
    if (userInput[len-1] == '\n') {
        userInput[len-1] = '\0';
    }

    // Sanitize userInput
    for (i=0, j=0; i<len; i++) {
        if (userInput[i] >= 'a' && userInput[i] <= 'z') {
            sanitizedInput[j++] = userInput[i];
        }
        else if (userInput[i] >= 'A' && userInput[i] <= 'Z') {
            sanitizedInput[j++] = userInput[i] + ('a'-'A');
        }
    }
    sanitizedInput[j] = '\0';

    // Display sanitizedInput
    printf("Sanitized Input: %s\n", sanitizedInput);

    return 0;
}