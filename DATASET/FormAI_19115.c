//FormAI DATASET v1.0 Category: Math exercise ; Style: decentralized
#include<stdlib.h>
#include<stdio.h>

int main(){
    int num1, num2, sum=0, subtract, multiply=1, divide;

    printf("Enter any two numbers: ");

    // Take input from user
    scanf("%d%d", &num1, &num2);
    printf("\nYou entered: %d and %d", num1, num2);

    // Calculate sum of num1 and num2
    sum = num1 + num2;
    printf("\nThe sum of %d and %d is: %d", num1, num2, sum);

    // Calculate subtraction of num1 and num2
    subtract = num1 - num2;
    printf("\nThe subtraction of %d from %d is: %d", num2, num1, subtract);

    // Calculate multiplication of num1 and num2
    for(int i=1; i<=num2;i++){
        multiply *= num1;
    }
    printf("\nThe multiplication of %d and %d is: %d", num1, num2, multiply);

    // Calculate division of num1 and num2
    if(num2!=0){
        divide = num1/num2;
        printf("\nThe division of %d by %d is: %d", num1, num2, divide);
    } 
    else{
        printf("\nDivide by zero error!!!");
    }

    return 0;
}