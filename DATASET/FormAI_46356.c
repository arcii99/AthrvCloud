//FormAI DATASET v1.0 Category: Weather simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Initializing variables
    int rain_prob, temp, humidity;
    char weather_type[20];

    // Setting the seed for rand()
    srand(time(0));

    // Generating random values for temperature and humidity
    temp = rand() % 41; // Temperature can range from 0 to 40 degrees Celsius
    humidity = rand() % 101; // Humidity can range from 0% to 100%
    
    // Deciding the weather type based on temperature and humidity
    if(temp >= 30 && humidity >= 60){
        strcpy(weather_type, "Thunderstorm"); // High temp and humidity - Thunderstorm
        rain_prob = 80; // High chance of rain during thunderstorms
    }
    else if(temp >= 25 && humidity >= 70){
        strcpy(weather_type, "Rain"); // High humidity with moderate temperature - Rain
        rain_prob = 60; // Moderate chance of rain during rainy weather
    }
    else if(temp >= 20 && humidity >= 50){
        strcpy(weather_type, "Cloudy"); // Moderate temp and humidity - Cloudy
        rain_prob = 30; // Low chance of rain during cloudy weather
    }
    else{
        strcpy(weather_type, "Sunny"); // Low temp and humidity - Sunny
        rain_prob = 10; // Very low chance of rain during sunny weather
    }

    // Displaying the weather information to the user
    printf("Weather Type: %s\n", weather_type);
    printf("Temperature: %d degrees Celsius\n", temp);
    printf("Humidity: %d%%\n", humidity);

    // Deciding whether it will rain or not based on the rain probability
    if(rand()%101 <= rain_prob)
        printf("It is raining!\n");
    else
        printf("It is not raining.\n");

    return 0;
}