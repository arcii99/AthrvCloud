//FormAI DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature;
    srand(time(NULL)); // initialize random number generator with current time

    printf("Initializing temperature monitor...\n");

    while(1)
    {
        // simulate temperature readings from -10 to 40 degrees Celsius
        temperature = (rand() % 500) / 10.0 - 10;

        if (temperature <= 0)
        {
            printf("Warning! Temperature is below freezing: %.1f degrees Celsius\n", temperature);
            printf("Taking necessary action to prevent damage.\n");
        }
        else if (temperature >= 30)
        {
            printf("Warning! Temperature is above safe range: %.1f degrees Celsius\n", temperature);
            printf("Sending email alert to system administrator.\n");
        }
        else
        {
            printf("Temperature is normal: %.1f degrees Celsius\n", temperature);
        }

        // simulate delay between temperature readings
        int delay = ((rand() % 10) + 1) * 1000;
        printf("Waiting for %d ms before reading temperature again...\n\n", delay);
        usleep(delay * 1000); // delay in microseconds
    }

    return 0;
}