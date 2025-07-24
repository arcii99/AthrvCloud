//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <string.h>

/* This program takes a mathematical expression as input and
   evaluates it by processing the text using certain rules. */

int main() {
    char expression[100];   // declare a character array to hold the expression
    int i, j, len, num = 0, op1 = 1, op2 = 0;   // declare variables for loop iterations and calculations
    
    printf("Enter a mathematical expression: ");
    fgets(expression, 100, stdin);   // read the expression from user input
    len = strlen(expression);   // find the length of the expression
    
    for(i=0; i<len; i++) {
        if(expression[i] >= '0' && expression[i] <= '9') {
            num = num * 10 + (expression[i] - '0');   // convert the character to integer digit and form the number
        }
        else if(expression[i] == '+') {
            op2 += op1 * num;   // add the previous number to the result
            op1 = 1;   // initialize the operator to add next number
            num = 0;   // reset the number to zero for next input
        }
        else if(expression[i] == '-') {
            op2 += op1 * num;   // add the previous number to the result
            op1 = -1;   // initialize the operator to subtract next number
            num = 0;   // reset the number to zero for next input
        }
        else if(expression[i] == '*') {
            num *= (expression[i+1] - '0');   // multiply the number with the next digit
            i++;   // skip the next digit as it is already processed
        }
        else if(expression[i] == '/') {
            num /= (expression[i+1] - '0');   // divide the number by the next digit
            i++;   // skip the next digit as it is already processed
        }
    }
    op2 += op1 * num;   // add the last number to the result
    
    printf("The value of the expression is: %d\n", op2);   // print the result
    
    return 0;
}