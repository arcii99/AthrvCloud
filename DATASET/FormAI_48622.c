//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char* input);

int main() {
    char input[100];
    printf("Enter a string to sanitize:\n");
    fgets(input, 100, stdin);
    sanitize(input);
    printf("Sanitized string: %s\n", input);
    return 0;
}

void sanitize(char* input) {
    int i, j;
    int len = strlen(input);
    char sanitized[len];
    j = 0;
    for(i = 0; i < len; i++) {
        if(isalnum(input[i])) {
            sanitized[j] = input[i];
            j++;
        }
    }
    sanitized[j] = '\0';
    strcpy(input, sanitized);
}