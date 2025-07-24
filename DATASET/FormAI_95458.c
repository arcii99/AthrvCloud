//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num1, num2, sum, diff, prod;
    float quo;
    printf("Welcome to my Arithmetic Calculator \n");
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    sum = num1+num2;
    diff = num1-num2;
    prod = num1*num2;
    if(num2 == 0){
        printf("Cannot divide by zero. \n");
        exit (0);
    }
    else{
        quo= (float)num1/num2;
    }
    printf("Sum: %d \n", sum);
    printf("Difference: %d \n", diff);
    printf("Product: %d \n", prod);
    printf("Quotient: %.2f \n", quo);
    if(num1 > num2){
        printf("%d is greater than %d \n", num1, num2);
    }
    else if(num1 < num2){
        printf("%d is less than %d \n", num1, num2);
    }
    else{
        printf("Both numbers are equal. \n");
    }
    return 0;
}