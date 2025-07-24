//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50

// function to sanitize user input
void sanitizer(char input[], char output[]) {
    int i, j;

    // remove any leading or trailing spaces
    while (isspace((unsigned char) input[0]))
        input++;

    i = strlen(input) - 1;
    while (isspace((unsigned char) input[i]))
        i--;

    // copy sanitized input to output
    for (j = 0; j <= i; j++) {
        output[j] = input[j];
    }

    // remove new line character if present
    if (output[i] == '\n') {
        output[i] = '\0';
    }
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];

    // get user input
    printf("Enter input: ");
    fgets(input, MAX_LENGTH, stdin);

    // sanitize input
    sanitizer(input, output);

    // print sanitized input
    printf("Sanitized input: %s\n", output);

    return 0;
}