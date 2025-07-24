//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    char input[1000];
    printf("Enter a C Syntax code: ");
    fgets(input, 1000, stdin);

    int curly = 0, square = 0, paren = 0; // variables to keep track of brackets

    bool line_comment = false, block_comment = false; // variables to keep track of comments

    for(int i = 0; i < strlen(input); i++) {

        // skip if inside a block comment
        if(block_comment) {
            if(input[i] == '*' && input[i+1] == '/') {
                block_comment = false;
                i++;
            }
            continue;
        }

        // skip if inside a line comment
        if(line_comment) {
            if(input[i] == '\n') {
                line_comment = false;
            }
            continue;
        }

        // check for block comment
        if(input[i] == '/' && input[i+1] == '*') {
            block_comment = true;
            i++;
            continue;
        }

        // check for line comment
        if(input[i] == '/' && input[i+1] == '/') {
            line_comment = true;
            i++;
            continue;
        }

        // keep track of brackets
        if(input[i] == '{') {
            curly++;
        } else if(input[i] == '}') {
            curly--;
        } else if(input[i] == '[') {
            square++;
        } else if(input[i] == ']') {
            square--;
        } else if(input[i] == '(') {
            paren++;
        } else if(input[i] == ')') {
            paren--;
        }

    }

    // check if brackets are balanced
    if(curly != 0 || square != 0 || paren != 0) {
        printf("Syntax error: unbalanced brackets!\n");
        return 1;
    }

    printf("Your syntax is correct. Well done!\n");

    return 0;
}