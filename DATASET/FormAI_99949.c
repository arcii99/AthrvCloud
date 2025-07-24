//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    if (scanf("%d%d", &num1, &num2) != 2) {
        fprintf(stderr, "Error: Invalid input.\n");
        exit(1);
    }

    if (num2 == 0) {
        fprintf(stderr, "Error: Division by zero.\n");
        exit(1);
    }

    printf("%d / %d = %f\n", num1, num2, (float)num1 / num2);

    return 0;
}