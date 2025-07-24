//FormAI DATASET v1.0 Category: Weather simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 7

typedef struct {
    int max_temp;
    int min_temp;
    int humidity;
    int wind_speed;
} climate;

// Function to simulate the weather
void simulate_weather(climate arr[]) {
    int max, min, h, w;
    srand(time(0)); // Seed for random number generator

    // Generate random weather data for each day of the week
    for(int i = 0; i < DAYS; i++) {
        max = rand() % 30 + 20; // Temperatures between 20 to 50 degrees Celsius
        min = rand() % (max - 10) + 10; // Minimum temperature is 10 degrees lower than max temperature
        h = rand() % 70 + 30; // Humidity between 30% to 100%
        w = rand() % 20 + 5; // Wind speed between 5 to 25 Kmph

        // Assign the generated values to the climate structure
        arr[i].max_temp = max;
        arr[i].min_temp = min;
        arr[i].humidity = h;
        arr[i].wind_speed = w;
    }
}

// Function to display the weather data
void display_weather(climate arr[]) {
    printf("Weather data for the week:\n");
    printf("\n");
    printf("Day\tMax Temp(C)\tMin Temp(C)\tHumidity(%%)\tWind Speed(Kmph)\n");
    
    // Loop through the weather data and display it line by line
    for(int i = 0; i < DAYS; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arr[i].max_temp, arr[i].min_temp, arr[i].humidity, arr[i].wind_speed);
    }
}

int main() {
    climate weather[DAYS]; // Initialize array of climate structures
    simulate_weather(weather); // Call function to generate weather data
    display_weather(weather); // Call function to display weather data
    return 0;
}