//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

// function to calculate the sum of squares of n numbers
int sum_of_squares(int n){
    int i, sum=0;
    for(i=1; i<=n; i++){
        sum += i*i;
    }
    return sum;
}

// function to calculate the factorial of a number
int factorial(int n){
    int i, fact=1;
    for(i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

// main function
int main(){
    int n, choice;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("\n1. Calculate Sum of Squares of n Numbers\n2. Calculate Factorial of n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("\nThe Sum of Squares of %d Numbers is %d\n", n, sum_of_squares(n));
            break;
        case 2:
            printf("\nThe Factorial of %d is %d\n", n, factorial(n));
            break;
        default:
            printf("\nInvalid Choice. Program Terminated.");
            exit(0);
    }
    return 0;
}