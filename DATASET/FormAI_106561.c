//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Initialize global variables */
char current_token;
char current_name[100];
char input_string[1000];

/* Function declarations */
void get_next_token();
void parse();

/* Main function */
int main() {
    printf("Enter a C statement:\n");
    fgets(input_string, 1000, stdin);
    get_next_token();
    parse();
    return 0;
}

/* Parse function to process statements */
void parse() {
    if (strcmp(current_name, "int") == 0) {
        printf("Found declaration of integer variable.\n");
        get_next_token();
        if (current_token == ';') {
            printf("Statement ends with semicolon.\n");
            return;
        }
        else if (current_token == '=') {
            printf("Variable is assigned a value.\n");
            get_next_token();
            printf("Value of variable is: %c\n", current_token);
            get_next_token();
            if (current_token == ';') {
                printf("Statement ends with semicolon.\n");
                return;
            }
            else {
                printf("Syntax error: expected semicolon after assignment.\n");
                exit(1);
            }
        }
        else {
            printf("Syntax error: expected semicolon or assignment after variable declaration.\n");
            exit(1);
        }
    }
    else {
        printf("Syntax error: expected variable type.\n");
        exit(1);
    }
}

/* Tokenizer function to get the next token from input string */
void get_next_token() {
    int i = 0;
    while (isspace(input_string[i]) && input_string[i] != '\0') {
        i++;
    }
    if (input_string[i] == '\0') {
        current_token = '\0';
        return;
    }
    else if (input_string[i] == ';') {
        current_token = ';';
        return;
    }
    else if (input_string[i] == '=') {
        current_token = '=';
        return;
    }
    else {
        int j = 0;
        while (isalpha(input_string[i]) && j < 100 && input_string[i] != '\0') {
            current_name[j] = input_string[i];
            i++;
            j++;
        }
        current_name[j] = '\0';
        return;
    }
}