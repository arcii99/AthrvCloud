//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include<stdio.h>

int main(){
    int num1, num2, sum, diff, prod;
    float quo;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    //Performing arithmetic operations
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    //Checking if division is possible
    if(num2 != 0){
        quo = (float)num1 / num2;
    }
    else{
        printf("Division is not possible.\n");
        return 0;
    }

    //Printing results
    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", diff);
    printf("Product = %d\n", prod);
    printf("Quotient = %.2f\n", quo);

    return 0;
}