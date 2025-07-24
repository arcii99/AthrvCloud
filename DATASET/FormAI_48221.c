//FormAI DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Seed the random number generator

    int temperature = rand() % 26 - 10; //Generate initial temperature between -10°C to 16°C
    int humidity = rand() % 101; //Generate initial humidity between 0% to 100%
    int pressure = rand() % 101 + 1000; //Generate initial pressure between 1000 hPa to 1100 hPa
    int wind_speed = rand() % 41; //Generate initial wind speed between 0 km/h to 40 km/h
    int wind_direction = rand() % 361; //Generate initial wind direction between 0° to 360°
    int precipitation = rand() % 11; //Generate initial precipitation between 0 mm to 10 mm
    
    printf("Initial weather conditions:\n");
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);
    printf("Wind speed: %d km/h\n", wind_speed);
    printf("Wind direction: %d°\n", wind_direction);
    printf("Precipitation: %d mm\n\n", precipitation);

    int i;
    for (i = 1; i <= 7; i++) { //Simulate weather for next 7 days
        int temp_change = rand() % 11 - 5; //Generate temperature change between -5°C to 5°C
        temperature += temp_change;
        temperature = (temperature < -10) ? -10 : ((temperature > 16) ? 16 : temperature); //Enforce bounds
        
        int hum_change = rand() % 11 - 5; //Generate humidity change between -5% to 5%
        humidity += hum_change;
        humidity = (humidity < 0) ? 0 : ((humidity > 100) ? 100 : humidity); //Enforce bounds
        
        int press_change = rand() % 11 - 5; //Generate pressure change between -5 hPa to 5 hPa
        pressure += press_change;
        pressure = (pressure < 1000) ? 1000 : ((pressure > 1100) ? 1100 : pressure); //Enforce bounds
        
        int wind_speed_change = rand() % 11 - 5; //Generate wind speed change between -5 km/h to 5 km/h
        wind_speed += wind_speed_change;
        wind_speed = (wind_speed < 0) ? 0 : ((wind_speed > 40) ? 40 : wind_speed); //Enforce bounds
        
        int wind_dir_change = rand() % 31 - 15; //Generate wind direction change between -15° to 15°
        wind_direction += wind_dir_change;
        wind_direction = (wind_direction < 0) ? wind_direction + 360 : ((wind_direction > 360) ? wind_direction - 360 : wind_direction); //Wrap around
        
        int precip_change = rand() % 6 - 2; //Generate precipitation change between -2 mm to 3 mm
        precipitation += precip_change;
        precipitation = (precipitation < 0) ? 0 : precipitation; //Enforce lower bound
        
        printf("Weather conditions for day %d:\n", i);
        printf("Temperature: %d°C\n", temperature);
        printf("Humidity: %d%%\n", humidity);
        printf("Pressure: %d hPa\n", pressure);
        printf("Wind speed: %d km/h\n", wind_speed);
        printf("Wind direction: %d°\n", wind_direction);
        printf("Precipitation: %d mm\n\n", precipitation);
    }

    return 0;
}