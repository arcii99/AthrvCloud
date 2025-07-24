//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float current_temp, previous_temp = 0;
    time_t current_time;

    // Get current time and temperature readings
    current_time = time(NULL);
    srand(time(0));
    current_temp = (rand() % 100) - 50;
    printf("Current temperature is %.2f degrees Celsius\n", current_temp);

    // Continuously monitor temperature
    while (1)
    {
        // Sleep for 5 seconds
        sleep(5);

        // Check current temperature
        previous_temp = current_temp;
        current_temp = (rand() % 100) - 50;
        printf("Current temperature is %.2f degrees Celsius\n", current_temp);

        // Check for temperature change
        if (current_temp > (previous_temp + 5))
        {
            printf("Temperature has increased by 5 degrees, potential danger!\n");
        }
        else if (current_temp < (previous_temp - 5))
        {
            printf("Temperature has decreased by 5 degrees, potential danger!\n");
        }

        // Log temperature reading to file
        FILE *fp;
        fp = fopen("temp_log.txt", "a");
        fprintf(fp, "Time: %sTemperature: %.2f degrees Celsius\n", asctime(localtime(&current_time)), current_temp);
        fclose(fp);
    }

    return 0;
}