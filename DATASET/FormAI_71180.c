//FormAI DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int current_temp, min_temp, max_temp, total_temp = 0, count = 0;
    
    srand(time(NULL)); // Seed random number generator with current time
    
    min_temp = rand() % 5 + 15; // Generate random minimum temperature between 15 and 19 degrees Celsius
    max_temp = rand() % 5 + 25; // Generate random maximum temperature between 25 and 29 degrees Celsius
    
    printf("Minimum Temperature: %d°C\n", min_temp);
    printf("Maximum Temperature: %d°C\n", max_temp);
    printf("------------------------\n");
    
    while(1)
    {
        current_temp = rand() % (max_temp - min_temp + 1) + min_temp; // Generate random current temperature between minimum and maximum
        
        printf("Current Temperature: %d°C\n\n", current_temp);
        
        total_temp += current_temp; // Add current temperature to running total
        
        count++; // Increment count of temperature readings
        
        if (current_temp >= 30) // Check if temperature is above 30 degrees Celsius
        {
            printf("WARNING! Temperature above 30°C. Cooling system failure detected.\n");
            printf("Shutting down system...\n");
            break; // End program
        }
        else if (count == 10) // Check if 10 temperature readings have been taken
        {
            float average_temp = (float) total_temp / count; // Calculate average temperature
            
            printf("Average Temperature: %.1f°C\n", average_temp);
            
            total_temp = 0; // Reset running total
            count = 0; // Reset count of temperature readings
            
            min_temp = rand() % 5 + 15; // Generate new random minimum temperature between 15 and 19 degrees Celsius
            max_temp = rand() % 5 + 25; // Generate new random maximum temperature between 25 and 29 degrees Celsius
            
            printf("Minimum Temperature: %d°C\n", min_temp); 
            printf("Maximum Temperature: %d°C\n", max_temp); 
            printf("------------------------\n");
        }
        
        sleep(1); // Wait for 1 second before taking next temperature reading
    }
    
    return 0;
}