//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

int factorial(int n){
    if(n<0){
        printf("Negative numbers do not have a factorial. Exiting program...\n");
        exit(EXIT_FAILURE);
    }
    else if(n==0){
        printf("Factorial of 0 is 1 because maths says so. \n");
        return 1;
    }
    else{
        int fact=n*factorial(n-1);
        printf("%d! = %d\n",n,fact);
        return fact;
    }
}

int main(){
    printf("Welcome to the factorial calculator! Enter a non-negative integer to get its factorial: \n");
    int num;
    scanf("%d",&num);
    factorial(num);
    return 0;
}