//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include <stdio.h>
#include <math.h>

// Function to perform addition
float add(float num1, float num2) {
    return num1 + num2;
}

// Function to perform subtraction
float subtract(float num1, float num2) {
    return num1 - num2;
}

// Function to perform multiplication
float multiply(float num1, float num2) {
    return num1 * num2;
}

// Function to perform division
float divide(float num1, float num2) {
    return num1 / num2;
}

// Function to perform modulus
int modulus(int num1, int num2) {
    return num1 % num2;
}

// Function to perform power
double power(double num1, double num2) {
    return pow(num1, num2);
}

// Function to perform square root
double square_root(double num) {
    return sqrt(num);
}

int main() {
    float num1, num2, result;
    int choice;
    
    printf("Choose operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Square Root\n");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = add(num1, num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = subtract(num1, num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = multiply(num1, num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            result = divide(num1, num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            break;
        case 5:
            printf("Enter two numbers to find modulus: ");
            scanf("%f %f", &num1, &num2);
            result = modulus((int)num1, (int)num2);
            printf("%.0f %% %.0f = %.0f\n", num1, num2, result);
            break;
        case 6:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 7:
            printf("Enter number to find square root: ");
            scanf("%lf", &num1);
            result = square_root(num1);
            printf("sqrt(%.2lf) = %.2lf\n", num1, result);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}