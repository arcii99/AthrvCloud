//FormAI DATASET v1.0 Category: Recursive ; Style: content
#include <stdio.h>

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int num;
    printf("Enter a number to find the Fibonacci sequence up to: ");
    scanf("%d", &num);

    printf("Fibonacci sequence up to %d:\n", num);

    for(int i=0; i<=num; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}