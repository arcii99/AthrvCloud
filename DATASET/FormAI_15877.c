//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>  
#include <stdlib.h> // for exit() function

int main()  
{  
    int num1, num2, result;  

    printf("Enter the first number: ");  
    scanf("%d", &num1);  

    printf("Enter the second number: ");  
    scanf("%d", &num2);  

    if(num2 == 0)  
    {  
        printf("Division by zero is not allowed...");
        exit(0); // exits the program if the second input number is zero
    }  
    else  
    {  
        result = num1 / num2;  
        printf("The result of division is : %d", result);  
    }  
  
    return 0;  
}