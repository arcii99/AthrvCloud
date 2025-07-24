//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate a random temperature between 0 and 40 degrees Celsius
int generateTemperature() {
    return rand() % 41;
}

// Generate a random wind speed between 0 and 100 km/h
int generateWindSpeed() {
    return rand() % 101;
}

// Generate a random precipitation amount between 0 and 50 mm
float generatePrecipitation() {
    return (float)(rand() % 51) / 10.0;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    
    int dayCount = 0;
    float temperature, precipitation;
    int windSpeed;
    
    // Loop through 365 days
    while (dayCount < 365) {
        temperature = generateTemperature();
        windSpeed = generateWindSpeed();
        precipitation = generatePrecipitation();
        
        printf("Day %d - Temperature: %d°C, Wind Speed: %d km/h, Precipitation: %.1f mm\n", dayCount+1, temperature, windSpeed, precipitation);
        
        dayCount++;
    }
    
    return 0;
}