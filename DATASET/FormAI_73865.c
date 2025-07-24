//FormAI DATASET v1.0 Category: Syntax parsing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter your C syntax code: \n");
    fgets(input, 1000, stdin);
    char *token;
    token = strtok(input, " ");

    while(token != NULL) {
        if (strcmp(token, "int") == 0) {
            printf("You have a variable of type int.\n");
        } else if (strcmp(token, "float") == 0) {
            printf("You have a variable of type float.\n");
        } else if (strcmp(token, "double") == 0) {
            printf("You have a variable of type double.\n");
        } else if (strcmp(token, "char") == 0) {
            printf("You have a variable of type char.\n");
        } else if (strcmp(token, "if") == 0) {
            printf("You have an if statement.\n");
        } else if (strcmp(token, "else") == 0) {
            printf("You have an else statement.\n");
        } else if (strcmp(token, "while") == 0) {
            printf("You have a while loop.\n");
        } else if (strcmp(token, "for") == 0) {
            printf("You have a for loop.\n");
        } else if (strcmp(token, "switch") == 0) {
            printf("You have a switch statement.\n");
        } else if (strcmp(token, "case") == 0) {
            printf("You have a case statement.\n");
        } else {
            printf("You have an unrecognized keyword or variable.\n");
        }
        token = strtok(NULL, " ");
    }

    return 0;
}