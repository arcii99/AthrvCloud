//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>

int main() {
    int x, y, z;
    printf("Welcome to the Medieval Calculator!\n");
    printf("Enter two numbers to add, separated by a space: ");
    scanf("%d %d", &x, &y);
    z = x + y;
    printf("The sum of %d and %d is %d.\n", x, y, z);
    printf("Now let's subtract. Enter two numbers to subtract, separated by a space: ");
    scanf("%d %d", &x, &y);
    z = x - y;
    printf("The difference between %d and %d is %d.\n", x, y, z);
    printf("Next we shall multiply. Enter two numbers to multiply, separated by a space: ");
    scanf("%d %d", &x, &y);
    z = x * y;
    printf("The product of %d and %d is %d.\n", x, y, z);
    printf("Finally, let's divide. Enter two numbers to divide, separated by a space: ");
    scanf("%d %d", &x, &y);
    z = x / y;
    printf("The quotient of %d and %d is %d.\n", x, y, z);
    printf("Thanks for using the Medieval Calculator!\n");
    return 0;
}