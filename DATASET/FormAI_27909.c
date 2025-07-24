//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void generateWeatherReport(int days, float temperature[], int windSpeed[], int humidity[]);
void displayWeatherReport(int days, float temperature[], int windSpeed[], int humidity[]);

// main function
int main() {
    int days;
    printf("Enter the number of days you want to generate a weather report for: ");
    scanf("%d", &days);  // user input for number of days
    float temperature[days];  // array to store temperature for each day
    int windSpeed[days];  // array to store wind speed for each day
    int humidity[days];  // array to store humidity for each day
    generateWeatherReport(days, temperature, windSpeed, humidity);  // function call to generate weather report
    displayWeatherReport(days, temperature, windSpeed, humidity);  // function call to display weather report
    return 0;
}

// function to generate weather report
void generateWeatherReport(int days, float temperature[], int windSpeed[], int humidity[]) {
    srand(time(NULL));  // seed for random number generation
    for (int i = 0; i < days; i++) {
        temperature[i] = (rand() % 40) - 10;  // random temperature between -10 to 30 degree Celsius
        windSpeed[i] = rand() % 50;  // random wind speed between 0 to 50 km/h
        humidity[i] = rand() % 101;  // random humidity level between 0 to 100 percent
    }
}

// function to display weather report
void displayWeatherReport(int days, float temperature[], int windSpeed[], int humidity[]) {
    printf("Weather report for the next %d days:\n", days);
    for (int i = 0; i < days; i++) {
        printf("Day %d: ", i+1);
        printf("Temperature: %.1f degree Celsius, ", temperature[i]);
        printf("Wind Speed: %d km/h, ", windSpeed[i]);
        printf("Humidity: %d%%\n", humidity[i]);
    }
}