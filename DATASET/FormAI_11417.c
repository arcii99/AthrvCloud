//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator
    
    // initialize variables
    int temperature = 70;
    int humidity = 50;
    int pressure = 1013;
    int time = 0;
    int day = 1;
    
    printf("Day 1: \n");
    printf("Temperature: %d F\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d mb\n", pressure);
    
    while (day <= 7) { // simulate 7 days
        time += rand() % 24; // randomly add hours to the time
        
        // simulate temperature change
        int temp_change = (rand() % 11) - 5;
        temperature += temp_change;
        
        // simulate humidity change
        int humidity_change = (rand() % 11) - 5;
        humidity += humidity_change;
        
        // simulate pressure change
        int pressure_change = (rand() % 11) - 5;
        pressure += pressure_change;
        
        printf("Day %d, %d:00:\n", day, time);
        printf("Temperature: %d F (%s%d)\n", temperature, temp_change >= 0 ? "+" : "", temp_change);
        printf("Humidity: %d%% (%s%d)\n", humidity, humidity_change >= 0 ? "+" : "", humidity_change);
        printf("Pressure: %d mb (%s%d)\n", pressure, pressure_change >= 0 ? "+" : "", pressure_change);
        
        if (time >= 18) { // end of day, reset time and increment day
            time = 0;
            day++;
            if (day <= 7) printf("Day %d: \n", day);
        }
    }
    
    return 0;
}