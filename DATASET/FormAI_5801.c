//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    char userInput[100];
    printf("Enter your input: ");
    scanf("%s", userInput);

    for(int i=0; i<strlen(userInput); i++) {

        //sanitize any spaces
        if(userInput[i] == ' ') {
            userInput[i] = '_';

        //sanitize any special characters
        } else if(userInput[i] == '!' || userInput[i] == '@' || userInput[i] == '#' || userInput[i] == '$' || userInput[i] == '%' || userInput[i] == '^' || userInput[i] == '&' || userInput[i] == '*' || userInput[i] == '(' || userInput[i] == ')' || userInput[i] == '-' || userInput[i] == '+' || userInput[i] == '=' || userInput[i] == '[' ||  userInput[i] == ']' || userInput[i] == '{' || userInput[i] == '}' || userInput[i] == '|' || userInput[i] == '\\' || userInput[i] == ';' ||  userInput[i] == ':' || userInput[i] == '\'' || userInput[i] == '\"' || userInput[i] == ',' || userInput[i] == '.' || userInput[i] == '/' || userInput[i] == '<' || userInput[i] == '>' || userInput[i] == '?' || userInput[i] == '`' || userInput[i] == '~') {
            userInput[i] = ' ';

        //reject any non-alphabetic characters
        } else if(!isalpha(userInput[i])) {
            printf("Your input contains non-alphabetic characters and cannot be sanitized.\n");
            return 1;
        }
    }

    printf("Your sanitized input is: %s\n", userInput);
    return 0;
}