//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// function to check whether a given string is a valid variable name
bool isValidVariableName(char* str) {
    if(!isalpha(str[0]) && str[0] != '_') {
        return false;
    }
    for(int i=1; i<strlen(str); i++) {
        if(!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }
    return true;
}

// function to check whether a given string is a valid numeric constant
bool isValidNumericConstant(char* str) {
    bool hasDecimal = false;
    for(int i=0; i<strlen(str); i++) {
        if(!isdigit(str[i])) {
            if(hasDecimal || str[i] != '.') {
                return false;
            }
            hasDecimal = true;
        }
    }
    return true;
}

// function to parse a given line of C code and perform syntax analysis
void parseLine(char* line) {
    char* token = strtok(line, " ");
    while(token != NULL) {
        if(isValidVariableName(token)) {
            printf("Variable: %s\n", token);
        } else if(isValidNumericConstant(token)) {
            printf("Numeric Constant: %s\n", token);
        } else if(strcmp(token, "if") == 0) {
            printf("Conditional Statement: if\n");
        } else if(strcmp(token, "else") == 0) {
            printf("Conditional Statement: else\n");
        } else {
            printf("Unknown Token: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    // sample C code to be parsed
    char code[100] = "int num_1 = 10; float num_2 = 3.14; if(num_1 > num_2) { printf(\"num_1 is greater\"); } else { printf(\"num_2 is greater\"); }";
    
    // perform syntax analysis on each line of the code
    char* line = strtok(code, ";");
    while(line != NULL) {
        parseLine(line);
        line = strtok(NULL, ";");
    }

    return 0;
}