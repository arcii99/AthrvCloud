//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isDataType(char* str) {
    char* types[10] = {"int", "long", "float", "double", "char", "void", "bool", "signed", "unsigned", "short"};
    for(int i = 0; i < 10; i++) {
        if(strcmp(str, types[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidIdentifier(char* str) {
    if(!(isalpha(str[0]) || str[0] == '_')) {
        return false;
    }
    for(int i = 1; i < strlen(str); i++) {
        if(!(isalnum(str[i]) || str[i] == '_')) {
            return false;
        }
    }
    return true;
}

bool isValidNumber(char* str) {
    for(int i = 0; i < strlen(str); i++) {
        if(!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a C syntax statement: ");
    fgets(str, 100, stdin);
    char* token = strtok(str, " ");
    while(token != NULL) {
        if(isDataType(token)) {
            printf("%s is a valid dataype\n", token);
        }
        else if(isValidIdentifier(token)) {
            printf("%s is a valid identifier\n", token);
        }
        else if(isValidNumber(token)) {
            printf("%s is a valid number\n", token);
        }
        else {
            printf("%s is an invalid token\n", token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}