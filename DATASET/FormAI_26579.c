//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
/****************************************************************************
*   Linus Torvalds-style Temperature Monitor Example Program
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if temperature is within acceptable range
bool is_temperature_valid(float temperature)
{
    if (temperature < 0.0 || temperature > 100.0) {
        return false;
    }
    return true;
}

int main(void)
{
    float temperature;
    char input[10];
    
    printf("Welcome to the Temperature Monitor. Press CTRL-C to exit.\n");

    while (true) {
        printf("Please enter the current temperature in Celcius: ");
        fgets(input, sizeof(input), stdin);

        // Check for invalid input
        if (sscanf(input, "%f", &temperature) != 1) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Check if temperature is within range
        if (!is_temperature_valid(temperature)) {
            printf("Temperature is out of range. Please check the sensors.\n");
            continue;
        }

        // Display the temperature
        printf("Current temperature: %.2f°C\n", temperature);
    }

    return 0;
}