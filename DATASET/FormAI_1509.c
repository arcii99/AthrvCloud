//FormAI DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, product, quotient, remainder;
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    diff = (num1 > num2) ? num1 - num2 : num2 - num1;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("\n\n");
    printf("---------------------------\n");
    printf("Mind-bending Arithmetic\n");
    printf("---------------------------\n");
    printf("         ______ \n");
    printf("        /      \\\n");
    printf("       /        \\\n");
    printf("      /__________\\\n");
    printf("      |          |\n");
    printf("      |          |\n");
    printf("      |  __  __  |\n");
    printf("      | |  ||  | |\n");
    printf("      | |__||__| |\n");
    printf("      | " "%d" "  | " "%d" " |\n", num1, num2);
    printf("      |__________|\n");
    printf("\n\n");
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);
    printf("\n\n");
    printf("The absolute difference between %d and %d is: %d\n", num1, num2, diff);
    printf("\n\n");
    printf("The product of %d and %d is: %d\n", num1, num2, product);
    printf("\n\n");
    printf("The quotient of %d and %d is: %d\n", num1, num2, quotient);
    printf("\n\n");
    printf("The remainder of %d divided by %d is: %d\n", num1, num2, remainder);
    return 0;
}