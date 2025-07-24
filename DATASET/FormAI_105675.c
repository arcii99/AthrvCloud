//FormAI DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include<stdio.h>
#include<string.h>

int main(){
    char input[100], operator;
    int num1, num2, result;
    printf("Enter your equation: ");
    fgets(input, 100, stdin); //takes input from user
    
    sscanf(input, "%d%c%d",&num1,&operator,&num2); //separating the operator and operands
    
    switch(operator){
        case '+':
            result = num1 + num2;
            printf("The result of %d + %d is %d\n",num1,num2,result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result of %d - %d is %d\n",num1,num2,result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result of %d * %d is %d\n",num1,num2,result);
            break;
        case '/':
            result = num1 / num2;
            printf("The result of %d / %d is %d\n",num1,num2,result);
            break;
        default:
            printf("Invalid operator entered\n");
    }
    return 0;
}