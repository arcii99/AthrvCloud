//FormAI DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include<stdio.h>

int main(){
    //declaring variables
    int x, y, result;
    char operator;

    //getting input from user
    printf("Enter an arithmetic expression: ");
    scanf("%d %c %d", &x, &operator, &y);

    //conditionals for arithmetic operations
    if(operator=='+'){
        result=x+y;
        printf("The sum is: %d", result);
    }
    else if(operator=='-'){
        result=x-y;
        printf("The difference is: %d", result);
    }
    else if(operator=='*'){
        result=x*y;
        printf("The product is: %d", result);
    }
    else if(operator=='/'){
        if(y==0){
            printf("Error: Division by zero");
        }
        else{
            result=x/y;
            printf("The quotient is: %d", result);
        }
    }
    else{
        printf("Error: Invalid operator");
    }

    return 0;
}