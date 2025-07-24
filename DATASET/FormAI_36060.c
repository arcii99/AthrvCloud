//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>

void sanitizeInput(char *input, int index) {
    if (input[index] == '\0') {
        return;
    }

    char currentChar = input[index];
    if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z')) {
        input[index] = currentChar;
    }
    else if (currentChar == ' ') {
        input[index] = '_'; // Replace spaces with underscores
    }
    else {
        input[index] = '?'; // Replace all other characters with question marks
    }

    sanitizeInput(input, index + 1); // Recursive call for the next index
}

int main() {
    char userInput[100];

    printf("Enter your input: ");
    scanf("%[^\n]", userInput);

    sanitizeInput(userInput, 0);

    printf("Sanitized input: %s\n", userInput);

    return 0;
}