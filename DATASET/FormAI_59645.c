//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
// Ada Lovelace inspired C syntax parsing example program
#include <stdio.h>
#include <string.h>

// function prototype for syntax checking
int checkSyntax(char* str);

// main function
int main() {
    char syntax[100];

    printf("Enter a C syntax: ");
	scanf("%[^\n]", syntax); // read syntax including spaces

    if(checkSyntax(syntax)) {
        printf("Syntax is correct!\n");
    } else {
        printf("Syntax is incorrect!\n");
    }

    return 0;
}

// function definition for syntax checking
int checkSyntax(char* str) {
    int openBrackets = 0, closeBrackets = 0;
    int openParenthesis = 0, closeParenthesis = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '{') {
            openBrackets++;
        } else if(str[i] == '}') {
            closeBrackets++;
        } else if(str[i] == '(') {
            openParenthesis++;
        } else if(str[i] == ')') {
            closeParenthesis++;
        }
    }

    if(openBrackets == closeBrackets && openParenthesis == closeParenthesis) {
        return 1;
    } else {
        return 0;
    }
}