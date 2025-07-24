//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: minimalist
#include <stdio.h>

int main() {
    
    int num1 = 0, num2 = 1, nextNum = 0, numTerms = 0, i = 0;
    
    printf("Enter the number of terms in the Fibonacci sequence to be displayed: ");
    scanf("%d", &numTerms);
    
    printf("\nFibonacci sequence for %d terms:\n", numTerms);
    
    while (i < numTerms) {
        
        if (i <= 1) {
            nextNum = i;
        } else {
            nextNum = num1 + num2;
            num1 = num2;
            num2 = nextNum;
        }
        
        for (int j = 0; j <= nextNum; j++) {
            printf("#");
        }
        
        printf("\n");
        
        i++;
    }
    
    return 0;
}