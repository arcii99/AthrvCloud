//FormAI DATASET v1.0 Category: Weather simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    float temperature = 25.0; // Start with a pleasant temperature
    float humidity = 70.0; // Start with a comfortable humidity
    
    printf("Starting weather conditions: Temperature %.1fC, Humidity %.1f%%\n", temperature, humidity);
    
    // Loop through 24 hours
    for (int i = 0; i < 24; i++)
    {
        // Randomly adjust temperature and humidity up or down by a small amount
        float temperatureAdjustment = (float)(rand() % 21 - 10) / 10.0; // -1.0 to 1.0
        float humidityAdjustment = (float)(rand() % 21 - 10) / 10.0; // -1.0 to 1.0
        
        // Apply adjustments
        temperature += temperatureAdjustment;
        humidity += humidityAdjustment;
        
        // Keep values within reasonable range
        temperature = temperature < -30.0 ? -30.0 : temperature;
        temperature = temperature > 50.0 ? 50.0 : temperature;
        humidity = humidity < 0.0 ? 0.0 : humidity;
        humidity = humidity > 100.0 ? 100.0 : humidity;
        
        // Output results
        printf("Hour %d: Temperature %.1fC, Humidity %.1f%% (Adjustment: %.1fC, %.1f%%)\n", i, temperature, humidity, temperatureAdjustment, humidityAdjustment);
        
        // Add some variability in rhyme for fun!
        if (i == 5 || i == 11 || i == 17 || i == 23)
        {
            printf("Checking the weather at this hour, it's neither sweet nor sour.\n");
        }
        else if (temperature >= 30.0 && humidity >= 80.0)
        {
            printf("It's hot and sticky, makes me feel pretty icky.\n");
        }
        else if (temperature <= -10.0)
        {
            printf("Jack Frost is nipping at your nose, better bundle up before it froze!\n");
        }
        else if (humidity <= 30.0)
        {
            printf("It's a dry heat, feels like walking on hot concrete.\n");
        }
        else if (humidity >= 80.0)
        {
            printf("It's wet and clammy, air so thick it's hard to breathe.\n");
        }
        else
        {
            printf("The weather is fair, blue skies and fresh air.\n");
        }
    }
    
    printf("Weather simulation complete.\n");
    
    return 0;
}