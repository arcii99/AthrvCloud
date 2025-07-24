//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
/* This program will take a mathematical expression consisting of only addition and subtraction of integers as input and output the computed value */

#include <stdio.h>
#include <string.h>

int main(){

    char expr[50];
    int n = 0, sum = 0, temp = 0, sign = 1;

    printf("Enter a mathematical expression:\n");
    scanf("%s", expr);

    // Parsing the expression
    while(expr[n] != '\0'){

        if(expr[n] >= '0' && expr[n] <= '9'){
            temp = temp*10 + (expr[n] - '0');
        }
        else if(expr[n] == '+'){
            sum += sign*temp;
            sign = 1;
            temp = 0;
        }
        else if(expr[n] == '-'){
            sum += sign*temp;
            sign = -1;
            temp = 0;
        }
        else{
            printf("Invalid expression!\n");
            return 0;
        }

        n++;
    }

    // Adding the last integer to the sum
    sum += sign*temp;

    printf("The computed value is: %d\n", sum);

    return 0;
}