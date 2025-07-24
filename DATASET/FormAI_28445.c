//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your name: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    // sanitize input
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32; // convert uppercase to lowercase
        } else if (input[i] == ' ') {
            input[i] = '_'; // replace spaces with underscores
        } else if (!(input[i] >= 'a' && input[i] <= 'z')) {
            input[i] = '?'; // replace non-alphabetic characters with question marks
        }
    }

    printf("Sanitized input: %s\n", input);
    return 0;
}