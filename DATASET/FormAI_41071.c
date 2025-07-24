//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float tempC[24];
    float tempF[24];
    float sumC = 0;
    float sumF = 0;
    int i;
    
    // Introducing a random number generator to simulate temperature data
    srand(time(0)); 
    
    printf("Hour\tTemperature(C)\tTemperature(F)\n");
    
    // Generate and print temperature data for 24 hours
    for(i = 0; i < 24; i++)
    {
        tempC[i] = (float)((rand() % 1500)/100.0) - 5.0; // Random temperature between -5C to 10C
        tempF[i] = (tempC[i] * 9.0/5.0) + 32.0; // Conversion formula from Celsius to Fahrenheit
        
        printf("%d\t%.2f\t\t\t%.2f\n", i, tempC[i], tempF[i]); // Print temperature data for each hour
        
        sumC += tempC[i]; // Sum of temperature in Celsius
        sumF += tempF[i]; // Sum of temperature in Fahrenheit
    }
    
    float avgC = sumC/24; // Average temperature in Celsius
    float avgF = sumF/24; // Average temperature in Fahrenheit
    
    printf("-----------------------------\n");
    printf("Average:\t %.2fC\t\t %.2fF\n", avgC, avgF);
    
    return 0;
}