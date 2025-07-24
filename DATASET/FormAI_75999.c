//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>

// Function to calculate the Fibonacci sequence and return the result
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to generate Fibonacci sequence visualization
void fibonacci_visualizer(int n) {
    printf("Fibonacci Sequence Visualizer\n");
    printf("-----------------------------\n");
    
    // Generate the Fibonacci sequence and print each number with a corresponding number of minus signs
    for (int i = 0; i <= n; i++) {
        int result = fibonacci(i);
        
        printf("%d: ", result); // Print the Fibonacci number
        
        // Print a corresponding number of minus signs to represent the number
        for (int j = 0; j < result; j++){
            printf("-");
        }
        
        printf("\n"); // Move to a new line after printing the number and corresponding minus signs
    }
}

// Main function to run the program
int main() {
    int n;
    
    printf("Enter how many terms of the Fibonacci sequence you want to visualize: ");
    scanf("%d", &n); // Get input from user
    
    fibonacci_visualizer(n);
    
    return 0;
}