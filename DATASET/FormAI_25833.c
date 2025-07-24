//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>

int main() {
    // Input string
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Syntax checking
    int bracketCount = 0;
    int i;
    for(i=0; inputString[i]!='\0'; i++) {
        if(inputString[i] == '(') {
            bracketCount++;
        } else if(inputString[i] == ')') {
            bracketCount--;
        }
        // Check for syntax error
        if(bracketCount < 0) {
            printf("\nError: Syntax error, invalid sequence of brackets\n");
            return 0;
        }
    }
    // Final check, must have an equal number of opening and closing brackets
    if(bracketCount == 0) {
        printf("\nSyntax check passed, valid sequence of brackets\n");
        return 0;
    } else {
        printf("\nError: Syntax error, invalid sequence of brackets\n");
        return 0;
    }
}