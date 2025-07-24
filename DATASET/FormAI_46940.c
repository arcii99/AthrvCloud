//FormAI DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(0));          // Seed for random number generation using current time 
    int num1 = rand() % 100;  // Generating random numbers within 100
    int num2 = rand() % 100;

    printf("Two random numbers generated are : %d and %d\n\n", num1, num2);

    printf("Addition of %d and %d is : %d\n", num1, num2, num1+num2);

    if(num1 > num2)
        printf("%d is greater than %d\n", num1, num2);
    else if(num2 > num1)
        printf("%d is greater than %d\n", num2, num1);
    else
        printf("%d is equal to %d\n", num1, num2);

    printf("Subtraction of %d and %d is : %d\n", num1, num2, num1-num2);

    if(num1 % num2 == 0)
        printf("%d is completely divisible by %d\n", num1, num2);
    else
        printf("%d is not completely divisible by %d\n", num1, num2);

    printf("Multiplication of %d and %d is : %d\n", num1, num2, num1*num2);

    if(num2 != 0)
        printf("Division of %d by %d is : %.2f\n", num1, num2, (float) num1/num2);
    else
        printf("Cannot divide %d by %d\n", num1, num2);

    printf("Modulus of %d and %d is : %d\n", num1, num2, num1%num2);

    return 0;
}