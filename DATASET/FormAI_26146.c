//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *input) {
    int i, j;
    char sanitized_str[100];

    for(i=0, j=0; i<strlen(input); i++) {
        if(isalpha(input[i])) {
            sanitized_str[j++] = tolower(input[i]);
        }
        else if(isdigit(input[i])) {
            sanitized_str[j++] = input[i];
        }
    }
    sanitized_str[j] = '\0';

    strcpy(input, sanitized_str);
}

int main() {
    char input_str[100];

    printf("Enter a string to sanitize: ");
    fgets(input_str, 100, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; // remove newline character

    sanitize(input_str);

    printf("Sanitized string: %s\n", input_str);

    return 0;
}