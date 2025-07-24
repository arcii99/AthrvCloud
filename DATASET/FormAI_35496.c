//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complete
#include <stdio.h>

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// main function
int main() {
    // variables to store user input and converted temperature
    float temperature, convertedTemp;
    // variable to store user choice
    int choice;
    
    // display options to user
    printf("Enter 1 to convert Fahrenheit to Celsius\n");
    printf("Enter 2 to convert Celsius to Fahrenheit\n");
    scanf("%d", &choice); // get user choice
    
    // switch case to execute chosen option
    switch(choice) {
        case 1:
            // get temperature in Fahrenheit from user
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            // convert temperature to Celsius and display result
            convertedTemp = fahrenheitToCelsius(temperature);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", temperature, convertedTemp);
            break;
        case 2:
            // get temperature in Celsius from user
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            // convert temperature to Fahrenheit and display result
            convertedTemp = celsiusToFahrenheit(temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", temperature, convertedTemp);
            break;
        default:
            printf("Invalid choice.");
    }
    
    return 0;
}