//FormAI DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    float currentTemp = (float)(rand() % 50) - 10; // generate random starting temp between -10 to 40 degrees Celsius
    float maxTemp = currentTemp;
    float minTemp = currentTemp;

    printf("Welcome to the Temperature Monitor!\n");
    printf("The current temperature is %.2f degrees Celsius.\n\n", currentTemp);

    int counter = 0;
    while(counter < 5){
        float newTemp = (float)(rand() % 6) - 3; // generate random temperature change between -3 to 2 degrees Celsius
        currentTemp += newTemp; // add temperature change to current temperature
        counter++;

        if(currentTemp > maxTemp){
            maxTemp = currentTemp;
        }
        if(currentTemp < minTemp){
            minTemp = currentTemp;
        }

        printf("The current temperature is %.2f degrees Celsius.\n", currentTemp);
    }

    printf("\nMonitor Summary:\n");
    printf("Highest temperature recorded: %.2f degrees Celsius.\n", maxTemp);
    printf("Lowest temperature recorded: %.2f degrees Celsius.\n", minTemp);

    return 0;
}