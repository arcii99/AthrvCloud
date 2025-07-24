//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Set random seed based on current system time
    
    int temperature = rand() % 51 - 10; // Generate random temperature between -10 and 40 degrees Celsius
    int humidity = rand() % 101; // Generate random humidity value (0-100%)
    int pressure = rand() % 101 + 900; // Generate random pressure value (900-1000 hPa)
    
    // Print out current weather conditions
    printf("Current weather conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);
    
    // Determine the current weather based on the conditions
    if (temperature < 0) {
        printf("It's freezing outside!\n");
    } else if (temperature < 10) {
        printf("It's very cold outside.\n");
    } else if (temperature < 20) {
        printf("It's chilly outside.\n");
    } else if (temperature < 30) {
        printf("It's warm outside.\n");
    } else {
        printf("It's hot outside!\n");
    }
    
    if (humidity < 30) {
        printf("It's dry outside.\n");
    } else if (humidity < 70) {
        printf("It's humid outside.\n");
    } else {
        printf("It's very humid outside!\n");
    }
    
    if (pressure < 980) {
        printf("The air pressure is low.\n");
    } else if (pressure < 1020) {
        printf("The air pressure is normal.\n");
    } else {
        printf("The air pressure is high.\n");
    }
    
    return 0;
}