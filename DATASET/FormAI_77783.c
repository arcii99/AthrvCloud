//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include<stdio.h>

int factorial(int n);

int main(){
    int n;
    printf("Enter the number to find factorial: ");
    scanf("%d", &n);
    int result = factorial(n);
    printf("Factorial of %d is %d", n, result);
    return 0;
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}