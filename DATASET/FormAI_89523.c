//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

// function declarations
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);
float square_root(float);
float absolute(float);

int main() {
    // variable declarations
    char operation;
    float num1, num2;

    // user input
    printf("*** Scientific Calculator ***\n");
    printf("Enter an operation (+, -, *, /, ^, √, |x|): ");
    scanf("%c", &operation);
    printf("Enter the first number: ");
    scanf("%f", &num1);
    if (operation != '|' && operation != '√') {
        printf("Enter the second number: ");
        scanf("%f", &num2);
    }

    // operation selection
    switch (operation) {
        case '+':
            printf("Result: %.2f\n", add(num1, num2));
            break;
        case '-':
            printf("Result: %.2f\n", subtract(num1, num2));
            break;
        case '*':
            printf("Result: %.2f\n", multiply(num1, num2));
            break;
        case '/':
            printf("Result: %.2f\n", divide(num1, num2));
            break;
        case '^':
            printf("Result: %.2f\n", power(num1, num2));
            break;
        case '√':
            printf("Result: %.2f\n", square_root(num1));
            break;
        case '|':
            printf("Result: %.2f\n", absolute(num1));
            break;
        default:
            printf("Error: Operation not recognized\n");
    }

    return 0;
}

// function definitions
float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 == 0) {
        printf("Error: Cannot divide by zero\n");
        return -1;
    } else {
        return num1 / num2;
    }
}

float power(float num1, float num2) {
    return pow(num1, num2);
}

float square_root(float num) {
    if (num < 0) {
        printf("Error: Cannot find square root of a negative number\n");
        return -1;
    } else {
        return sqrt(num);
    }
}

float absolute(float num) {
    return fabs(num);
}