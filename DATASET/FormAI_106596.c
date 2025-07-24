//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include<stdio.h>
#include<string.h>

void divide(int divisor, int dividend){
    if(dividend == 0){
        printf("Division by zero error\n");
        return;
    }
    int quotient = divisor/dividend;
    if(divisor % dividend != 0){
        printf("The remainder is %d\n", divisor % dividend);
        divide(dividend, divisor % dividend);
    }
    else{
        printf("The quotient is %d\n", quotient);
    }
}

int main(){
    int divisor, dividend;
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    divide(divisor, dividend);
    return 0;
}