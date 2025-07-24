//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define delay function for demonstration purposes
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

// Define asynchronous calculation function
void calculate(int x, int y, int* result) {
    delay(1000); // Simulate long processing time
    *result = x + y;
}

int main() {
    int a = 6;
    int b = 4;
    int sum;

    // Start asynchronous calculation
    calculate(a, b, &sum);

    printf("Calculating %d + %d...\n", a, b);

    // Wait for asynchronous calculation to finish
    while (sum == 0) {
        delay(100);
    }

    printf("The sum of %d and %d is %d\n", a, b, sum);

    return 0;
}