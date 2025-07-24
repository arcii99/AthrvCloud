//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float readTemperature()
{
    float temp = 0;
    // code to read temperature from sensor
    // for this example, we will simulate the temperature reading
    srand(time(NULL)); // initialize random seed
    temp = (float)(rand() % 100) + ((float)(rand() % 10) / 10); // generate random temperature between 0 - 100.9
    return temp;
}

void displayTemperature(float temp)
{
    printf("\nCurrent temperature: %.1f degrees Celsius\n", temp);
}

void checkTemperature(float temp, float threshold)
{
    if(temp > threshold)
    {
        printf("Temperature has exceeded the threshold of %.1f degrees Celsius!\n", threshold);
        // code to send alert to user
    }
}

int main()
{
    float threshold = 28.0; // temperature threshold
    printf("Temperature Monitor Program\n");
    printf("Threshold: %.1f degrees Celsius\n\n", threshold);
    for(int i=0; i<10; i++)
    {
        float currentTemp = readTemperature();
        displayTemperature(currentTemp);
        checkTemperature(currentTemp, threshold);
        sleep(1); // wait for 1 second before reading temperature again
    }
    return 0;
}