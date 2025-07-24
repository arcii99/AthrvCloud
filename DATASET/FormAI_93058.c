//FormAI DATASET v1.0 Category: Temperature monitor ; Style: imaginative
#include <stdio.h>

int main() {

    float temperature; // variable to store temperature
    
    printf("Please enter the temperature in Celsius: "); // prompt user for input
    scanf("%f", &temperature); // read input from user
    
    if (temperature < -273.15) { // check if temperature is valid
        printf("Invalid input, temperature cannot be below absolute zero."); // error message
        return 0;
    }
    
    printf("Temperature in Celsius: %.2f\n", temperature); // display temperature in Celsius
    
    // Convert Celsius to Fahrenheit and display
    float fahrenheit = (temperature * 9 / 5) + 32; // calculate Fahrenheit temperature
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit); // display Fahrenheit temperature
    
    // Convert Celsius to Kelvin and display
    float kelvin = temperature + 273.15; // calculate Kelvin temperature
    printf("Temperature in Kelvin: %.2f\n", kelvin); // display Kelvin temperature
    
    return 0;
}