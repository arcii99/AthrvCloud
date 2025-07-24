//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod, quo, rem;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    rem = num1 % num2;
    
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The difference between %d and %d is %d.\n", num1, num2, diff);
    printf("The product of %d and %d is %d.\n", num1, num2, prod);
    
    if (num2 != 0) {
        printf("The quotient of %d divided by %d is %d with a remainder of %d.\n", num1, num2, quo, rem);
    } else {
        printf("Cannot perform division as second number is zero.\n");
    }
    
    printf("The absolute value of the difference between %d and %d is %d.\n", num1, num2, abs(diff));
    printf("The maximum of %d and %d is %d.\n", num1, num2, max(num1, num2));
    printf("The minimum of %d and %d is %d.\n", num1, num2, min(num1, num2));
    
    return 0;
}

int abs(int num) {
    return (num < 0) ? -num : num;
}

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int min(int num1, int num2) {
    return (num1 < num2) ? num1 : num2;
}