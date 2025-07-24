//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    int a, b, c, d, e, f;

    printf("Enter six numbers:\n");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    int sum = a + b + c + d + e + f;
    int product = a * b * c * d * e * f;

    printf("The sum of the numbers is: %d\n", sum);
    printf("The product of the numbers is: %d\n", product);

    int quotient = sum / product;

    printf("The quotient of the sum and product is: %d\n", quotient);

    int remainder = sum % product;

    printf("The remainder of the sum and product is: %d\n", remainder);

    printf("Thank you for using this program!\n");

    return 0;
}