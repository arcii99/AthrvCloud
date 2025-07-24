//FormAI DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) { // base case
        return 1;
    } else { // recursive case
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    
    printf("Enter a positive integer to find its factorial: ");
    scanf("%d", &num);
    
    if (num < 0) { // validation check for negative numbers
        printf("Invalid Input\n");
        return 0;
    } else {
        int result = factorial(num);
        printf("%d! = %d\n", num, result);
    }
    
    return 0;
}