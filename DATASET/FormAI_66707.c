//FormAI DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature = 0;

    // Set the seed for the random number generator
    srand(time(0));

    // Generate random temperature values for the next 7 days
    printf("Weather forecast for the next 7 days:\n");
    for (int i = 0; i < 7; i++)
    {
        // Generate random temperature between -10 to 40 degrees Celsius
        temperature = (rand() % 51) - 10;
        
        // Print the day number and temperature
        printf("Day %d: %d degrees Celsius\n", i+1, temperature);
    }
    
    // Calculate the average temperature for the week
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += temperature;
    }
    int average = sum / 7;
    
    // Determine the weather conditions based on the average temperature
    printf("\n");
    printf("Weather conditions for the week:\n");
    if (average <= -5)
    {
        printf("Very cold\n");
    }
    else if (average <= 5)
    {
        printf("Cold\n");
    }
    else if (average <= 15)
    {
        printf("Moderate\n");
    }
    else if (average <= 25)
    {
        printf("Warm\n");
    }
    else
    {
        printf("Hot\n");
    }
    
    return 0;
}