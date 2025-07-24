//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include<stdio.h>
#include<math.h>

// function declarations
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);
float logarithm(float, float);
float factorial(float);
float sin_value(float);
float cos_value(float);
float tan_value(float);

// main function
int main() {
    float num1, num2, result;
    int choice;
    
    // menu
    printf("-----Scientific Calculator-----\n\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Logarithm\n7. Factorial\n8. Sine\n9. Cosine\n10. Tangent\n\n");
    
    // input choice
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: // addition
            printf("Enter two numbers to add: ");
            scanf("%f%f", &num1, &num2);
            result = add(num1, num2);
            printf("Result: %f\n", result);
            break;
            
        case 2: // subtraction
            printf("Enter two numbers to subtract: ");
            scanf("%f%f", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result: %f\n", result);
            break;
            
        case 3: // multiplication
            printf("Enter two numbers to multiply: ");
            scanf("%f%f", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result: %f\n", result);
            break;
            
        case 4: // division
            printf("Enter two numbers to divide: ");
            scanf("%f%f", &num1, &num2);
            result = divide(num1, num2);
            printf("Result: %f\n", result);
            break;
            
        case 5: // power
            printf("Enter base and exponent: ");
            scanf("%f%f", &num1, &num2);
            result = power(num1, num2);
            printf("Result: %f\n", result);
            break;
            
        case 6: // logarithm
            printf("Enter base and number: ");
            scanf("%f%f", &num1, &num2);
            result = logarithm(num1, num2);
            printf("Result: %f\n", result);
            break;
            
        case 7: // factorial
            printf("Enter a number to find factorial of: ");
            scanf("%f", &num1);
            result = factorial(num1);
            printf("Result: %f\n", result);
            break;
            
        case 8: // sine
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = sin_value(num1);
            printf("Result: %f\n", result);
            break;
            
        case 9: // cosine
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = cos_value(num1);
            printf("Result: %f\n", result);
            break;
            
        case 10: // tangent
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = tan_value(num1);
            printf("Result: %f\n", result);
            break;
            
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}

// addition function
float add(float x, float y) {
    return x + y;
}

// subtraction function
float subtract(float x, float y) {
    return x - y;
}

// multiplication function
float multiply(float x, float y) {
    return x * y;
}

// division function
float divide(float x, float y) {
    return x / y;
}

// power function
float power(float base, float exponent) {
    return pow(base, exponent);
}

// logarithm function
float logarithm(float base, float num) {
    return log(num) / log(base);
}

// factorial function
float factorial(float num) {
    if(num == 0 || num == 1) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

// sine function
float sin_value(float angle) {
    float radians = angle * 3.141592653589793 / 180; // convert degrees to radians
    return sin(radians);
}

// cosine function
float cos_value(float angle) {
    float radians = angle * 3.141592653589793 / 180; // convert degrees to radians
    return cos(radians);
}

// tangent function
float tan_value(float angle) {
    float radians = angle * 3.141592653589793 / 180; // convert degrees to radians
    return tan(radians);
}