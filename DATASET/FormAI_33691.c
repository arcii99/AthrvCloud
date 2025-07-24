//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

int factorial(int n) {
    if(n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    
    printf("Please enter a positive integer to calculate its factorial: ");
    scanf("%d", &num);
    
    if(num < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
    }
    else {
        int result = factorial(num);
        printf("%d! = %d\n", num, result);
    }
    
    return 0;
}