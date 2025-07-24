//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *keywords[] = {"int", "char", "float", "double", "if", "else", "while", "for", "switch", "case", "break", "continue", "return", "struct"};
int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

void parse_c_syntax(char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        int is_keyword = 0;
        for (int i = 0; i < num_keywords; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                printf("%s is a keyword!\n", token);
                is_keyword = 1;
                break;
            }
        }
        if (!is_keyword) {
            printf("%s is not a keyword.\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[100];
    printf("Enter some C syntax: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline
    parse_c_syntax(input);
    return 0;
}