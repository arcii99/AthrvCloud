//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>

int main() {

    int num1, num2; //declaring integer variables
    char operator; //declaring character variable
    
    printf("Welcome to the Curious Calculator Program!\n");
    printf("Please enter an operator (+, -, *, /): ");
    scanf("%c", &operator); //taking operator input from user
    
    printf("\nGreat, you have chosen the operator: %c\n", operator);
    printf("Now enter two numbers to perform the operation: ");
    scanf("%d %d", &num1, &num2); //taking number inputs from user
    
    switch(operator) { //performing operation based on user input
        
        case '+':
            printf("\n%d + %d = %d\n", num1, num2, num1+num2);
            break;
        
        case '-':
            printf("\n%d - %d = %d\n", num1, num2, num1-num2);
            break;
            
        case '*':
            printf("\n%d x %d = %d\n", num1, num2, num1*num2);
            break;
            
        case '/':
            if(num2 == 0) {
                printf("\nError: Cannot divide by zero\n");
                break;
            } else {
                printf("\n%d / %d = %d\n", num1, num2, num1/num2);
                break;
            }
        
        default:
            printf("\nError: Invalid operator\n");
    }
    
    printf("\nThank you for using the Curious Calculator Program. Have a great day!\n");

    return 0;
}