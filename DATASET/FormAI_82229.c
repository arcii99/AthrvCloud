//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include<stdio.h>

#define TEMP_UPPER_BOUND 100.0 // Set to Celsius
#define TEMP_LOWER_BOUND 0.0   // Set to Celsius

// Function declarations
void display_warning(const char *);
float get_temperature_reading(void);

int main(void)
{
    float temperature = 0.0;

    while (1) // Runs indefinitely
    {
        temperature = get_temperature_reading();

        // Check if temperature is within acceptable range
        if (temperature > TEMP_UPPER_BOUND)
        {
            display_warning("Temperature is too high! Please check the system.");
        }
        else if (temperature < TEMP_LOWER_BOUND)
        {
            display_warning("Temperature is too low! Please check the system.");
        }
        else
        {
            printf("Current temperature reading: %.2f C\n", temperature);
        }
    }

    return 0;
}

void display_warning(const char *warning_message)
{
    printf("WARNING: %s\n", warning_message);
}

float get_temperature_reading(void)
{
    float temperature = 0.0;

    // Code to get temperature reading goes here
    // ...

    return temperature;
}