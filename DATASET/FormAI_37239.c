//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n < 0) {
        printf("Can't compute a factorial for negative numbers, what do you think I am, a miracle worker?\n");
        exit(1);
    }
    
    if (n == 0) {
        return 1;
    }
    
    return n * factorial(n-1);
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("%d! = %d\n", num, result);
    
    return 0;
}