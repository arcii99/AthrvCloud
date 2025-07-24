//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to read temperature from sensor
float readTemperature() {
    // Simulate reading temperature from sensor
    float temperature = (float)(rand() % 50);
    return temperature;
}

// Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float temperature) {
    float fahrenheit = (temperature * 1.8) + 32.0;
    return fahrenheit;
}

int main() {
    int numReadings = 3; // Number of temperature readings to take
    float temperature; // Variable to store temperature readings
    float sumTemperature = 0.0; // Variable to store sum of all temperature readings
    float averageTemperature; // Variable to store average of all temperature readings

    // Take the temperature readings
    for (int i = 0; i < numReadings; i++) {
        temperature = readTemperature();
        printf("Temperature reading %d: %.2f C\n", i+1, temperature);
        sumTemperature += temperature;
    }

    // Calculate the average temperature
    averageTemperature = sumTemperature / numReadings;

    // Convert Celsius temperature to Fahrenheit
    float fahrenheitTemperature = celsiusToFahrenheit(averageTemperature);

    // Print the average temperature in Celsius and Fahrenheit
    printf("Average temperature: %.2f C\n", averageTemperature);
    printf("Average temperature: %.2f F\n", fahrenheitTemperature);

    return 0;
}