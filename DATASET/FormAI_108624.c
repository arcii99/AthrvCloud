//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include<stdio.h>

int factorial(int n){
    int result;
    if (n == 1){
        result = 1;
    }
    else {
        result = n * factorial(n-1);
    }
    return result;
}

int main(){
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    while (num < 0){
        printf("Factorial of negative numbers cannot be found. Please enter a positive integer: ");
        scanf("%d", &num);
    }
    int fact = factorial(num);
    printf("%d! is equal to %d", num, fact);
    return 0;
}