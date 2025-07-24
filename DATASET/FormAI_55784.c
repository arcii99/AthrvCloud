//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

int fib(int n){
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n, i;
    printf("Enter the number of terms you want in Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci Series:\n");
    for(i=0; i<n; i++){
        printf("%d ", fib(i));
    }
    return 0;
}