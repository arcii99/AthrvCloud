//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod, quo, mod;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    mod = num1 % num2;
    printf("%d + %d = %d\n", num1, num2, sum);
    printf("%d - %d = %d\n", num1, num2, diff);
    printf("%d * %d = %d\n", num1, num2, prod);
    printf("%d / %d = %d\n", num1, num2, quo);
    printf("%d %% %d = %d\n", num1, num2, mod);
    return 0;
}