//FormAI DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    // Create variables for temperature and precipitation
    float temperature;
    int precipitation;
    
    // Generate random initial values for temperature and precipitation
    temperature = (float)(rand() % 50) - 10.0;  // Range (-10 to 40) Celsius
    precipitation = rand() % 101;  // Range (0 to 100) millimeters
    
    // Print initial values
    printf("Initial temperature: %.1f degrees Celsius\n", temperature);
    printf("Initial precipitation: %d millimeters\n", precipitation);
    
    // Simulate weather changes for a week
    int day;
    for(day = 1; day <= 7; day++)
    {
        // Generate random temperature change
        float tempChange = (float)(rand() % 21) - 10.0;  // Range (-10 to 10) Celsius
        
        // Update temperature
        temperature += tempChange;
        
        // Generate random precipitation change
        int precipChange = rand() % 21;  // Range (0 to 20) millimeters
        
        // Update precipitation
        precipitation += precipChange;
        
        // Print daily weather report
        printf("Day %d: %.1f degrees Celsius, %d millimeters of precipitation\n", day, temperature, precipitation);
    }
    
    return 0;
}