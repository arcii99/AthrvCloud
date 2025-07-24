//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include<stdio.h>

int fibo(int n);

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    if(n<0){
        printf("Invalid input. Enter a positive integer.\n");
        return -1;
    }
    printf("The %dth term in the Fibonacci series is %d.",n,fibo(n));
    return 0;
}

int fibo(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return(fibo(n-1)+fibo(n-2));
}