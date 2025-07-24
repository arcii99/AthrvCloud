//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include<stdio.h>

int main(){

    int num1, num2, result;

    printf("Enter any two numbers:\n");
    scanf("%d %d",&num1,&num2);

    printf("\nThe two numbers in binary are:\n");
    printf("%d in binary is: ", num1);
    binary(num1);
    printf("%d in binary is: ", num2);
    binary(num2);

    printf("\n\n");

    result = num1 & num2;
    printf("The result of AND operation between %d and %d is: %d\n", num1, num2, result);

    printf("%d in binary is: ", result);
    binary(result);
    printf("\n\n");

    result = num1 | num2;
    printf("The result of OR operation between %d and %d is: %d\n", num1, num2, result);

    printf("%d in binary is: ", result);
    binary(result);
    printf("\n\n");

    result = num1 ^ num2;
    printf("The result of XOR operation between %d and %d is: %d\n", num1, num2, result);

    printf("%d in binary is: ", result);
    binary(result);
    printf("\n\n");

    result = ~num1;
    printf("The result of NOT operation on %d is: %d\n", num1, result);

    printf("%d in binary is: ", result);
    binary(result);
    printf("\n\n");

    result = num1 << 2;
    printf("The result of LEFT SHIFT operation on %d by 2 is: %d\n", num1, result);

    printf("%d in binary is: ", result);
    binary(result);
    printf("\n\n");

    result = num1 >> 2;
    printf("The result of RIGHT SHIFT operation on %d by 2 is: %d\n", num1, result);

    printf("%d in binary is: ", result);
    binary(result);
    printf("\n\n");

    return 0;
}

void binary(int n){
    int i;
    for(i=31; i>=0; i--){
        if((n>>i) & 1){
            printf("1");
        }
        else{
            printf("0");
        }
    }
}