//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Recursive function to perform addition
int add(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return add(x ^ y, (x & y) << 1);
    }
}

// Recursive function to perform subtraction
int sub(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return sub(x ^ y, (~x & y) << 1);
    }
}

// Recursive function to perform multiplication
int mul(int x, int y) {
    if (x == 0 || y == 0) {
        return 0;
    } else if (y > 0) {
        return x + mul(x, y - 1);
    } else {
        return -mul(x, -y);
    }
}

// Recursive function to perform division
int divide(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero!");
        return 0;
    } else if (x == 0 || x < y) {
        return 0;
    } else {
        return 1 + divide(x - y, y);
    }
}

int main() {
    int a = 10, b = 5;
    printf("Addition of %d and %d is %d\n", a, b, add(a, b));
    printf("Subtraction of %d and %d is %d\n", a, b, sub(a, b));
    printf("Multiplication of %d and %d is %d\n", a, b, mul(a, b));
    printf("Division of %d by %d is %d\n", a, b, divide(a, b));
    return 0;
}