//FormAI DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>

int main(){
    printf("Hello fellow coders, I'm so excited to share with you my unique C syntax parsing program!\n");
    printf("Let's get straight to it!\n\n");

    char code[500]; // 500 characters of code, plenty of space!
    printf("Please enter your C code: ");
    fgets(code, 500, stdin); // gets user input

    int i; 
    for(i=0; code[i] != '\0'; i++){ // loop through characters in code
        if(code[i] == ';'){ // check for semicolons
            printf("Semicolon found on line %d! Nice job following convention. ;)\n", i+1);
        }
        if(code[i] == '{'){ // check for left curly braces
            printf("Opening curly brace found on line %d! Time to get down to business.\n", i+1);
        }
        if(code[i] == '}'){ // check for right curly braces
            printf("Closing curly brace found on line %d. Don't forget to end your blocks!\n", i+1);
        }
        if(code[i] == '('){ // check for parentheses
            printf("Left parenthesis found on line %d! Looks like a function call.\n", i+1);
        }
        if(code[i] == ')'){ // check for parentheses
            printf("Right parenthesis found on line %d! Ending a function call perhaps?\n", i+1);
        }
    }

    printf("\nWow, that was fun! I hope you enjoyed my unique C syntax parsing program. Until next time, happy coding!\n");

    return 0;
}