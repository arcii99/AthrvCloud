//FormAI DATASET v1.0 Category: Text processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    const char *delimiter = " ,.!?\n";
    char *token;
    char *tokens[10];
    int index = 0;

    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    // Tokenize the input sentence using the specified delimiter
    token = strtok(input, delimiter);
    while (token != NULL) {
        // Convert each token to uppercase
        int i = 0;
        while (token[i]) {
            token[i] = toupper(token[i]);
            i++;
        }
        // Store the tokenized and uppercase string in the tokens array
        tokens[index] = token;
        index++;

        // Get the next token
        token = strtok(NULL, delimiter);
    }

    // Print the tokenized and uppercase strings
    printf("Tokenized and Uppercase Strings:\n");
    for (int i = 0; i < index; i++) {
        printf("%s\n", tokens[i]);
    }

    // Sort the tokens array in descending order
    for (int i = 0; i < index-1; i++) {
        for (int j = i+1; j < index; j++) {
            if (strcmp(tokens[i], tokens[j]) < 0) {
                char *temp = tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = temp;
            }
        }
    }

    // Print the sorted strings
    printf("\nSorted Strings in Descending Order:\n");
    for (int i = 0; i < index; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}