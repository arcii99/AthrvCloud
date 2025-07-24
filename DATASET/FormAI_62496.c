//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int factorial(int n);

int main() {
    int num;
    
    printf("Please enter a positive integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Error: Invalid input\n");
        return 1;
    }
    
    printf("%d! = %d\n", num, factorial(num));
    
    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}