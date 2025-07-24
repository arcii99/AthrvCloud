//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>

// Function to generate the Fibonacci sequence
void generateFibonacci(int n) {
    int a = 0, b = 1, c;
    printf("%d, %d", a, b); // Print the first two numbers of the sequence
    
    for(int i=3; i<=n; i++) {
        c = a + b;
        printf(", %d", c); // Print the current number of the sequence
        a = b;
        b = c;
    }
}

// Function to display the Fibonacci sequence visually
void displayFibonacci(int n) {
    printf("\nFibonacci Sequence Visualizer\n\n");
    
    for(int i=1; i<=n; i++) {
        printf("%d ", i);
        for(int j=1; j<=i; j++) {
            printf("* "); // Print '*' for each number in the sequence
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);
    
    printf("\n");
    generateFibonacci(n);
    printf("\n\n");
    displayFibonacci(n);
    
    return 0;
}