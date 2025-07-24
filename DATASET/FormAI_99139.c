//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int main() {
    printf("Welcome to the Arithmetic Magic!\n");
    printf("Enter two numbers to do some magic on them:\n");

    // Reading the input numbers from the user
    float num1, num2;
    scanf("%f %f", &num1, &num2);

    // Performing some basic arithmetic operations on the numbers
    float sum = num1 + num2;
    float diff = num1 - num2;
    float prod = num1 * num2;
    float quo = num1 / num2;

    // Displaying the results in a magical manner
    printf("\n");

    // Sum of the two numbers
    printf("The magical sum of %.2f and %.2f is %.2f\n", num1, num2, sum);
    printf("%c %c %c %c %c\n", '|', '|', '|', '|', '|');
    printf("%c %.2f %c\n", '|', sum, '|');
    printf("%c %c %c %c %c\n", '|', '|', '|', '|', '|');
    printf("\n");

    // Difference of the two numbers
    printf("The magical difference between %.2f and %.2f is %.2f\n", num1, num2, diff);
    printf("%c %c\n", '|', '|');
    printf("%c %.2f %c\n", '|', diff, '|');
    printf("%c %c\n", '|', '|');
    printf("\n");

    // Product of the two numbers
    printf("The magical product of %.2f and %.2f is %.2f\n", num1, num2, prod);
    printf("%c %c %c %c\n", '/', '/', '/', '/');
    printf("%c %.2f %c\n", '|', prod, '|');
    printf("%c %c %c %c\n", '\\', '\\', '\\', '\\');
    printf("\n");

    // Quotient of the two numbers
    printf("The magical quotient of %.2f and %.2f is %.2f\n", num1, num2, quo);
    printf("%c %c\n", '_', '_');
    printf("%c %.2f %c\n", '|', quo, '|');
    printf("%c %c\n", '-', '-');

    return 0;
}