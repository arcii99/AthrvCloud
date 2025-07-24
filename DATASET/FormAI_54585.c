//FormAI DATASET v1.0 Category: Scientific ; Style: recursive
#include<stdio.h>

//Function to calculate the factorial of a number
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

//Function to calculate the nth fibonacci number
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));
    printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));
    return 0;
}