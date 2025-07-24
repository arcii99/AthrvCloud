//FormAI DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addIndentation(char *code, int indentLevel, char *indents) {
    int i;
    for (i = 0; i < indentLevel; i++) {
        strcat(code, indents);
    }
}

int main(void) {
    int indentLevel = 0;
    char *indents = "    "; // four spaces for indentation
    char line[2000];
    char code[100000] = "";
    char *token;
    char *delim = " \t";

    while (fgets(line, sizeof(line), stdin)) {
        
        // remove leading and trailing whitespace
        char *linePtr = line;
        while (*linePtr == ' ' || *linePtr == '\t') {
            linePtr++;
        }
        int len = strlen(linePtr);
        if (len > 0 && linePtr[len - 1] == '\n') {
            linePtr[len - 1] = '\0';
        }

        token = strtok(linePtr, delim);
        while (token != NULL) {
            if (strcmp(token, "{") == 0) {
                strcat(code, token);
                strcat(code, "\n");
                indentLevel++;
                addIndentation(code, indentLevel, indents);
            } else if (strcmp(token, "}") == 0) {
                strcat(code, "\n");
                indentLevel--;
                addIndentation(code, indentLevel, indents);
                strcat(code, token);
            } else {
                strcat(code, token);
                strcat(code, " ");
            }
            token = strtok(NULL, delim);
        }
        strcat(code, "\n");
        addIndentation(code, indentLevel, indents);
    }
    printf("%s", code);
    return 0;
}