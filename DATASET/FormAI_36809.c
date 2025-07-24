//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, pressure;
    
    srand(time(NULL)); // Initialize random number generator
    
    printf("Welcome to Weather Simulator!\n\n");
    
    // Loop to simulate multiple days of weather
    for(int i = 1; i <= 7; i++) {
        printf("Day %d:\n", i);
        
        // Generate random values for temperature, humidity, and pressure
        temperature = rand() % 50 - 10;
        humidity = rand() % 101;
        pressure = rand() % 301 + 700;
        
        // Print out the values for the day
        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d percent\n", humidity);
        printf("Pressure: %d hPa\n\n", pressure);
    }
    
    printf("Thank you for using Weather Simulator!\n");
    
    return 0;
}