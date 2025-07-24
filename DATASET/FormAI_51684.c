//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

/* Function to sanitize user input */
void sanitize_input(char input[], size_t size) {
    /* Remove newline character */
    input[strcspn(input, "\n")] = '\0';

    for (size_t i = 0; i < size; i++) {
        /* Convert all alphabets to lowercase */
        input[i] = tolower(input[i]);

        /* Remove trailing and leading whitespaces */
        if (i == 0 && isspace(input[i])) {
            while (isspace(input[i])) {
                i++;
            }
            memmove(input, input + i, strlen(input) - i + 1);
            i = 0;
        }
        if (isspace(input[i]) && i != strlen(input) - 1 && isspace(input[i + 1])) {
            size_t j = i + 1;
            while (isspace(input[j])) {
                j++;
            }
            memmove(&input[i + 1], &input[j], strlen(input) - j + 1);
        }

        /* Check for invalid characters */
        int invalid = 0;
        char *p = &input[i];
        while (*p != '\0') {
            if (!isalpha(*p) && !isspace(*p)) {
                invalid = 1;
                break;
            }
            p++;
        }
        if (invalid) {
            memset(input, '\0', size);
            printf("Invalid Input! Please enter only letters and white space.\n");
            fgets(input, size, stdin);
            sanitize_input(input, size);
            break;
        }
    }
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    sanitize_input(input, MAX_SIZE);

    printf("\nSanitized Input: %s", input);

    return 0;
}