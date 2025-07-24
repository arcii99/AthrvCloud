//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    printf("Enter two integers to divide: ");
    scanf("%d %d", &num1, &num2);

    if (num2 == 0) {
        fprintf(stderr, "Error: Cannot divide by zero\n");
        exit(1);
    }

    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}