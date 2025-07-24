//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int minTemp = 10, maxTemp = 35, currentTemp;
    time_t t;
    srand((unsigned)time(&t));

    printf("Initializing temperature monitor...\n\n");

    while(1) {
        currentTemp = (rand() % (maxTemp - minTemp + 1)) + minTemp; // Generating random temperature value
        printf("Current temperature: %d°C\n", currentTemp);
        if(currentTemp >= 30) {
            printf("WARNING: High temperature detected! Cooling system activated.\n\n");
        } else if(currentTemp <= 15) {
            printf("WARNING: Low temperature detected! Heating system activated.\n\n");
        } else {
            printf("Temperature within normal range.\n\n");
        }
        sleep(2); // Wait for 2 seconds before checking temperature again
    }
    
    return 0;
}