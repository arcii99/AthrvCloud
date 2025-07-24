//FormAI DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

/* This program generates a Fibonacci sequence */

int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;
    
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);
    
    printf("Fibonacci sequence:\n");
    
    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    
    return 0;
}