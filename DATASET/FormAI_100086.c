//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;
    for(int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;
    printf("Enter the number of terms to be printed: ");
    scanf("%d", &n);
    if(n <= 0) {
        printf("Number of terms should be greater than 0.\n");
        return 0;
    }
    printf("The Fibonacci sequence is: ");
    fibonacci(n);
    return 0;
}