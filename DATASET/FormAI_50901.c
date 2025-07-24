//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temp = 0;
    time_t t;
    srand((unsigned) time(&t)); //Initializing random number generator

    printf("The temperature monitoring program is running...\n");

    while(1) // Loop to continuously monitor temperature
    {
        temp = (float) rand() / RAND_MAX * 100; // Generate a random temperature value between 0 and 100
        printf("Current Temperature: %.2f degrees Celsius\n", temp);
        if(temp > 30) // If temperature is above 30 degrees Celsius, send a warning message
        {
            printf("*** WARNING: Temperature is above 30 degrees Celsius ***\n");
            // Add code to send an alert message to system administrator
        }
        sleep(2); // Wait for 2 seconds before taking the next temperature reading
    }

    return 0;
}