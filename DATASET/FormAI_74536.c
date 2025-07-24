//FormAI DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // declare input buffer
    printf("Enter a C syntax statement: ");
    fgets(input, 100, stdin); // reads input from user
    
    // check if statement ends with semicolon
    if (input[strlen(input)-2] != ';') {
        printf("Syntax error: statement must end with a semicolon.\n");
        return 1;
    }
    
    // check if statement contains int or float type
    if (strstr(input, "int") == NULL && strstr(input, "float") == NULL) {
        printf("Syntax error: statement must contain int or float variable type.\n");
        return 1;
    }
    
    // check if statement contains an assignment operator
    if (strchr(input, '=') == NULL) {
        printf("Syntax error: statement must include an assignment operator.\n");
        return 1;
    }
    
    // check if statement contains variable name
    char *p = strtok(input, " ");
    while (p != NULL) {
        if (strcmp(p, "int") != 0 && strcmp(p, "float") != 0 && strcmp(p, "=") != 0) {
            printf("Variable name: %s\n", p);
            break;
        }
        p = strtok(NULL, " ");
    }
    
    // check if statement contains a value to assign
    p = strtok(NULL, " ");
    if (p == NULL) {
        printf("Syntax error: statement must include a value to assign.\n");
        return 1;
    }
    printf("Value to assign: %s\n", p);
    
    return 0;
}