//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main(void) {
    char input[MAX_LEN];
    int count = 0;
    int n;

    // Prompt the user for input
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);

    // Remove trailing newline character
    n = strlen(input);
    if (input[n-1] == '\n') {
        input[n-1] = '\0';
    }

    // Convert all characters to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Count the number of words in the string
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' && input[i-1] != ' ') {
            count++;
        }
    }
    count++;

    // Print out the processed string and the number of words
    printf("\nProcessed string: %s\n", input);
    printf("Number of words: %d\n", count);

    return 0;
}