//FormAI DATASET v1.0 Category: Syntax parsing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

/* function to parse a C syntax declaration */
void parseCDeclaration(char *s) {
    char *name, *type;
    char *tok = strtok(s, " ");
    int isPointer = 0;
    while (tok != NULL) {
        // check if current token is a pointer
        if (*tok == '*') {
            isPointer = 1;
        } else {
            // check if current token is a type or a name
            if (type == NULL) {
                type = tok;
                // check if a pointer to the type exists
                if (isPointer) {
                    type = strcat(type, " *");
                }
            } else {
                name = tok;
                // check if a pointer to the type exists
                if (isPointer) {
                    // set the type to pointer to type
                    type = strcat(" *", type);
                }
                printf("Variable name: %s\nType: %s\n\n", name, type);
                // reset the isPointer flag
                isPointer = 0;
            }
        }
        tok = strtok(NULL, " ");
    }
}

int main() {
    char inputDeclaration[100];
    printf("Enter a C syntax declaration: ");
    fgets(inputDeclaration, 100, stdin);
    parseCDeclaration(inputDeclaration);
    return 0;
}