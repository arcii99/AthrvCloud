//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void add(int x, int y, void (*callback)(int));
void subtract(int x, int y, void (*callback)(int));
void multiply(int x, int y, void (*callback)(int));
void divide(int x, int y, void (*callback)(float));

// Callback Functions
void print_sum(int sum){
    printf("Sum of the two numbers is: %d\n", sum);
}

void print_difference(int difference){
    printf("Difference between the two numbers is: %d\n", difference);
}

void print_product(int product){
    printf("Product of the two numbers is: %d\n", product);
}

void print_quotient(float quotient){
    printf("Quotient of the two numbers is: %0.2f\n", quotient);
}

// Main function
int main(){
    int x, y;
    srand(time(NULL));
    
    // Generate two random numbers
    x = rand() % 100 + 1;
    y = rand() % 100 - 1;
    
    printf("The two numbers generated are %d and %d\n", x, y);
    
    // Asynchronous calls to arithmetic functions
    add(x, y, print_sum);
    subtract(x, y, print_difference);
    multiply(x, y, print_product);
    divide(x, y, print_quotient);
    
    return 0;
}

// Function to add two numbers
void add(int x, int y, void (*callback)(int)){
    int sum = x + y;
    callback(sum);
}

// Function to subtract two numbers
void subtract(int x, int y, void (*callback)(int)){
    int difference = x - y;
    callback(difference);
}

// Function to multiply two numbers
void multiply(int x, int y, void (*callback)(int)){
    int product = x * y;
    callback(product);
}

// Function to divide two numbers
void divide(int x, int y, void (*callback)(float)){
    if(y == 0){
        printf("Cannot divide by zero!\n");
        return;
    }
    float quotient = (float)x / (float)y;
    callback(quotient);
}