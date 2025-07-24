//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>

int main() {
    int length, i, first = 0, second = 1, next;
    
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &length);
    
    printf("Fibonacci Series: %d %d ", first, second);
    
    for (i = 2; i < length; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    
    return 0;
}