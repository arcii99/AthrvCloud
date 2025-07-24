//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include<stdio.h>

int main(){

    // Displaying the program name
    printf("This is a factorial calculator program in C.\n");

    // Taking input from user
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d",&num);

    // Checking if the number is negative
    if(num < 0){
        printf("Error: Factorial of a negative number doesn't exist.\n");
        return 0;
    }

    // Calculating factorial of a number
    int factorial = 1;
    for(int i=1; i<=num; i++){
        factorial *= i;
    }

    // Displaying the result
    printf("Factorial of %d is %d\n", num, factorial);

    return 0;
}