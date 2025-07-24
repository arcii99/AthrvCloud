//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main(){
    int divisible, divisor, quotient;
    printf("Enter the divisible and divisor: ");
    scanf("%d %d", &divisible, &divisor);
    if(divisor == 0){
        fprintf(stderr, "Division by zero is not possible!\n");
        exit(1); //exit with error code 1
    }
    else{
        quotient = divisible / divisor;
        printf("Quotient of %d divided by %d is %d\n", divisible, divisor, quotient);
    }
    return 0;
}