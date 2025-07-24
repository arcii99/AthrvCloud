//FormAI DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int current_weather = rand() % 4; // 0 = sunny, 1 = cloudy, 2 = rainy, 3 = snowy
    printf("Current Weather: ");
    switch(current_weather) {
        case 0: printf("Sunny\n"); break;
        case 1: printf("Cloudy\n"); break;
        case 2: printf("Rainy\n"); break;
        case 3: printf("Snowy\n"); break;
    }
    int temperature = rand() % 71 - 20; // Random temperature between -20 and 50 Celsius
    printf("Temperature: %d Celsius\n", temperature);
    if(current_weather == 2 || current_weather == 3) {
        int wind_speed = rand() % 101; // Random wind speed between 0 and 100 km/h
        printf("Wind Speed: %d km/h\n", wind_speed);
    }
    if(current_weather == 2) {
        int humidity = rand() % 101; // Random humidity between 0 and 100 percent
        printf("Humidity: %d %%\n", humidity);
    }
    if(current_weather == 3) {
        int snow_depth = rand() % 51 + 10; // Random snow depth between 10 and 60 cm
        printf("Snow Depth: %d cm\n", snow_depth);
    }
    return 0;
}