//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include<stdio.h>
#include<string.h>

void parseSyntax(char *input) {
    int length = strlen(input);
    int i = 0;
    int openBrackets = 0;
    int closeBrackets = 0;
    int openCurlyBrackets = 0;
    int closeCurlyBrackets = 0;
    int openSquareBrackets = 0;
    int closeSquareBrackets = 0;
    int quotationMarks = 0;
    int singleQuotes = 0;

    for(i=0; i<length; i++) {

        if(input[i] == '(') {
            openBrackets++;
        } else if(input[i] == ')') {
            closeBrackets++;
        } else if(input[i] == '{') {
            openCurlyBrackets++;
        } else if(input[i] == '}') { 
            closeCurlyBrackets++;
        } else if(input[i] == '[') {
            openSquareBrackets++;
        } else if(input[i] == ']') { 
            closeSquareBrackets++;
        } else if(input[i] == '\"') {
            quotationMarks++;
        } else if(input[i] == '\'') {
            singleQuotes++;
        }

    }

    if(openBrackets == closeBrackets && 
       openCurlyBrackets == closeCurlyBrackets && 
       openSquareBrackets == closeSquareBrackets &&
       quotationMarks%2 == 0 && singleQuotes%2 == 0) {
        printf("Syntax is correct!\n");
    } else {
        printf("Syntax is incorrect!\n");
    }

}

int main() {

    char code[] = "int main() { printf(\"Hello, world!\"); }";
    parseSyntax(code);

    return 0;
}