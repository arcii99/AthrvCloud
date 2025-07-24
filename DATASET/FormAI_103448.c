//FormAI DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

bool checkSyntax(char code[], int length);

int main() {
    char code[] = "(a+b)*c-(d/e+(f-g))";
    int length = sizeof(code) / sizeof(char);
    bool isSyntaxCorrect = checkSyntax(code, length);
    
    if (isSyntaxCorrect) {
        printf("The syntax of the code is correct.\n");
    } else {
        printf("The syntax of the code is incorrect.\n");
    }
    
    return 0;
}

bool checkSyntax(char code[], int length) {
    int parenthesesCount = 0;
    int squareBracketsCount = 0;
    int curlyBracketsCount = 0;
    char lastOpenParentheses = '(';
    char lastOpenSquareBracket = '[';
    char lastOpenCurlyBracket = '{';
    bool isSyntaxCorrect = true;
    
    for (int i = 0; i < length; i++) {
        char currentChar = code[i];
        
        switch (currentChar) {
            case '(':
                parenthesesCount++;
                lastOpenParentheses = '(';
                break;
            case ')':
                parenthesesCount--;
                if (lastOpenParentheses != '(') {
                    isSyntaxCorrect = false;
                }
                break;
            case '[':
                squareBracketsCount++;
                lastOpenSquareBracket = '[';
                break;
            case ']':
                squareBracketsCount--;
                if (lastOpenSquareBracket != '[') {
                    isSyntaxCorrect = false;
                }
                break;
            case '{':
                curlyBracketsCount++;
                lastOpenCurlyBracket = '{';
                break;
            case '}':
                curlyBracketsCount--;
                if (lastOpenCurlyBracket != '{') {
                    isSyntaxCorrect = false;
                }
                break;
            default:
                break;
        }
        
        if (parenthesesCount < 0 || squareBracketsCount < 0 || curlyBracketsCount < 0) {
            isSyntaxCorrect = false;
        }
    }
    
    if (parenthesesCount != 0 || squareBracketsCount != 0 || curlyBracketsCount != 0) {
        isSyntaxCorrect = false;
    }
    
    return isSyntaxCorrect;
}