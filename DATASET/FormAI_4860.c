//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
#include <stdio.h>
#include <math.h>

/* Function prototypes */
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float power(float x, float y);
float square(float a);

int main() {
    int choice;
    float a, b;
    printf("Welcome to the Scientific Calculator!\n\n");
    printf("Please select an operation to perform:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("5. Raise to power\n6. Square\n\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &a, &b);
            printf("Result: %.2f\n", add(a, b));
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &a, &b);
            printf("Result: %.2f\n", subtract(a, b));
            break; 
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &a, &b);
            printf("Result: %.2f\n", multiply(a, b));
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &a, &b);
            printf("Result: %.2f\n", divide(a, b));
            break;
        case 5:
            printf("Enter a number to raise to a power: ");
            scanf("%f", &a);
            printf("Enter the power to raise the number to: ");
            scanf("%f", &b);
            printf("Result: %.2f\n", power(a, b));
            break;
        case 6:
            printf("Enter a number to square: ");
            scanf("%f", &a);
            printf("Result: %.2f\n", square(a));
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}

/* Function definitions */
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

float power(float x, float y) {
    return pow(x, y);
}

float square(float a) {
    return sqrt(a);
}