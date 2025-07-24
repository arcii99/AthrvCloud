//FormAI DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

void beautifyHTML(char* code) {
    int indent_level = 0;
    int new_line = 0;
    int length = strlen(code);
    for (int i = 0; i < length; i++) {
        if (code[i] == '<') {
            if (new_line) {
                printf("\n");
                for (int j = 0; j < indent_level; j++) {
                    printf("    ");
                }
            }
            printf("%c", code[i]);
            if (code[i + 1] == '/') {
                indent_level--;
            }
            else if (code[i + 1] != '!' && code[i + 1] != '?') {
                indent_level++;
            }
            new_line = 1;
        }
        else if (code[i] == '>') {
            printf("%c", code[i]);
            new_line = 1;
        }
        else if (code[i] == '\n' || code[i] == '\r') {
            // ignore newline characters
        }
        else {
            printf("%c", code[i]);
            new_line = 0;
        }
    }
}

int main() {
    char code[MAX_LENGTH];
    printf("Enter HTML code:\n");
    fgets(code, MAX_LENGTH, stdin);
    beautifyHTML(code);
    return 0;
}