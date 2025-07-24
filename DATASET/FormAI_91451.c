//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMPERATURE_READINGS 1000

int main()
{
    int temperatureReadings[MAX_TEMPERATURE_READINGS];
    int numberOfReadings = 0;
    char userInput[10];

    printf("Enter temperature values (enter 'q' to quit):\n");

    // Loop until the user enters 'q' or until the maximum number of readings is reached
    while (numberOfReadings < MAX_TEMPERATURE_READINGS)
    {
        printf("Temperature #%d: ", numberOfReadings + 1);

        // Read user input as a string
        fgets(userInput, 10, stdin);

        // Check if the user wants to quit
        if (strcmp(userInput, "q\n") == 0)
        {
            break;
        }

        // Convert user input from string to integer
        int temperature = atoi(userInput);

        // Save the temperature reading
        temperatureReadings[numberOfReadings] = temperature;
        numberOfReadings++;
    }

    // Calculate the average temperature
    int sum = 0;
    for (int i = 0; i < numberOfReadings; i++)
    {
        sum += temperatureReadings[i];
    }
    float averageTemperature = (float)sum / numberOfReadings;

    // Print out the average temperature and the highest and lowest temperature readings
    int highestTemperature = temperatureReadings[0];
    int lowestTemperature = temperatureReadings[0];
    for (int i = 0; i < numberOfReadings; i++)
    {
        if (temperatureReadings[i] > highestTemperature)
        {
            highestTemperature = temperatureReadings[i];
        }
        if (temperatureReadings[i] < lowestTemperature)
        {
            lowestTemperature = temperatureReadings[i];
        }
    }
    printf("\nAverage temperature: %.2f\n", averageTemperature);
    printf("Highest temperature: %d\n", highestTemperature);
    printf("Lowest temperature: %d\n", lowestTemperature);

    return 0;
}