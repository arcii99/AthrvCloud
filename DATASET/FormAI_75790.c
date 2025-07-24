//FormAI DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>

int fib_recursive(int n){
    //fibonacci series using recursion
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return (fib_recursive(n-1) + fib_recursive(n-2));
}

int main(){
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for(i = 0; i < n; i++){
        printf("%d ", fib_recursive(i));
    }

    return 0;
}