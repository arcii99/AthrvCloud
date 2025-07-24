//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to add two numbers
double add(double x, double y) {
    return x + y;
}

// Function to subtract two numbers
double subtract(double x, double y) {
    return x - y;
}

// Function to multiply two numbers
double multiply(double x, double y) {
    return x * y;
}

// Function to divide two numbers
double divide(double x, double y) {
    if (y == 0) {
        printf("Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    return x / y;
}

// Function to calculate power of a number
double power(double x, double y) {
    return pow(x, y);
}

// Function to calculate square root of a number
double squareRoot(double x) {
    if (x < 0) {
        printf("Error: Square root of negative number\n");
        exit(EXIT_FAILURE);
    }
    return sqrt(x);
}

// Function to calculate sine of a number (in radians)
double sine(double x) {
    return sin(x);
}

// Function to calculate cosine of a number (in radians)
double cosine(double x) {
    return cos(x);
}

// Function to calculate tangent of a number (in radians)
double tangent(double x) {
    return tan(x);
}

int main() {
    int choice;
    double x, y, result;
    while (1) {
        printf("------------Scientific Calculator------------\n");
        printf("Choose an operation:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Square Root\n7. Sine\n8. Cosine\n9. Tangent\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 10) {
            printf("Goodbye!\n");
            break;
        }
        switch(choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = add(x, y);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = subtract(x, y);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = multiply(x, y);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = divide(x, y);
                break;
            case 5:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = power(x, y);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &x);
                result = squareRoot(x);
                break;
            case 7:
                printf("Enter a number (in radians): ");
                scanf("%lf", &x);
                result = sine(x);
                break;
            case 8:
                printf("Enter a number (in radians): ");
                scanf("%lf", &x);
                result = cosine(x);
                break;
            case 9:
                printf("Enter a number (in radians): ");
                scanf("%lf", &x);
                result = tangent(x);
                break;
            default:
                printf("Invalid choice\n");
                continue;
       }
       printf("Result: %lf\n", result);
   }
   return 0;
}