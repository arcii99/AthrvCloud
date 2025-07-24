//FormAI DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void indent(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter the HTML code to beautify:\n");
    fgets(input, MAX_LENGTH, stdin);

    int len = strlen(input);
    int indent_depth = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == '<') {
            if (input[i + 1] == '/') {  // closing tag, decrement indent
                indent_depth -= 2;
            }
            indent(indent_depth);
            printf("%c", input[i]);
            if (input[i + 1] != '/') {  // opening tag, increment indent
                indent_depth += 2;
            }
        } else if (input[i] == '>') {
            printf(">\n");  // finish line for each tag
        } else {
            printf("%c", input[i]);
        }
    }

    return 0;
}