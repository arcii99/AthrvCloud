//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

void parse_syntax(char *line);

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        parse_syntax(line);
    }
    return 0;
}

void parse_syntax(char *line) {
    char c;
    int i, num_paren = 0, num_bracket = 0, num_brace = 0;

    for (i = 0; (c = line[i]) != '\0'; i++) {
        switch (c) {
            case '(':
                num_paren++;
                break;
            case ')':
                num_paren--;
                if (num_paren < 0) {
                    printf("Error: Mismatched Parentheses\n");
                    exit(1);
                }
                break;
            case '[':
                num_bracket++;
                break;
            case ']':
                num_bracket--;
                if (num_bracket < 0) {
                    printf("Error: Mismatched Brackets\n");
                    exit(1);
                }
                break;
            case '{':
                num_brace++;
                break;
            case '}':
                num_brace--;
                if (num_brace < 0) {
                    printf("Error: Mismatched Braces\n");
                    exit(1);
                }
                break;
            default:
                if (!isspace(c)) {
                    /* parse any other syntax rules here */
                }
                break;
        }
    }

    if (num_paren > 0) {
        printf("Error: Mismatched Parentheses\n");
        exit(1);
    } else if (num_bracket > 0) {
        printf("Error: Mismatched Brackets\n");
        exit(1);
    } else if (num_brace > 0) {
        printf("Error: Mismatched Braces\n");
        exit(1);
    }

    printf("Valid Syntax\n");
}