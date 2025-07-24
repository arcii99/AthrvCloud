//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>

// Function to check if a character is an operator
int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
        return 1;
    }
    return 0;
}

// Function to check if a character is a digit
int isDigit(char c) {
    if(c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

// Function to check if a character is a valid identifier
int isIdentifier(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_')) {
        return 1;
    }
    return 0;
}

// Function to parse the input C code
void parse(char* code) {
    int len = strlen(code);
    int i = 0;
    while(i < len) {
        // Skip all whitespaces
        while(code[i] == ' ' || code[i] == '\t' || code[i] == '\n') {
            i++;
        }

        // Check for comments
        if(code[i] == '/' && (i+1) < len && code[i+1] == '/') {
            while(i < len && code[i] != '\n') {
                i++;
            }
            continue;
        }

        // Check for data type
        if((code[i] == 'i' && code[i+1] == 'n' && code[i+2] == 't') || (code[i] == 'f' && code[i+1] == 'l' && code[i+2] == 'o' && code[i+3] == 'a' && code[i+4] == 't')) {
            printf("Data type: %c%c%c\n", code[i], code[i+1], code[i+2]);
            i += 3;
            continue;
        }

        // Check for keywords
        if((code[i] == 'i' && code[i+1] == 'f') || (code[i] == 'e' && code[i+1] == 'l' && code[i+2] == 's' && code[i+3] == 'e') || (code[i] == 'w' && code[i+1] == 'h' && code[i+2] == 'i' && code[i+3] == 'l' && code[i+4] == 'e') || (code[i] == 'f' && code[i+1] == 'o' && code[i+2] == 'r')) {
            printf("Keyword: %c%c", code[i], code[i+1]);
            if(code[i+2] == ' ' || code[i+2] == '(') {
                printf("\n");
            }
            i += 2;
            continue;
        }

        // Check for identifiers
        if(isIdentifier(code[i])) {
            printf("Identifier: ");
            while(isIdentifier(code[i]) || isDigit(code[i])) {
                printf("%c", code[i]);
                i++;
            }
            printf("\n");
            continue;
        }

        // Check for operators
        if(isOperator(code[i])) {
            if(code[i+1] == '=') {
                printf("Operator: %c%c\n", code[i], code[i+1]);
                i += 2;
            } else {
                printf("Operator: %c\n", code[i]);
                i++;
            }
            continue;
        }

        // Check for literals
        if(isDigit(code[i])) {
            printf("Literal: ");
            while(isDigit(code[i])) {
                printf("%c", code[i]);
                i++;
            }
            printf("\n");
            continue;
        }

        // Unknown token
        printf("Unknown token!\n");
        i++;
    }
}


int main() {
    // Sample C code to be parsed
    char code[] = "int main() {\n\tint a = 5;\n\tfloat b = 2.5;\n\tif(a > b) {\n\t\ta = 10;\n\t} else {\n\t\ta = 20;\n\t}\n\tfor(int i = 0; i < a; i++) {\n\t\tprintf(\"%d \", i);\n\t}\n\treturn 0;\n}";

    // Call the parse function
    parse(code);

    return 0;
}