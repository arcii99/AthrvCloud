//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

int main() {
    int numTerms, first = 0, second = 1, next;
    printf("Enter the number of terms to display in the Fibonacci sequence: ");
    scanf("%d", &numTerms);
    
    printf("Fibonacci sequence:\n");
    for(int i = 0; i < numTerms; i++) {
        if(i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
        
        // Visual representation of the current term
        for(int j = 0; j < next; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}