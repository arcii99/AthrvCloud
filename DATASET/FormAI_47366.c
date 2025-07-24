//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {
    int a, b, c, d, e;
    printf("Welcome to my cheerful arithmetic program!\n");
    printf("Enter five integers: \n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int sum = a + b + c + d + e;
    int product = a * b * c * d * e;
    int quotient = a / b / c / d / e;
    int difference1 = a - b - c;
    int difference2 = d - e;
    int difference = difference1 - difference2;
    int remainder = a % b % c % d % e;

    printf("The sum of the five numbers is: %d\n", sum);
    printf("The product of the five numbers is: %d\n", product);
    printf("The quotient of the five numbers is: %d\n", quotient);
    printf("The difference of the first three numbers minus the difference of the last two numbers is: %d\n", difference);
    printf("The remainder of the five numbers when divided is: %d\n", remainder);

    printf("\nThank you for using my cheerful arithmetic program!\n");
    return 0;
}