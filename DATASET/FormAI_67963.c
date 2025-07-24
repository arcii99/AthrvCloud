//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to remove leading and trailing whitespaces from a string
char* trim(char* str) {
    int len = strlen(str);
    int i = 0, j = len - 1;
    while(i < len && isspace(str[i])) i++;
    while(j > i && isspace(str[j])) j--;
    str[j + 1] = '\0';
    return str + i;
}

// Function to remove non alphanumeric characters from a string
char* sanitizeInput(char* str) {
    int len = strlen(str);
    char* sanitized = malloc(len + 1);
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(isalnum(str[i])) {
            sanitized[count++] = str[i];
        }
    }
    sanitized[count] = '\0';
    return sanitized;
}

int main() {
    char input[100];
    printf("Enter a string (max 100 characters) : ");
    fgets(input, 100, stdin);

    // Remove leading and trailing whitespaces from the input
    char* trimmed = trim(input);
    printf("Trimmed input : %s\n", trimmed);

    // Sanitize the input to remove non alphanumeric characters
    char* sanitized = sanitizeInput(trimmed);
    printf("Sanitized input : %s\n", sanitized);

    free(sanitized); // Freeing the allocated memory
    return 0;
}