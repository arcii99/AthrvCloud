//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include <stdio.h>

int main()
{
    int a, b, sum, dif, pro, quo;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    sum = a + b;
    dif = a - b;
    pro = a * b;
    quo = a / b;

    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", dif);
    printf("Product = %d\n", pro);
    printf("Quotient = %d\n", quo);

    return 0;
}