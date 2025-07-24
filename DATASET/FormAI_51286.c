//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include<stdio.h>

int main() {
    int a = 7, b = 5, c;

    //Adding a and b
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);

    //Subtracting b from a
    c = a - b;
    printf("%d - %d = %d\n", a, b, c);

    //Multiplying a and b
    c = a * b;
    printf("%d * %d = %d\n", a, b, c);

    //Dividing a by b
    c = a / b;
    printf("%d / %d = %d\n", a, b, c);

    //Finding the remainder when a is divided by b
    c = a % b;
    printf("%d mod %d = %d\n", a, b, c);

    //Increasing the value of a by 1
    a++;
    printf("a after increment = %d\n", a);

    //Decreasing the value of b by 1
    b--;
    printf("b after decrement = %d\n", b);

    //Using shorthand operators to add 5 to a
    a += 5;
    printf("a after adding 5 = %d\n", a);

    //Using shorthand operators to subtract 2 from b
    b -= 2;
    printf("b after subtracting 2 = %d\n", b);

    //Negating the value of a
    a = -a;
    printf("a after negation = %d\n", a);

    return 0;
}