//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Temperature range in Celsius
    const int MIN_TEMP = -30;
    const int MAX_TEMP = 50;

    // Generate a random Celsius temperature
    srand(time(NULL));
    int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;

    // Display the temperature
    printf("Current temperature in Celsius: %d\n", temp);

    // Convert Celsius to Fahrenheit
    double tempF = temp * 1.8 + 32;

    // Display temperature in Fahrenheit
    printf("Current temperature in Fahrenheit: %.1f\n", tempF);

    // Set alert temperature thresholds
    const int ALERT_TEMP_LOW = 0;
    const int ALERT_TEMP_HIGH = 40;

    // Check if temperature is outside alert thresholds
    if (temp < ALERT_TEMP_LOW || temp > ALERT_TEMP_HIGH)
    {
        // Display alert message
        printf("ALERT: Temperature is outside safe range!\n");
    }

    return 0;
}