//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surprised
#include <stdio.h>

int main() {
    int num, i, term1 = 0, term2 = 1, nextTerm;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Fibonacci Sequence up to %d:\n", num);
    
    // first two terms are always 0 and 1
    printf("%d, %d, ", term1, term2);
    
    for (i = 3; i <= num; i++) {
        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;
        
        if (nextTerm % 2 == 0) {
            printf("Woah! %d, ", nextTerm);
        } else {
            printf("%d, ", nextTerm);
        }
    }
    
    printf("That's all! Ain't Fibonacci amazing?");
    
    return 0;
}