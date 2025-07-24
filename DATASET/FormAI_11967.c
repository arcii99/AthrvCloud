//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

// Define the function pointers for the math operations
typedef double (*operation_t)(double, double);

// Define the math operation functions
double add(double x, double y) { return x + y; }
double subtract(double x, double y) { return x - y; }
double multiply(double x, double y) { return x * y; }
double divide(double x, double y) { return x / y; }

// Define the asynchronous calculator struct
typedef struct {
    double x, y;
    operation_t operation;
    int is_calculated;  // flag to indicate whether the result has been calculated
    double result;      // store the result
} async_calculator_t;

// Define the function to initialize the async calculator struct
void initialize_async_calculator(async_calculator_t *calculator, double x, double y, operation_t operation) {
    calculator->x = x;
    calculator->y = y;
    calculator->operation = operation;
    calculator->is_calculated = 0;
}

// Define the async calculation function
void calculate(async_calculator_t *calculator) {
    // Calculate the result
    calculator->result = calculator->operation(calculator->x, calculator->y);
    calculator->is_calculated = 1;
}

int main() {
    // Create the async calculator
    async_calculator_t calculator;
    // Initialize the async calculator with 10 and 3 for x and y, and the add operation
    initialize_async_calculator(&calculator, 10, 3, add);
    // Call the calculate function asynchronously
    calculate(&calculator);
    
    // Wait for the result to be calculated
    while (!calculator.is_calculated) {
        // Do some other work while waiting...
    }
    
    // Print the result
    printf("The result of %f + %f is %f\n", calculator.x, calculator.y, calculator.result);
    
    // Update the async calculator with 5 and 2 for x and y, and the divide operation
    initialize_async_calculator(&calculator, 5, 2, divide);
    // Call the calculate function asynchronously
    calculate(&calculator);
    
    // Wait for the result to be calculated
    while (!calculator.is_calculated) {
        // Do some other work while waiting...
    }
    
    // Print the result
    printf("The result of %f / %f is %f\n", calculator.x, calculator.y, calculator.result);
    
    return 0;
}