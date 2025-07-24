//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ada Lovelace
/* Oh, greetings dear coders!
 * Let's create a program that parses C Syntax
 * In Ada Lovelace's style, we'll add some elegance
 * And make sure the code passes without any hindrance!
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100

int main(){
    char code[MAX_LENGTH];
    int i, open_bracket=0, close_bracket=0, open_paren=0, close_paren=0, open_curly=0, close_curly=0;

    printf("Please provide your C Syntax: ");
    fgets(code, MAX_LENGTH, stdin); // get input from user

    for (i=0; i<strlen(code); i++){
        if (code[i] == '['){ // check for open bracket
            open_bracket++;
        } else if (code[i] == ']'){ // check for close bracket
            close_bracket++;
        } else if (code[i] == '('){ // check for open parenthesis
            open_paren++;
        } else if (code[i] == ')'){ // check for close parenthesis
            close_paren++;
        } else if (code[i] == '{'){ // check for open curly bracket
            open_curly++;
        } else if (code[i] == '}'){ // check for close curly bracket
            close_curly++;
        }
    }

    if (open_bracket != close_bracket){
        printf("Error: Mismatched brackets\n");
        exit(0);
    } else if (open_paren != close_paren){
        printf("Error: Mismatched parentheses\n");
        exit(0);
    } else if (open_curly != close_curly){
        printf("Error: Mismatched curly braces\n");
        exit(0);
    } else {
        printf("Your C Syntax is valid. Huzzah!\n");
    }

    return 0;
}