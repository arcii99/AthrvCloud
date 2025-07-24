//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

int main() {
    int n, i, a = 0, b = 1, c;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci sequence:\n");
    
    if(n == 1) {
        printf("%d", a);
    }
    else if(n == 2) {
        printf("%d %d", a, b);
    }
    else {
        printf("%d %d ", a, b);
        
        for(i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
            printf("%d ", c);
        }
    }
    
    return 0;
}