//FormAI DATASET v1.0 Category: Recursive ; Style: secure
#include<stdio.h>

int factorial(int n);

int main(){

    int num;

    printf("Enter an integer to find its factorial: ");
    scanf("%d",&num);

    while(num<0){
        printf("Factorial of negative integers is not defined.\nEnter a non-negative integer: ");
        scanf("%d",&num);
    }

    printf("Factorial of %d is %d",num,factorial(num));

    return 0;
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}