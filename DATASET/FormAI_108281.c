//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num1, num2, num3, result;
    
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    // Calculation 1: Average of three numbers
    float avg = (float)(num1 + num2 + num3)/3;

    // Calculation 2: Sum of first two numbers squared
    int sum_sq = pow(num1 + num2, 2);

    // Calculation 3: Product of all three numbers
    int product = num1 * num2 * num3;

    // Calculation 4: Result of a complex math equation involving all three numbers
    float temp_result = pow(product, 0.5) + pow(avg, 3) - pow(sum_sq, (float)1/4);

    // Round the result to nearest integer
    result = round(temp_result);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}