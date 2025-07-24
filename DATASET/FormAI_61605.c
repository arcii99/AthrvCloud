//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>

double celsiusToFahrenheit(double tempCelsius) {
    double tempFahrenheit = (tempCelsius * 1.8) + 32;
    return tempFahrenheit;
}

int main() {
    double currentTempCelsius, currentTempFahrenheit;
    printf("Enter the current temperature in Celsius: ");
    scanf("%lf", &currentTempCelsius);

    if(currentTempCelsius < -273.15) { // Check if the temperature is below absolute zero
        printf("Temperature below absolute zero!\n");
        exit(EXIT_FAILURE);
    }
    else {
        currentTempFahrenheit = celsiusToFahrenheit(currentTempCelsius);
        printf("The current temperature in Fahrenheit is: %.2lf\n", currentTempFahrenheit);
    }

    return 0;
}