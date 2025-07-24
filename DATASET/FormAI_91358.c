//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to sanitize user input by removing special characters and new line characters */
void sanitize(char *str) {
    int i, j;
    /* list of special characters to remove */
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\"', '<', '>', ',', '.', '/', '?'};

    /* remove trailing newline character */
    str[strcspn(str, "\n")] = 0;

    /* iterate through string */
    for (i = 0; str[i]; i++) {
        /* check if character is a special character */
        for (j = 0; j < strlen(special_chars); j++) {
            if (str[i] == special_chars[j]) {
                /* replace special character with space */
                str[i] = ' ';
                break;
            }
        }
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%[^\n]", input);

    sanitize(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}