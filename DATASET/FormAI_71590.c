//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>

int main() {
    int num1 = 5, num2 = 10;
    printf("Before swapping:\n");
    printf("Num1 = %d, Num2 = %d\n\n", num1, num2);

    printf("Swapping...\n\n");

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("After swapping:\n");
    printf("Num1 = %d, Num2 = %d\n\n", num1, num2);

    printf("Let's do some math operations!\n");
    int a = 5, b = 7;
    printf("a = %d, b = %d\n", a, b);

    int sum = a + b;
    printf("Sum of a and b = %d\n", sum);

    int difference = a - b;
    printf("Difference of a and b = %d\n", difference);

    int product = a * b;
    printf("Product of a and b = %d\n", product);

    int quotient = a / b;
    printf("Quotient of a and b (integer division) = %d\n", quotient);

    float dividend = (float) a / b;
    printf("Quotient of a and b (floating point division) = %f\n", dividend);

    printf("Now, let's see how many digits we can print!\n");
    int long_num = 123456789;
    printf("Printing a long number = %d\n", long_num);

    printf("Representing the long number in different bases:\n");
    printf("In octal = %o\n", long_num);
    printf("In hexadecimal = %x\n", long_num);

    printf("Let's do some logic operations!\n");
    int boolean1 = 1, boolean2 = 0;

    printf("Boolean1 = %d, Boolean2 = %d\n", boolean1, boolean2);
    printf("Boolean1 AND Boolean2 = %d\n", boolean1 && boolean2);
    printf("Boolean1 OR Boolean2 = %d\n", boolean1 || boolean2);
    printf("NOT Boolean1 = %d, NOT Boolean2 = %d\n\n", !boolean1, !boolean2);

    printf("Phew! That was a lot of fun!\n");
    return 0;
}