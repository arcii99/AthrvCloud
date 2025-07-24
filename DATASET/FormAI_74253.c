//FormAI DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>

int main() {
    char input[1000];
    printf("Enter a C program:\n");
    fgets(input, 1000, stdin);
    
    int curlyBraces = 0, parentheses = 0, brackets = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '{')
            curlyBraces++;
        else if (input[i] == '}')
            curlyBraces--;
        else if (input[i] == '(')
            parentheses++;
        else if (input[i] == ')')
            parentheses--;
        else if (input[i] == '[')
            brackets++;
        else if (input[i] == ']')
            brackets--;
    }
    
    if (curlyBraces == 0 && parentheses == 0 && brackets == 0) {
        printf("The program is properly formatted.\n");
        return 0;
    }
    
    if (curlyBraces != 0) {
        if (curlyBraces > 0)
            printf("There are %d more opening curly braces than closing curly braces.\n", curlyBraces);
        else
            printf("There are %d more closing curly braces than opening curly braces.\n", -curlyBraces);
    }
    
    if (parentheses != 0) {
        if (parentheses > 0)
            printf("There are %d more opening parentheses than closing parentheses.\n", parentheses);
        else
            printf("There are %d more closing parentheses than opening parentheses.\n", -parentheses);
    }
    
    if (brackets != 0) {
        if (brackets > 0)
            printf("There are %d more opening brackets than closing brackets.\n", brackets);
        else
            printf("There are %d more closing brackets than opening brackets.\n", -brackets);
    }
    
    return 0;
}