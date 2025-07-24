//FormAI DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>

int gcd(int num1, int num2) {
    if(num1 == 0) return num2;
    return gcd(num2 % num1, num1);
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    int result = gcd(num1, num2);
    printf("GCD of %d and %d is %d\n", num1, num2, result);
    return 0;
}