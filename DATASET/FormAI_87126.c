//FormAI DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void printChar(char c, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        putchar(c);
    }
}

void printLine() {
    putchar('<');
    printChar('-', MAX_LENGTH - 2);
    putchar('>');
    putchar('\n');
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int i, j;
    int indentLevel = 0;
    int isInsideTag = 0;
    int isInsideComment = 0;
    
    // Read input
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    
    // Process input
    for (i = 0, j = 0; input[i] != '\0'; ++i) {
        if (isInsideComment) {
            if (input[i] == '*' && input[i + 1] == '/') {
                isInsideComment = 0;
                output[j++] = input[i];
                output[j++] = input[i + 1];
                i++;
            }
        } else if (isInsideTag) {
            output[j++] = input[i];
            if (input[i] == '>') {
                isInsideTag = 0;
            }
        } else {
            // Handle comments
            if (input[i] == '/' && input[i + 1] == '*') {
                isInsideComment = 1;
                output[j++] = input[i];
                output[j++] = input[i + 1];
                i++;
            } else if (input[i] == '<') {
                isInsideTag = 1;
                output[j++] = input[i];
            } else if (input[i] == '>') {
                output[j++] = input[i];
                indentLevel--;
            } else if (input[i] == '\n') {
                output[j++] = input[i];
                if (!isInsideComment) {
                    printChar('\t', indentLevel);
                }
            } else {
                output[j++] = input[i];
            }
            
            // Handle indentation
            if (input[i] == '>' && input[i + 1] != '\n') {
                printLine();
                indentLevel++;
                printChar('\t', indentLevel);
            }
        }
    }
    output[j] = '\0';
    
    // Output result
    printf("%s\n", output);
    return 0;
}