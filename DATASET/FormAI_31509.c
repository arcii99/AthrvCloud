//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
/*
 * Written by [Your Name]
 * This program demonstrates the use of pointers in C.
 */

#include <stdio.h>

int main() {
    int num1, num2, *p1, *p2, sum;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    p1 = &num1;
    p2 = &num2;

    sum = *p1 + *p2;

    printf("The sum of %d and %d is %d\n", *p1, *p2, sum);

    return 0;
}