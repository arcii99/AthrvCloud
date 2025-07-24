//FormAI DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to check if character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// function to check if character is an alphabet
int isAlpha(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int main() {
    char input[1000];
    int i, len, error = 0;

    // ask user for input
    printf("Enter a line of code:\n");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // loop through each character of the input
    for(i=0; i<len; i++) {
        // if character is not a whitespace
        if(input[i] != ' ') {
            // if character is not an alphabet or digit
            if(!isAlpha(input[i]) && !isDigit(input[i])) {
                printf("Error! Invalid character '%c' at position %d.\n", input[i], i+1);
                error = 1;
                break;
            }
            // if character is an alphabet
            else if(isAlpha(input[i])) {
                // check if it is a keyword
                char temp[15];
                int j = 0;
                while(i<len && isAlpha(input[i])) {
                    temp[j++] = input[i++];
                }
                temp[j] = '\0';
                i--;
                if(!strcmp(temp, "if") || !strcmp(temp, "else") || !strcmp(temp, "while") || !strcmp(temp, "for") || !strcmp(temp, "int") || !strcmp(temp, "char") || !strcmp(temp, "float") || !strcmp(temp, "double")) {
                    printf("'%s' is a keyword.\n", temp);
                }
                else {
                    printf("'%s' is an identifier.\n", temp);
                }
            }
            // if character is a digit
            else {
                // check if it is a number
                char temp[15];
                int j = 0;
                while(i<len && isDigit(input[i])) {
                    temp[j++] = input[i++];
                }
                temp[j] = '\0';
                i--;
                printf("'%s' is a number.\n", temp);
            }
        }
    }

    // if no error found
    if(!error) {
        printf("Syntax is correct!\n");
    }

    return 0;
}