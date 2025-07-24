//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate sum of two numbers
int calculate(int num1, int num2){
    int sum = num1 + num2;
    return sum;
}

// Callback function to print result
void printResult(int result) 
{
    printf("The sum is: %d\n", result);
}

// Main function
int main() {
    int num1, num2;
    
    // Generate random numbers
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;
    
    printf("Calculating the sum of %d and %d...\n\n", num1, num2);
    
    // Initialize asynchronous operation
    int result;
    void (*callback)(int);
    callback = printResult;
    
    // Start operation
    result = calculate(num1, num2);
    (*callback)(result);
    
    // Continue running the program while asynchronous operation
    // completes in the background...
    
    printf("Waiting for operation to complete...\n\n");
    
    // Do some other tasks while waiting
    
    printf("Operation completed!\n");
    
    return 0;
}