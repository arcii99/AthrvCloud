//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    printf("Enter the number of Fibonacci terms to display: ");
    scanf("%d", &n);
    
    printf("Here are the first %d Fibonacci numbers:\n", n);
    
    for (int i = 0; i < n; i++) {
        int term = fibonacci(i);
        printf("%d ", term);
        for (int j = 0; j < term; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}