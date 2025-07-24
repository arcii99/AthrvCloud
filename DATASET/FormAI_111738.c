//FormAI DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); // seed the random number generator with the current time
    
    float temperature = 20.0f; // starting temperature
    
    for(int i = 0; i < 365; i++) // simulate one year's worth of weather data
    {
        float change = ((float)rand() / RAND_MAX) * 10.0f - 5.0f; // generate a random temperature change
        
        temperature += change; // apply the temperature change
        
        if(temperature < 0.0f) // check if temperature is below freezing
        {
            printf("It is very cold today! ");
        }
        else if(temperature > 30.0f) // check if temperature is above 30°C
        {
            printf("It is very hot today! ");
        }
        else // temperature is within normal range
        {
            printf("The weather is pleasant today. ");
        }
        
        printf("The temperature is %0.1f°C.\n", temperature); // print current temperature
    }
    
    printf("Year-long simulation complete.\n");
    
    return 0;
}