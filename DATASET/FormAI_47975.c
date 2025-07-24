//FormAI DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: \n");
    scanf("%d %d", &num1, &num2);

    printf("\n");

    if (num1 % 2 == 0 && num2 % 2 == 0) {
        printf("%d and %d are even numbers.\n", num1, num2);
        printf("The sum of these two numbers is: %d\n", num1+num2);
    } else if (num1 % 2 == 0 && num2 % 2 != 0) {
        printf("%d is an even number but %d is an odd number.\n", num1, num2);
        printf("The difference between %d and %d is: %d\n", num1, num2, num1-num2);
    } else if (num1 % 2 != 0 && num2 % 2 == 0) {
        printf("%d is an odd number but %d is an even number.\n", num1, num2);
        printf("The difference between %d and %d is: %d\n", num2, num1, num2-num1);
    } else {
        printf("%d and %d are odd numbers.\n", num1, num2);
        printf("The multiplication of these two numbers is: %d\n", num1*num2);
    }

    printf("\n");

    return 0;
}