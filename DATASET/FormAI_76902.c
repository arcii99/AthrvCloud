//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
#include <stdio.h>

int main() {
    
    int n, a = 0, b = 1, sum = 0;
    
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    // Visualize the first two terms as 0 and 1
    printf("\nFibonacci Sequence:\n %d\t%d", a, b);
    
    for(int i=3; i<=n; i++) {
        sum = a + b;
        a = b;
        b = sum;
        
        // Visualize the next term in the sequence
        printf("\t%d", sum);
        
        // To avoid overflow, break if sum exceeds the maximum int value
        if(sum < 0) {
            printf("\n\nInteger overflow occurred. Program terminated.\n");
            return 1;
        }
    }
    
    printf("\n");
    
    return 0;
}