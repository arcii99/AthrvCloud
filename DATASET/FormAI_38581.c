//FormAI DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables for temperature readings and time
    float temperature;
    time_t current_time;
    char* c_time_string;

    // Use random seed to generate temperature readings
    srand(time(NULL));

    // Loop through 10 temperature readings
    for (int i = 0; i < 10; i++)
    {
        // Generate random temperature reading between 0 and 100 degrees Celsius
        temperature = (rand() % 101);

        // Get current time
        current_time = time(NULL);

        // Convert current time to string format
        c_time_string = ctime(&current_time);

        // Print out temperature reading and time
        printf("Temperature reading #%d: %.1f degrees Celsius\n", i+1, temperature);
        printf("Reading taken at: %s\n\n", c_time_string);

        // Delay for 2 seconds before taking next temperature reading
        sleep(2);
    }

    return 0;
}