//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include<stdio.h>

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    printf("Enter the number of terms for Fibonacci Series: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}