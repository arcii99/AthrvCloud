//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structs */
typedef struct {
    char type[256];
    char name[256];
    int value;
} token;

/* Forward Declarations */
int parse_expression(void);
int parse_term(void);
int parse_factor(void);
void getNextToken(void);

/* Globals */
token current_token;
char input[256];
int i = 0;

int main() {
    printf("Welcome to RetroSyntax!\n");
    printf("Please enter your code:\n");

    fgets(input, 256, stdin);

    printf("Your code:\n%s", input);

    getNextToken();
    int result = parse_expression();

    printf("RESULT: %d\n", result);

    return 0;
}

/* Functions */
void getNextToken() {
    char token_type[256] = "";
    char token_name[256] = "";
    int token_value = 0;

    while(input[i] == ' ' || input[i] == '\n') {
        i++;
    }

    if(input[i] >= '0' && input[i] <= '9') {
        token_type[0] = 'i';
        sscanf(input + i, "%d", &token_value);
        sprintf(token_name, "%d", token_value);
        i += strlen(token_name);
    } else if(input[i] == '+') {
        token_type[0] = '+';
        token_name[0] = '+';
        i++;
    } else if(input[i] == '-') {
        token_type[0] = '-';
        token_name[0] = '-';
        i++;
    } else if(input[i] == '*') {
        token_type[0] = '*';
        token_name[0] = '*';
        i++;
    } else if(input[i] == '/') {
        token_type[0] = '/';
        token_name[0] = '/';
        i++;
    }

    strcpy(current_token.type, token_type);
    strcpy(current_token.name, token_name);
    current_token.value = token_value;
}

int parse_expression() {
    int result = parse_term();

    while(current_token.type[0] == '+' || current_token.type[0] == '-') {
        token op = current_token;
        getNextToken();

        int term_result = parse_term();

        if(op.type[0] == '+') {
            result += term_result;
        } else {
            result -= term_result;
        }
    }

    return result;
}

int parse_term() {
    int result = parse_factor();

    while(current_token.type[0] == '*' || current_token.type[0] == '/') {
        token op = current_token;
        getNextToken();

        int factor_result = parse_factor();

        if(op.type[0] == '*') {
            result *= factor_result;
        } else {
            result /= factor_result;
        }
    }

    return result;
}

int parse_factor() {
    int result = 0;

    if(current_token.type[0] == 'i') {
        result = current_token.value;
        getNextToken();
    } else if(current_token.type[0] == '(') {
        getNextToken();
        result = parse_expression();
        getNextToken();
    }

    return result;
}