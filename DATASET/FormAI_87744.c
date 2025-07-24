//FormAI DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>

// Function prototype
double convertToFahrenheit(double celsius);

int main() {
    double celsius, fahrenheit;
    
    // Prompt user to enter temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    // Convert temperature from Celsius to Fahrenheit
    fahrenheit = convertToFahrenheit(celsius);
    
    // Display the result
    printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);
    
    return 0;
}

// Function to convert temperature from Celsius to Fahrenheit
double convertToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}