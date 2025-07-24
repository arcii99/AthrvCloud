//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to read temperature from user input
float read_temperature() {
    float temperature;
    printf("Please enter temperature in Celsius: ");
    scanf("%f", &temperature);
    return temperature;
}

// Function to convert temperature from Celsius to Fahrenheit
float to_fahrenheit(float temperature) {
    float fahrenheit = (temperature * 9 / 5) + 32;
    return fahrenheit;
}

// Main function
int main() {
    float temperature;
    char c;

    do {
        // Read temperature from user input
        temperature = read_temperature();

        // Convert temperature from Celsius to Fahrenheit
        float fahrenheit = to_fahrenheit(temperature);

        // Display temperature in Celsius and Fahrenheit
        printf("%.1f Celsius is equal to %.1f Fahrenheit\n", temperature, fahrenheit);

        // Check if user wants to continue
        printf("Do you want to monitor temperature again? (y/n): ");
        scanf(" %c", &c);
        printf("\n");

    } while(c == 'y' || c == 'Y');

    printf("Thank you for using the Temperature Monitor!\n");

    return EXIT_SUCCESS;
}