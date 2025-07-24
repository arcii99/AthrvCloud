//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    float temperature;
    int num_readings = 0;
    float average_temp = 0;

    // Seed the random number generator
    srand(time(NULL));

    printf("C Temperature Monitor\n");

    // Continuously read temperature until user exits
    while (1) 
    {
        // Simulate a temperature reading
        temperature = (float)rand()/(float)(RAND_MAX/30) + 20; // Generate random temperature between 20 and 50 degrees Celsius
        printf("Temperature: %.1f C\n", temperature);

        // Update running average temperature
        average_temp = ((average_temp * num_readings) + temperature) / (num_readings + 1);
        num_readings++;

        // Display current average temperature
        printf("Average Temperature: %.1f C\n", average_temp);

        // Wait for 2 seconds before next loop iteration
        sleep(2);
    }

    return 0;
}