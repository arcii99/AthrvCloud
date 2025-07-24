//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <unistd.h>

// Function to print the Fibonacci sequence up to a given limit
void fibonacci(int limit) {
    // Initialize the first two terms of the sequence
    int n1 = 0, n2 = 1;
    // Iterate through the sequence until the limit is reached
    while (n1 < limit) {
        // Print the current term of the sequence
        printf("%d ", n1);
        // Swap the variables to update the sequence
        int temp = n2;
        n2 = n1 + n2;
        n1 = temp;
        // Add a short delay to create a visual effect
        usleep(50000);
    }
}

int main() {
    // Prompt the user to enter a limit for the sequence
    int limit;
    printf("Enter the Fibonacci sequence limit: ");
    scanf("%d", &limit);
    // Call the fibonacci function to generate the sequence
    fibonacci(limit);
    return 0;
}