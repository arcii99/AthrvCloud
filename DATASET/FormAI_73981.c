//FormAI DATASET v1.0 Category: Recursive ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

/*This is a recursive function that calculates the factorial of a given number using an iterative approach*/
int factorial_iterative(int n){
    int i,fact=1;
    for(i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

/*This is a recursive function that calculates the factorial of a given number using a recursive approach*/
int factorial_recursive(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial_recursive(n-1); //Recursive call to the function itself
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial of %d using iterative approach: %d\n",n,factorial_iterative(n));
    printf("Factorial of %d using recursive approach: %d\n",n,factorial_recursive(n));
    return 0;
}