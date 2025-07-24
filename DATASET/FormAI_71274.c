//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include<stdio.h>

int fib(int n){
    if(n==1 || n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("The %dth Fibonacci number is %d\n",n,fib(n));
    return 0;
}