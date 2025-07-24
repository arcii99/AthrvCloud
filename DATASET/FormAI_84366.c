//FormAI DATASET v1.0 Category: Syntax parsing ; Style: random
#include<stdio.h>
#include<string.h>

int main() {
    char input[100]; //initialize an array to store user input
    int braces = 0, brackets = 0; //declare variables for braces and brackets
    printf("Enter the code to parse:\n"); 
    fgets(input, 100, stdin); //receive input from user
    for(int i = 0; i < strlen(input); i++) { 
        if(input[i] == '{') { //increment braces counter if opening brace is found
            braces++;
        }
        else if(input[i] == '}') { //decrement braces counter if closing brace is found
            braces--;
        }
        else if(input[i] == '[') { //increment brackets counter if opening bracket is found
            brackets++;
        }
        else if(input[i] == ']') { //decrement brackets counter if closing bracket is found
            brackets--;
        }
    }
    if(braces == 0 && brackets == 0) { //if both counters are zero, input is valid
        printf("The code is valid!\n");
    } 
    else if(braces > 0) { //if braces counter is greater than zero, there is a missing closing brace
        printf("Error: Missing %d } \n", braces);
    }
    else if(braces < 0) { //if braces counter is less than zero, there is a missing opening brace
        printf("Error: Missing %d { \n", -braces);
    }
    else if(brackets > 0) { //if brackets counter is greater than zero, there is a missing closing bracket
        printf("Error: Missing %d ] \n", brackets);
    }
    else if(brackets < 0) { //if brackets counter is less than zero, there is a missing opening bracket
        printf("Error: Missing %d [ \n", -brackets);
    }
    return 0; //end of program
}