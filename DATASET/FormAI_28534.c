//FormAI DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random weather conditions
int randomWeather()
{
    int weather = rand() % 3;
    // 0 = sunny, 1 = cloudy, 2 = rainy
    return weather;
}

// Function to display weather conditions
void displayWeather(int weather)
{
    switch (weather)
    {
        case 0:
            printf("Weather: Sunny\n");
            break;
        case 1:
            printf("Weather: Cloudy\n");
            break;
        case 2:
            printf("Weather: Rainy\n");
            break;
        default:
            printf("Weather: Unknown\n");
            break;
    }
}

// Function to simulate temperature
int simulateTemp(int month, int weather)
{
    int temp;
    // Generate temperature based on month and weather condition
    switch (month)
    {
        // January to March
        case 1:
        case 2:
        case 3:
            switch (weather)
            {
                case 0:
                    temp = rand() % 12 + 15; // 15 to 26 degrees Celsius
                    break;
                case 1:
                    temp = rand() % 8 + 8; // 8 to 15 degrees Celsius
                    break;
                case 2:
                    temp = rand() % 6 + 3; // 3 to 8 degrees Celsius
                    break;
            }
            break;
        // April to June
        case 4:
        case 5:
        case 6:
            switch (weather)
            {
                case 0:
                    temp = rand() % 14 + 20; // 20 to 33 degrees Celsius
                    break;
                case 1:
                    temp = rand() % 10 + 15; // 15 to 24 degrees Celsius
                    break;
                case 2:
                    temp = rand() % 8 + 10; // 10 to 18 degrees Celsius
                    break;
            }
            break;
        // July to September
        case 7:
        case 8:
        case 9:
            switch (weather)
            {
                case 0:
                    temp = rand() % 8 + 25; // 25 to 32 degrees Celsius
                    break;
                case 1:
                    temp = rand() % 6 + 20; // 20 to 25 degrees Celsius
                    break;
                case 2:
                    temp = rand() % 10 + 15; // 15 to 24 degrees Celsius
                    break;
            }
            break;
        // October to December
        case 10:
        case 11:
        case 12:
            switch (weather)
            {
                case 0:
                    temp = rand() % 10 + 20; // 20 to 29 degrees Celsius
                    break;
                case 1:
                    temp = rand() % 6 + 12; // 12 to 17 degrees Celsius
                    break;
                case 2:
                    temp = rand() % 6 + 5; // 5 to 10 degrees Celsius
                    break;
            }
            break;
    }
    return temp;
}

// Main function
int main() {
    // Seed random number generator
    srand(time(0));
    // Set current month to January
    int month = 1;
    // Loop through entire year
    for (int i = 1; i <= 12; i++)
    {
        printf("Month: %d\n", month);
        int weather = randomWeather();
        displayWeather(weather);
        int temp = simulateTemp(month, weather);
        printf("Temperature: %d degrees Celsius\n\n", temp);
        // Increment month
        month++;
    }
    return 0;
}