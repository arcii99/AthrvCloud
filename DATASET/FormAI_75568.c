//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    } else {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d",&n);
    printf("\nFibonacci series for the first %d terms:\n",n);
    for(i=0; i<n; i++) {
        printf("%d\t", fibonacci(i));
    }
    printf("\n");
    return 0;
}