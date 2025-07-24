//FormAI DATASET v1.0 Category: Arithmetic ; Style: unmistakable
#include <stdio.h>

int main() {
    int x = 20;
    int y = 10;
    int sum = x + y;
    int sub = x - y;
    int mul = x * y;
    float div = (float)x / y;

    printf("x = %d, y = %d\n", x, y);
    printf("x + y = %d\n", sum);
    printf("x - y = %d\n", sub);
    printf("x * y = %d\n", mul);
    printf("x / y = %.2f\n", div);

    int i, j;
    printf("\n");
    printf("Multiplication Table: \n");
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }

    int num, factorial = 1;
    printf("\n");
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial of negative numbers doesn't exist.");
    else {
        for (i = 1; i <= num; i++) {
            factorial *= i;
        }
        printf("Factorial of %d is %d.\n", num, factorial);
    }

    return 0;
}