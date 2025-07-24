//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];

    printf("Enter a C program: ");
    fgets(input, 1000, stdin); // Read input from user

    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        // Check for comments
        if (input[i] == '/' && input[i + 1] == '/') {
            // This line is a comment - ignore the rest of the line
            break;
        } else if (input[i] == '/' && input[i + 1] == '*') {
            // This is the start of a block comment
            for (int j = i + 2; j < length; j++) {
                if (input[j] == '*' && input[j + 1] == '/') {
                    // This is the end of the block comment
                    i = j + 1;
                    break;
                }
            }
        } else {
            printf("%c", input[i]);
        }
    }

    return 0;
}