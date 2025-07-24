//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: automated
#include <stdio.h>
#include <string.h>

void sanitizeInput(char* s) {
    int i, j;
    char tempStr[100];

    for (i = 0, j = 0; i < strlen(s); i++, j++) {
        if (s[i] == ' ') {
            tempStr[j++] = '\\';
        }

        tempStr[j] = s[i];
    }

    tempStr[j] = '\0';

    strcpy(s, tempStr);
}

int main() {
    char userInput[100];

    printf("Enter your input: ");
    fgets(userInput, sizeof(userInput), stdin);

    sanitizeInput(userInput);

    printf("Sanitized input: %s", userInput);

    return 0;
}