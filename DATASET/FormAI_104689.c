//FormAI DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char code[100];
    printf("Enter some C code:\n");
    fgets(code, 100, stdin);

    char* token = strtok(code, " ");
    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "double") == 0) {
            token = strtok(NULL, " ");
            if (*token == '(') {
                printf("Function declaration: %s\n", token);
            } else {
                printf("Variable declaration: %s\n", token);
            }
        } else if (strcmp(token, "if") == 0 || strcmp(token, "else") == 0) {
            printf("Conditional statement: %s\n", token);
        } else if (strcmp(token, "while") == 0 || strcmp(token, "for") == 0) {
            printf("Loop statement: %s\n", token);
        } else if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0) {
            printf("Block statement: %s\n", token);
        } else {
            printf("Syntax not recognized: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}