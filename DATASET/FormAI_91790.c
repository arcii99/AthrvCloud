//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

int recursiveMultiply(int, int);
int recursiveSubtract(int, int);
int recursiveDivide(int, int);
int recursiveMod(int, int);

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Multiplication: %d\n", recursiveMultiply(a, b));
    printf("Subtraction: %d\n", recursiveSubtract(a, b));
    printf("Division: %d\n", recursiveDivide(a, b));
    printf("Modulus: %d\n", recursiveMod(a, b));
    return 0;
}

int recursiveMultiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    else {
        return a + recursiveMultiply(a, b - 1);
    }
}

int recursiveSubtract(int a, int b) {
    if (b < 0) {
        return recursiveSubtract(a, -b);
    }
    else if (b == 0) {
        return a;
    }
    else {
        return recursiveSubtract(a - 1, b - 1);
    }
}

int recursiveDivide(int a, int b) {
    if (b == 0) {
        printf("Error: divide by zero.\n");
        return;
    }
    else if (a < b) {
        return 0;
    }
    else {
        return 1 + recursiveDivide(a - b, b);
    }
}

int recursiveMod(int a, int b) {
    if (b == 0) {
        printf("Error: divide by zero.\n");
        return;
    }
    else if (a < b) {
        return a;
    }
    else {
        return recursiveMod(a - b, b);
    }
}