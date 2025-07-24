//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define TAB_SIZE 4

char* remove_whitespace_and_comments(char* code) {
    int len = strlen(code);
    int new_len = len;
    char* new_code = malloc(new_len + 1);
    int j = 0;

    bool in_comment = false;
    for (int i = 0; i < len; i++) {
        if (in_comment) {
            if (code[i] == '*' && code[i+1] == '/') {
                in_comment = false;
                i++;
            }
        }
        else {
            if (code[i] == '/' && code[i+1] == '/') {
                while (code[i] != '\n') {
                    i++;
                }
            }
            else if (code[i] == '/' && code[i+1] == '*') {
                in_comment = true;
                i++;
            }
            else if (code[i] == ' ' || code[i] == '\t' || code[i] == '\n') {
                continue;
            }
            new_code[j] = code[i];
            j++;
        }
    }
    new_code[j] = '\0';

    return new_code;
}

void beautify(char* code) {
    code = remove_whitespace_and_comments(code);
    int indent = 0;
    int len = strlen(code);
    char* beautified_code = malloc(len + 1);
    int j = 0;

    for (int i = 0; i < len; i++) {
        beautified_code[j] = code[i];
        j++;

        if (code[i] == '{' || code[i] == '(' || code[i] == '[') {
            indent++;
            beautified_code[j] = '\n';
            j++;

            for (int k = 0; k < indent * TAB_SIZE; k++) {
                beautified_code[j] = ' ';
                j++;
            }
        }
        else if (code[i] == '}' || code[i] == ')' || code[i] == ']') {
            indent--;
            beautified_code[j] = '\n';
            j++;

            for (int k = 0; k < indent * TAB_SIZE; k++) {
                beautified_code[j] = ' ';
                j++;
            }
        }
        else if (code[i] == ';') {
            beautified_code[j] = '\n';
            j++;

            for (int k = 0; k < indent * TAB_SIZE; k++) {
                beautified_code[j] = ' ';
                j++;
            }
        }
    }

    beautified_code[j] = '\0';
    printf("%s\n", beautified_code);
    free(beautified_code);
}

int main() {
    char* code = "int main(){int a=1;int b=2;if(a>b)printf(\"a>b\");else printf(\"a<=b\");return 0;}";
    beautify(code);
    return 0;
}