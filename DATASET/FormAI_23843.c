//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>

int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;
    
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &n);
    
    printf("The Fibonacci sequence:\n");
    
    for(i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            printf(" |      ");
        } else {
            printf("  _      ");
        }
    }
    
    printf("\n");
    
    for(i = 1; i <= n; i++) {
        if(i == 1) {
            printf("%d", t1);
        } else if(i == 2) {
            printf("%d", t2);
        } else {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            printf("%d", nextTerm);
        }
        if(i % 2 == 0) {
            printf("| ");
        } else {
            printf(" ");
        }
    }

    return 0;
}