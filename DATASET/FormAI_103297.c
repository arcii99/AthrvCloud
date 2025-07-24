//FormAI DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[1000];
    int i = 0;
    printf("Enter a C program:\n");
    while ((input[i] = getchar()) != '\n') {
        i++;
    }

    input[i] = '\0'; // end of input

    int brackets = 0, parentheses = 0, braces = 0;
    char last_c = ' ';

    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // handle comments
        if (c == '/') {
            if (last_c == '/') {
                while (input[i] != '\n' && input[i] != '\0') {
                    i++;
                }
            } else {
                last_c = c;
            }
        }

        // handle brackets
        if (c == '{') {
            brackets++;
        } else if (c == '}') {
            brackets--;
        }

        // handle parentheses
        if (c == '(') {
            parentheses++;
        } else if (c == ')') {
            parentheses--;
        }

        // handle braces
        if (c == '[') {
            braces++;
        } else if (c == ']') {
            braces--;
        }

        last_c = c;
    }

    if (brackets != 0) {
        printf("Error: Number of opening and closing brackets do not match\n");
    }
    if (parentheses != 0) {
        printf("Error: Number of opening and closing parentheses do not match\n");
    }
    if (braces != 0) {
        printf("Error: Number of opening and closing braces do not match\n");
    }

    return 0;
}