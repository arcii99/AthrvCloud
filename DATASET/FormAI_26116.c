//FormAI DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j;
    srand(time(NULL)); // seed randomized numbers with current time

    // Generate 5 days of weather
    for(i=1; i<=5; i++) {
        printf("\nDay %d:\n", i);
        // Generate weather for each hour of the day
        for(j=0; j<24; j++) {
            int temp = rand() % 40;
            int humidity = rand() % 101;
            int wind_speed = rand() % 51;
            int wind_direction = rand() % 361;
            // Print out weather information for each hour
            printf("%02d:00: Temperature: %dC, Humidity: %d%%, Wind Speed: %dm/s, Wind Direction: %d degrees\n", j, temp, humidity, wind_speed, wind_direction);
        }
    }

    return 0;
}