//FormAI DATASET v1.0 Category: Weather simulation ; Style: post-apocalyptic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

/* Function to generate random temperature within given range */ 
double generateTemperature(double minTemp, double maxTemp) 
{ 
    double temp = (double)rand()/(double)RAND_MAX; 
    return minTemp + temp*(maxTemp-minTemp); 
} 

/* Function to generate random precipitation within given range */ 
double generatePrecipitation(double minPrecip, double maxPrecip) 
{ 
    double precip = (double)rand()/(double)RAND_MAX; 
    return minPrecip + precip*(maxPrecip-minPrecip); 
} 

int main() 
{ 
    srand(time(NULL)); // Seed for random function 

    double temperature, precipitation; 
    int postApocalypticWeather[7][24]; // 7 days x 24 hours

    // Generate weather conditions for the next 7 days 
    for(int day = 0; day < 7; day++)
    { 
        printf("Day %d\n", day+1); 
        for(int hour = 0; hour < 24; hour++)
        { 
            // Determine temperature and precipitation for this hour 
            if(hour <= 12) // Temperature rises in the morning
                temperature = generateTemperature(10.0, 25.0); 
            else // Temperature drops in the evening
                temperature = generateTemperature(-5.0, 20.0); 
            
            if(temperature < 0.0) // If temperature is below 0, there is snow
                precipitation = generatePrecipitation(0.1, 0.5); 
            else // Otherwise, there is rain
                precipitation = generatePrecipitation(0.3, 1.0); 

            // Store weather conditions for this hour 
            postApocalypticWeather[day][hour] = (int) (temperature + 0.5); // Round temperature to nearest integer
            postApocalypticWeather[day][hour] *= 10; // Multiply by 10 to store as an integer
            postApocalypticWeather[day][hour] += (int) (precipitation * 100); // Store precipitation as an integer
            
            // Print weather conditions for this hour 
            printf("%d:00 - Temperature: %g, Precipitation: %g\n", hour, temperature, precipitation); 
        } 
        printf("\n"); 
    }

    // Print all weather conditions for all hours 
    printf(" All Weather Conditions for all Hours:\n"); 
    for(int day = 0; day < 7; day++)
    {
        for(int hour = 0; hour < 24; hour++)
        {
            printf("%d ", postApocalypticWeather[day][hour]);
        }
        printf("\n"); 
    }

    return 0; 
}