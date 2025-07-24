//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    float result;

    printf("Enter values for a, b, c, d, e and f: \n");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    // perform arithmetic operations
    result = ((float)a / b) * (c + (d % e)) - f;

    // display the result
    printf("The result of the arithmetic operation is: %.2f\n", result);

    return 0;
}