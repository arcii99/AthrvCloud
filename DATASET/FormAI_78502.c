//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <string.h>

/* Struct for holding variable information */
typedef struct {
    char name[50];
    char type[50];
} Variable;

/* Function for parsing syntax */
void parseSyntax(char* syntax) {
    char* token;
    Variable varList[50];
    int varCount = 0;

    /* Check for variable declaration */
    if (strstr(syntax, "int") || strstr(syntax, "float") || strstr(syntax, "char")) {
        printf("Variable Declaration Found:\n");

        /* Split the syntax into tokens */
        token = strtok(syntax, " ");
        while (token != NULL) {

            /* Check for variable type */
            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0) {
                strcpy(varList[varCount].type, token);
            }

            /* Check for variable name */
            if (varCount > 0 && strcmp(varList[varCount-1].type, "int") == 0 || strcmp(varList[varCount-1].type, "float") == 0 || strcmp(varList[varCount-1].type, "char") == 0) {
                strcpy(varList[varCount-1].name, token);
            }

            token = strtok(NULL, " ");
            varCount++;
        }

        /* Print out the variables */
        for (int i = 0; i < varCount-1; i++) {
            printf("%s %s;\n", varList[i].type, varList[i].name);
        }
    }

    /* Check for function declaration */
    else if (strstr(syntax, "(") && strstr(syntax, ")")) {
        printf("Function Declaration Found:\n");

        /* Split syntax into tokens */
        token = strtok(syntax, " ");
        while (token != NULL) {

            /* Check for return type */
            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0 || strcmp(token, "void") == 0) {
                printf("Return Type: %s\n", token);
            }

            /* Check for function name */
            if (strstr(token, "(")) {
                char* nameToken = strtok(token, "(");
                printf("Function Name: %s\n", nameToken);
            }

            token = strtok(NULL, " ");
        }
    }

    /* If no variables or functions are found, print error message */
    else {
        printf("Invalid Syntax!\n");
    }
}

int main() {
    char syntax[100];

    /* Prompt user for syntax input */
    printf("Enter C syntax: ");
    fgets(syntax, 100, stdin);

    /* Remove newline character from input */
    strtok(syntax, "\n");

    /* Call parseSyntax function */
    parseSyntax(syntax);

    return 0;
}