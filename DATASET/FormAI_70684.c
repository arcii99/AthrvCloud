//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, result;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) { //Check if scanf returns 2
        fprintf(stderr, "Error: Invalid input. Please enter two integers separated by a space.\n");
        exit(1);
    }
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(1);
    }
    result = a / b;
    printf("%d / %d = %d\n", a, b, result);
    return 0;
}