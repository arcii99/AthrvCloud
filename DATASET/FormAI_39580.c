//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    printf("Enter two numbers to divide: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("[ERROR] Invalid input! Aborting program...");
        exit(1);
    }

    if (b == 0) {
        printf("[ERROR] Division by zero! Please enter a non-zero divisor...");
        printf("\nEnter the divisor: ");
        if (scanf("%d", &b) != 1 || b == 0) {
            printf("[ERROR] Invalid input! Aborting program...");
            exit(1);
        }
    }

    c = a / b;
    printf("%d divided by %d equals %d\n", a, b, c);

    return 0;
}