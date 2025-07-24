//FormAI DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>

int main() {
    double celsius, fahrenheit;

    // Ask user for input
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    // Convert celsius to fahrenheit
    fahrenheit = (celsius * 1.8) + 32;

    // Display the result
    printf("%.2lf Celsius = %.2lf Fahrenheit", celsius, fahrenheit);

    return 0;
}