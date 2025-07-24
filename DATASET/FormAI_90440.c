//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>

int main() {
    // Enter the cyber world of C-syntax parsing
    printf("Welcome to the cyber world of C-syntax parsing!\n");

    // Declare variables
    int x, y, z;

    // Prompt user for input and scan for variables
    printf("Enter three integers separated by spaces: ");
    scanf("%d %d %d", &x, &y, &z);

    // Check if x is positive
    if (x > 0) {
        printf("x is positive! ");
    }

    // Check if y is negative
    if (y < 0) {
        printf("y is negative! ");
    }

    // Check if z is even
    if (z % 2 == 0) {
        printf("z is even! ");
    }

    // Check if x is greater than y and z
    if (x > y && x > z) {
        printf("x is the largest integer entered!");
    }

    // Check if x is less than y and z
    if (x < y && x < z) {
        printf("x is the smallest integer entered!");
    }

    // End program
    printf("\nThank you for parsing the syntax in the cyber world of C!\n");
    return 0;
}