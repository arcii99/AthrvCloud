//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>

int main() {

    int n, t1 = 0, t2 = 1, nextNum;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    
    for (int i = 1; i <= n; ++i) {
        
        printf("%d, ", t1);
        
        nextNum = t1 + t2;
        t1 = t2;
        t2 = nextNum;
    }
    
    return 0;
}