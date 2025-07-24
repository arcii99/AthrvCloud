//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
void sanitizeInput(char *str) {
    int i, j = 0;
    char temp[strlen(str)];
    memset(temp, 0, strlen(str));

    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) || isdigit(str[i]) || str[i] == ' ') {
            temp[j] = str[i];
            j++;
        }
    }

    memset(str, 0, strlen(str));
    strcpy(str, temp);
}

int main() {
    char input[100];

    printf("Enter your input: ");
    fgets(input, 100, stdin);

    sanitizeInput(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}