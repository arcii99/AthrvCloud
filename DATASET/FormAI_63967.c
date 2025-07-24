//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <math.h>

int main() {

// Displaying the Options
printf("Welcome to Retro Scientific Calculator\n");
printf("=====================================\n");
printf("Choose the Operation you want to Perform\n");
printf("1. Addition\n");
printf("2. Subtraction\n");
printf("3. Multiplication\n");
printf("4. Division\n");
printf("5. Power\n");
printf("6. Square Root\n");
printf("7. Sine\n");
printf("8. Cosine\n");
printf("9. Tangent\n");
printf("0. Exit\n");

// Reading the User's Choice
int choice;
printf("Enter your Choice: ");
scanf("%d", &choice);

// Switch Case for the Operations
switch (choice) {
case 1: {
    // Addition
    float num1, num2;
    printf("Enter 1st Number: ");
    scanf("%f", &num1);
    printf("Enter 2nd Number: ");
    scanf("%f", &num2);
    printf("Result: %.2f\n", num1 + num2);
    break;
}
case 2: {
    // Subtraction
    float num1, num2;
    printf("Enter 1st Number: ");
    scanf("%f", &num1);
    printf("Enter 2nd Number: ");
    scanf("%f", &num2);
    printf("Result: %.2f\n", num1 - num2);
    break;
}
case 3: {
    // Multiplication
    float num1, num2;
    printf("Enter 1st Number: ");
    scanf("%f", &num1);
    printf("Enter 2nd Number: ");
    scanf("%f", &num2);
    printf("Result: %.2f\n", num1 * num2);
    break;
}
case 4: {
    // Division
    float num1, num2;
    printf("Enter 1st Number: ");
    scanf("%f", &num1);
    printf("Enter 2nd Number: ");
    scanf("%f", &num2);
    if (num2 == 0) {
        printf("Cannot divide by 0\n");
    } else {
        printf("Result: %.2f\n", num1 / num2);
    }
    break;
}
case 5: {
    // Power
    float num1, num2;
    printf("Enter Base: ");
    scanf("%f", &num1);
    printf("Enter Exponent: ");
    scanf("%f", &num2);
    printf("Result: %.2lf\n", pow(num1, num2));
    break;
}
case 6: {
    // Square Root
    float num;
    printf("Enter a Number: ");
    scanf("%f", &num);
    printf("Result: %.2f\n", sqrt(num));
    break;
}
case 7: {
    // Sine
    float num;
    printf("Enter a Number in Degrees: ");
    scanf("%f", &num);
    printf("Result: %.2f\n", sin(num * M_PI / 180));
    break;
}
case 8: {
    // Cosine
    float num;
    printf("Enter a Number in Degrees: ");
    scanf("%f", &num);
    printf("Result: %.2f\n", cos(num * M_PI / 180));
    break;
}
case 9: {
    // Tangent
    float num;
    printf("Enter a Number in Degrees: ");
    scanf("%f", &num);
    printf("Result: %.2f\n", tan(num * M_PI / 180));
    break;
}
case 0: {
    // Exit
    printf("Thank you for using Retro Scientific Calculator\n");
    break;
}
default:
    printf("Invalid Choice\n");
}

return 0;
}