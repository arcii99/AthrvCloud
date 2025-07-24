//FormAI DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a C syntax statement: ");
    fgets(input, 100, stdin);

    // Removing trailing newline character
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // Parsing input
    char delimiter[2] = " ";
    char* token;

    token = strtok(input, delimiter);
    int token_count = 0;
    while (token != NULL) {
        printf("Token %d: %s\n", token_count+1, token);
        token_count++;
        token = strtok(NULL, delimiter);
    }

    // Validating syntax
    if (strcmp(input, "int main()") == 0) {
        printf("Valid C syntax statement.\n");
    } else {
        printf("Invalid C syntax statement.\n");
    }

    return 0;
}