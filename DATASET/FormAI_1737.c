//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to remove extra spaces and non-alpha characters from a given string
void sanitize(char *str) {
    char *p = str, *q = str;
    while (*q) {
        if (isalpha(*q) || isspace(*q)) {
            *p++ = tolower(*q++);
        } else {
            q++;
        }
    }
    *p = '\0';
    p = str;
    q = str;
    while (*q) {
        if (*q == ' ' && (*(q+1) == ' ' || *(q+1) == '\0')) {
            q++;
        } else {
            *p++ = *q++;
        }
    }
    *p = '\0';
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';
    sanitize(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}