//FormAI DATASET v1.0 Category: Temperature monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 100 // the maximum safe temperature
#define MIN_TEMP 0   // the minimum safe temperature

int main()
{
    float temperature;

    while(1) // run forever
    {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temperature);

        // check if the temperature exceeds the maximum safe level
        if(temperature > MAX_TEMP)
        {
            printf("\nWARNING! The temperature is too high! Current temperature is %0.2f C\n", temperature);
        }

        // check if the temperature goes below the minimum safe level
        else if(temperature < MIN_TEMP)
        {
            printf("\nWARNING! The temperature is too low! Current temperature is %0.2f C\n", temperature);
        }
        
        else
        {
            printf("\nTemperature is within the safety limits! Current temperature is %0.2f C\n", temperature);
        }
    }

    return 0;
}