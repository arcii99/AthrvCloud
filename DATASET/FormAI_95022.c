//FormAI DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature;
    
    srand(time(NULL)); // Initialize random number generator
    
    printf("Temperature Monitor\n");
    printf("-------------------\n");
    
    while(1) // Infinite loop to continuously monitor temperature
    {
        temperature = rand() % 30 + 10; // Generate random temperature between 10°C and 40°C
        
        printf("Current temperature: %.1f°C\n", temperature);
        
        if(temperature > 35.0) // If temperature exceeds 35°C, notify the user
        {
            printf("WARNING: Temperature is too high!\n");
        }
        
        printf("-------------------\n");
        
        sleep(1); // Wait for 1 second before checking temperature again
    }
    
    return 0;
}