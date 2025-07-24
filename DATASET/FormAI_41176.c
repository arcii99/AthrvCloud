//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Donald Knuth
#include <stdio.h>

int main() {
    char input[100];
    printf("Enter some C code:\n");
    fgets(input, 100, stdin);

    int i = 0;
    int curlyCount = 0;
    int parenthesesCount = 0;
    int squareCount = 0;

    while (input[i] != '\0') {
        if (input[i] == '{') {
            curlyCount++;
        } else if (input[i] == '}') {
            if (curlyCount == 0) {
                printf("Error: Too many closing curly braces.\n");
                return 1;
            }
            curlyCount--;
        } else if (input[i] == '(') {
            parenthesesCount++;
        } else if (input[i] == ')') {
            if (parenthesesCount == 0) {
                printf("Error: Too many closing parentheses.\n");
                return 1;
            }
            parenthesesCount--;
        } else if (input[i] == '[') {
            squareCount++;
        } else if (input[i] == ']') {
            if (squareCount == 0) {
                printf("Error: Too many closing square brackets.\n");
                return 1;
            }
            squareCount--;
        }

        i++;
    }

    if (curlyCount > 0) {
        printf("Error: Too many opening curly braces.\n");
        return 1;
    }
    if (parenthesesCount > 0) {
        printf("Error: Too many opening parentheses.\n");
        return 1;
    }
    if (squareCount > 0) {
        printf("Error: Too many opening square brackets.\n");
        return 1;
    }

    printf("Code syntax is correct!\n");
    return 0;
}