//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 1000

void initializeInput(char input[]) {
    printf("Enter the input HTML code:\n");
    fgets(input, MAX_SIZE, stdin);
}

void beautifyHTML(char input[], char output[]) {
    int i = 0, j = 0;
    int indentLevel = 0;
    int len = strlen(input);

    while (i < len) {
        if (input[i] == '<') { // check if starting tag
            if (input[i+1] == '/') { // closing tag
                indentLevel--;
            }
            if (j > 0 && output[j-1] == '\n') { // add indentation
                for (int k = 0; k < indentLevel; k++) {
                    output[j++] = '\t';
                }
            }
            output[j++] = input[i++]; // add starting tag
            while (i < len && input[i] != '>') { // add class attributes
                if (input[i-1] == '<' && input[i] == 'd' && input[i+1] == 'i' && input[i+2] == 'v') {
                    output[j++] = '\n';
                    for (int k = 0; k < indentLevel+1; k++) {
                        output[j++] = '\t';
                    }
                    while (input[i] != '>') {
                        output[j++] = input[i++];
                    }
                    output[j++] = '\n';
                    for (int k = 0; k < indentLevel+2; k++) {
                        output[j++] = '\t';
                    }
                    continue;
                }
                if (input[i-1] == 'c' && input[i] == 'l' && input[i+1] == 'a' && input[i+2] == 's' && input[i+3] == 's' && input[i+4] == '=') {
                    output[j++] = input[i++];
                    output[j++] = input[i++];
                    output[j++] = input[i++];
                    while (input[i] == ' ') {
                        output[j++] = input[i++];
                        output[j++] = input[i++];
                    }
                    output[j++] = ' ';
                } else {
                    output[j++] = input[i++];
                }
            }
            output[j++] = input[i++]; // add ending tag
            if (input[i-2] != '/') { // check if self-closing tag
                output[j++] = '\n';
                if (input[i-2] != '/') {
                    indentLevel++;
                }
                for (int k = 0; k < indentLevel; k++) {
                    output[j++] = '\t';
                }
            }
        } else { // not a tag
            output[j++] = input[i++];
        }
    }
    output[j] = '\0'; // terminate string
}

int main() {
    char input[MAX_SIZE], output[MAX_SIZE];

    initializeInput(input);
    beautifyHTML(input, output);

    printf("\nFormatted HTML:\n%s", output);

    return 0;
}