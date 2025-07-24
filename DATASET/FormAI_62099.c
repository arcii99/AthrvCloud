//FormAI DATASET v1.0 Category: Weather simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void simulateWeather(int lowTemp, int highTemp, int humidity, int windSpeed);

int main() {
    int lowTemp, highTemp, humidity, windSpeed;

    // Set seed for random number generator
    srand(time(0));

    // Get user input for weather conditions
    printf("Enter the low temperature (in Celsius): ");
    scanf("%d", &lowTemp);

    printf("Enter the high temperature (in Celsius): ");
    scanf("%d", &highTemp);

    printf("Enter the humidity percentage: ");
    scanf("%d", &humidity);

    printf("Enter the wind speed (in km/h): ");
    scanf("%d", &windSpeed);

    // Call function to simulate weather
    simulateWeather(lowTemp, highTemp, humidity, windSpeed);

    return 0;
}

void simulateWeather(int lowTemp, int highTemp, int humidity, int windSpeed) {
    // Generate random temperature within user input range
    int temperature = rand() % (highTemp - lowTemp + 1) + lowTemp;

    // Convert temperature to Fahrenheit
    float fahrenheit = (temperature * 9 / 5) + 32;

    // Generate random pressure between 950 and 1050 millibars
    double pressure = (double) (rand() % 100 + 950) / 10.0;

    // Generate random precipitation amount between 0 and 10 millimetres
    float precipitation = (float) rand() / (float) (RAND_MAX / 10);

    // Calculate wind chill factor
    float windChill = 13.12 + (0.6215 * temperature) - (11.37 * pow(windSpeed, 0.16)) + (0.3965 * temperature * pow(windSpeed, 0.16));

    // Print generated weather conditions
    printf("\nThe temperature is %d Celsius / %.1f Fahrenheit\n", temperature, fahrenheit);
    printf("The humidity is %d percent\n", humidity);
    printf("The wind speed is %d km/h\n", windSpeed);
    printf("The pressure is %.1f millibars\n", pressure);
    printf("The precipitation amount is %.1f mm\n", precipitation);
    printf("The wind chill factor is %.1f Celsius\n", windChill);
}