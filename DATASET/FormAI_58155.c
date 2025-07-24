//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to remove all whitespace characters from string
void remove_whitespace(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

// function to add indentation to the HTML tags
void print_with_indentation(const char *str, int indentation) {
    int len = strlen(str);
    printf("%*s", indentation, ""); // print indentation
    for (int i = 0; i < len; i++) {
        putchar(str[i]);
        if (str[i] == '>') {
            putchar('\n');
            if (i < len - 1 && str[i+1] != '<') {
                printf("%*s", indentation, "");
            }
        }
    }
}

// main function
int main() {
    char input[1000];
    printf("Enter the HTML code to beautify:\n");
    fgets(input, 1000, stdin);
    remove_whitespace(input);

    printf("\nFormatted HTML code:\n");
    int indentation = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == '<') {
            print_with_indentation(&input[i], indentation);
            if (input[i+1] != '/') {
                indentation += 4;
            }
        } else if (input[i] == '/') {
            indentation -= 4;
            print_with_indentation(&input[i], indentation);
        }
    }
    return 0;
}