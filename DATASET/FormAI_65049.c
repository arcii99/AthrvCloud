//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to generate a random temperature value in Celsius
float generateTemp() {
    float temp = (rand() % 100) - 50.0;
    return temp;
}

// Function to convert Celsius to Fahrenheit
float convertToFahrenheit(float tempCelsius) {
    float tempFahrenheit = (tempCelsius * 1.8) + 32.0;
    return tempFahrenheit;
}

int main() {
    srand(time(NULL)); // Seed for random temperature generation
    int i;
    float tempCelsius, tempFahrenheit;

    for (i = 0; i < 10; i++) {
        tempCelsius = generateTemp();
        tempFahrenheit = convertToFahrenheit(tempCelsius);
        printf("Temperature %d: %.2f C / %.2f F\n", i+1, tempCelsius, tempFahrenheit);
        sleep(1); // Wait for 1 second before generating next temperature
    }

    return 0;
}