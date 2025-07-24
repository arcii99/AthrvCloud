//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

/* This program calculates the factorial of a number
   entered by the user using recursion */

int factorial(int n){
    if(n==0 || n==1){  // base case
        return 1;
    }
    else{  // recursive case
        return n*factorial(n-1);
    }
}

int main(){
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if(num>=0){  // check if input is non-negative
        printf("The factorial of %d is %d\n", num, factorial(num));
    }
    else{
        printf("Invalid input! Please enter a non-negative integer.\n");
    }

    return 0;
}