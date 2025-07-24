//FormAI DATASET v1.0 Category: Syntax parsing ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    printf("Enter a C language code snippet: \n");
    fgets(input, 100, stdin);

    int curly_braces = 0;
    int line_count = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            line_count++;
        } else if (input[i] == '{') {
            curly_braces++;
        } else if (input[i] == '}') {
            curly_braces--;
        }
    }

    if (curly_braces > 0) {
        printf("Error: Missing '}'\n");
    } else if (curly_braces < 0) {
        printf("Error: Too many '}'\n");
    } else {
        printf("The code is syntactically correct with %d lines.\n", line_count);
    }

    return 0;
}