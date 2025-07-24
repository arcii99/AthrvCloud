//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kilometers to Miles
float kmToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
float milesToKm(float miles) {
    return miles * 1.60934;
}

int main()
{
    // Welcome message
    printf("Welcome to the Unit Converter!\n\n");

    // Menu options
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Kilometers to Miles\n4. Miles to Kilometers\n\n");
    printf("Please enter your choice: ");

    // User input for choice
    int choice;
    scanf("%d", &choice);

    // Variables for input and output values for conversion
    float input, output;

    // Switch case based on user's choice
    switch(choice) {
        case 1:
            printf("\nEnter Celsius value: ");
            scanf("%f", &input);
            output = celsiusToFahrenheit(input);
            printf("%.2f Celsius = %.2f Fahrenheit", input, output);
            break;
        case 2:
            printf("\nEnter Fahrenheit value: ");
            scanf("%f", &input);
            output = fahrenheitToCelsius(input);
            printf("%.2f Fahrenheit = %.2f Celsius", input, output);
            break;
        case 3:
            printf("\nEnter kilometers value: ");
            scanf("%f", &input);
            output = kmToMiles(input);
            printf("%.2f kilometers = %.2f miles", input, output);
            break;
        case 4:
            printf("\nEnter miles value: ");
            scanf("%f", &input);
            output = milesToKm(input);
            printf("%.2f miles = %.2f kilometers", input, output);
            break;
        default:
            printf("Invalid option selected.");
            break;
    }

    return 0;
}