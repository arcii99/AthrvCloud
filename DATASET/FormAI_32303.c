//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

void printTriangle(int n) {
    if (n == 0) return;
    printTriangle(n-1);
    for (int i = 1; i <= n; i++) {
        printf("*");
    }
    printf("\n");
}

void towersOfHanoi(int n, int from, int to, int spare) {
    if (n == 1) {
        printf("Move disk from %d to %d\n", from, to);
    }
    else {
        towersOfHanoi(n-1, from, spare, to);
        towersOfHanoi(1, from, to, spare);
        towersOfHanoi(n-1, spare, to, from);
    }
}

int main() {
    // Calculate and print Fibonacci sequence up to the 10th number
    for (int i = 0; i <= 10; i++) {
        printf("%d ", fibonacci(i));
    }
    
    printf("\n");
    
    // Calculate and print factorials up to 10
    for (int i = 0; i <= 10; i++) {
        printf("%d ", factorial(i));
    }
    
    printf("\n");
    
    // Print a triangle of asterisks with 5 rows
    printTriangle(5);
    
    printf("\n");
    
    // Solve the Towers of Hanoi puzzle with 3 disks
    towersOfHanoi(3, 1, 3, 2);
    
    return 0;
}