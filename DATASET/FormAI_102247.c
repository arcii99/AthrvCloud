//FormAI DATASET v1.0 Category: Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Welcoming message
    printf("Welcome to the Energetic Calculator! \n");

    // Asking for input
    printf("Please enter the first number: ");
    double num1;
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    double num2;
    scanf("%lf", &num2);

    // Performing addition
    double sum = num1 + num2;
    printf("The sum of %.2lf and %.2lf is %.2lf \n", num1, num2, sum);

    // Performing subtraction
    double difference = num1 - num2;
    printf("The difference between %.2lf and %.2lf is %.2lf \n", num1, num2, difference);

    // Performing multiplication
    double product = num1 * num2;
    printf("The product of %.2lf and %.2lf is %.2lf \n", num1, num2, product);

    // Performing division
    double quotient = num1 / num2;
    printf("The quotient of %.2lf and %.2lf is %.2lf \n", num1, num2, quotient);

    // Performing modulus calculation
    double modulus = fmod(num1, num2);
    printf("The modulus of %.2lf and %.2lf is %.2lf \n", num1, num2, modulus);

    // Performing power calculation
    double power = pow(num1, num2);
    printf("%.2lf to the power of %.2lf is %.2lf \n", num1, num2, power);

    // Closing message
    printf("Thank you for using the Energetic Calculator! \n");

    return 0;
}