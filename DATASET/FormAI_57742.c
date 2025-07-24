//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Fibonacci Series up to %d:\n", n);

    for (int i = 1; i <= n; ++i) {
        if(i == 1) {
            printf("%d, ", t1);
            continue;
        }
        if(i == 2) {
            printf("%d, ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        if(nextTerm > n)
            break;

        printf("%d, ", nextTerm);
    }
    return 0;
}