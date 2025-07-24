//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 512

void clean_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void sanitize(char *string) {
    int i, j;
    char symbol_blacklist[] = { '\\', '/', '*', '-', '`', '\'' };

    for (i = 0, j = 0; string[i] != '\0'; i++) {
        if (strchr(symbol_blacklist, string[i]) == NULL) {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

int main(void) {
    char input[MAX_INPUT_LENGTH];

    printf("Enter some input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    sanitize(input);
    printf("Your sanitized input is: %s\n", input);

    clean_stdin();
    printf("\nPress Enter to exit.");
    getchar();
    return EXIT_SUCCESS;
}