//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char code[1000];
    printf("Enter your unformatted HTML code:\n");
    fgets(code, 1000, stdin);

    // Remove comments and whitespace
    char formatted_code[1000];
    int i, j;
    j = 0;
    for (i = 0; i < strlen(code); i++) {
        if (code[i] == '<' && code[i + 1] == '!') {
            while (code[i] != '>') {
                i++;
            }
        } else if (code[i] != '\n' && code[i] != '\t' && code[i] != ' ') {
            formatted_code[j] = code[i];
            j++;
        }
    }

    // Add indentations
    int current_indentation = 0;
    char beautified_code[1000];
    j = 0;
    for (i = 0; i < strlen(formatted_code); i++) {
        if (formatted_code[i] == '<') {
            if (formatted_code[i + 1] == '/') {
                current_indentation--;
            }
            for (int k = 0; k < current_indentation; k++) {
                beautified_code[j] = '\t';
                j++;
            }
            if (formatted_code[i + 1] != '!' && formatted_code[i + 1] != '/') {
                current_indentation++;
            }
        }
        beautified_code[j] = formatted_code[i];
        j++;
    }

    printf("\nHere is your formatted HTML code in Cyberpunk style:\n");
    printf("%s\n", beautified_code);

    return 0;
}