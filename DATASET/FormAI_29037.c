//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>

// Modular Functions
int calculateSum(int a, int b);
int calculateProduct(int a, int b);
int calculateDifference(int a, int b);

int main() {
    int x = 5, y = 3;
    int sum = calculateSum(x, y);
    int product = calculateProduct(x, y);
    int difference = calculateDifference(x, y);
    
    printf("The sum of %d and %d is %d\n", x, y, sum);
    printf("The product of %d and %d is %d\n", x, y, product);
    printf("The difference of %d and %d is %d\n", x, y, difference);
    
    return 0;
}

int calculateSum(int a, int b) {
    return a + b;
}

int calculateProduct(int a, int b) {
    return a * b;
}

int calculateDifference(int a, int b) {
    return a - b;
}