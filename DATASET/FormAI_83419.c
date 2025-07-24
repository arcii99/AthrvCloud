//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate the inverse sine
double inverseSine(double x) {
    if (x > 1 || x < -1) {
        // throw error if input is out of range
        fprintf(stderr, "Error: Input out of range for inverse sine function.\n");
        exit(1);
    }
    return asin(x);
}

int main() {
    double input, result;
    printf("Enter the input for inverse sine function (-1 <= x <= 1): ");
    scanf("%lf", &input);
    
    // calculate inverse sine and handle errors
    result = inverseSine(input);
    
    // print result
    printf("The inverse sine of %lf is %lf.\n", input, result);
    
    return 0;
}