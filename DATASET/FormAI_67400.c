//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void peaceful_recursion(int n) {
    if(n == 0) {
        printf("0 is a peaceful number.\n");
        return;
    }
    else if(n < 0) {
        printf("Negative numbers are not peaceful...\n");
        return;
    }

    printf("%d is ", n);
    if(n % 2 == 0) {
        printf("even, so divide by 2: ");
        peaceful_recursion(n/2);
    }
    else {
        printf("odd, so multiply by 3 and add 1: ");
        peaceful_recursion(3*n+1);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    peaceful_recursion(n);

    return 0;
}