//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Hey there! Let's play an exciting game where you have to enter three numbers and I will then perform some calculations on them!\n");
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);
    printf("You entered %d, %d, and %d. Let's see what I can do!\n", a, b, c);

    int max = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    printf("The maximum number is: %d\n", max);

    int min = (a < b) ? (a < c ? a : c) : (b < c ? b : c);
    printf("The minimum number is: %d\n", min);

    float avg = (a + b + c) / 3.0;
    printf("The average of the numbers is: %.2f\n", avg);

    int sum = a + b + c;
    printf("The sum of the numbers is: %d\n", sum);

    int prod = a * b * c;
    printf("The product of the numbers is: %d\n", prod);

    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        printf("The numbers can form a valid triangle!\n");
    }
    else {
        printf("The numbers cannot form a valid triangle!\n");
    }

    if ((a == b) && (b == c)) {
        printf("The numbers form an equilateral triangle!\n");
    }
    else if ((a == b) || (b == c) || (a == c)) {
        printf("The numbers form an isosceles triangle!\n");
    }
    else {
        printf("The numbers form a scalene triangle!\n");
    }

    printf("Thank you for playing! Come again soon.\n");
    return 0;
}