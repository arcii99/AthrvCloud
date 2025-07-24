//FormAI DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    // Input temperature in Fahrenheit
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    // Display the result
    printf("%.2f Fahrenheit is equal to %.2f Celsius.", fahrenheit, celsius);

    return 0;
}