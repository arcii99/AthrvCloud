//FormAI DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, wind_speed;
    char weather_type[10], city[20];
    srand(time(0));
    
    printf("Enter the city name: ");
    scanf("%s", city);
    
    // Simulating temperature
    temperature = rand() % 50 + (-10);
    printf("Temperature in %s is %d degrees Celsius.\n", city, temperature);
    
    // Simulating humidity
    humidity = rand() % 100;
    printf("Humidity in %s is %d percent.\n", city, humidity);
    
    // Simulating wind speed
    wind_speed = rand() % 100;
    printf("Wind speed in %s is %d km/h.\n", city, wind_speed);
    
    // Simulating weather type
    switch(rand() % 4){
        case 0:
            strcpy(weather_type, "Sunny");
            break;
        case 1:
            strcpy(weather_type, "Cloudy");
            break;
        case 2:
            strcpy(weather_type, "Rainy");
            break;
        case 3:
            strcpy(weather_type, "Snowy");
            break;
    }
    printf("Weather in %s is %s.\n", city, weather_type);
    
    return 0;
}