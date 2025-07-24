//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int temperature, humidity, pressure;
    char* weather_type;
    double wind_speed, wind_direction;
    
    srand(time(NULL)); // Seed the random number generator with the current time
    
    // Generate random values for temperature, humidity, pressure, wind speed, and wind direction
    temperature = rand() % 60 - 20; // Temperature range: -20°C to 40°C
    humidity = rand() % 100; // Humidity range: 0% to 100%
    pressure = rand() % 1000 + 90000; // Pressure range: 90000 Pa to 90999 Pa
    wind_speed = rand() % 100; // Wind speed range: 0 m/s to 100 m/s
    wind_direction = rand() % 360; // Wind direction range: 0° to 359°
    
    // Determine the weather type based on the values of temperature, humidity, and pressure
    if(temperature < 0){
        weather_type = "Snow";
    }else if(temperature >= 0 && temperature < 10){
        weather_type = "Rainy";
    }else if(temperature >= 10 && temperature < 20){
        if(humidity >= 50){
            weather_type = "Thunderstorms";
        }else{
            weather_type = "Partly cloudy";
        }
    }else if(temperature >= 20 && temperature < 30){
        if(humidity >= 75){
            weather_type = "Heavy rain";
        }else{
            weather_type = "Sunny";
        }
    }else{
        weather_type = "Heat wave";
    }
    
    // Print out the generated values and weather type
    printf("Temperature: %d°C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d Pa\n", pressure);
    printf("Wind speed: %.2f m/s\n", wind_speed);
    printf("Wind direction: %.2f°\n", wind_direction);
    printf("Weather type: %s\n", weather_type);
    
    return 0;
}