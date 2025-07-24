//FormAI DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure to represent a weather forecast 
struct WeatherForecast{
    int temperature;
    int humidity;
    int pressure;
};

// function to generate a random weather forecast
struct WeatherForecast generateWeatherForecast(){
    struct WeatherForecast forecast;
    forecast.temperature = rand() % 101; 
    forecast.humidity = rand() % 101; 
    forecast.pressure = rand() % 101; 
    return forecast;
}

int main(){
    srand(time(NULL)); // seed the random number generator with system time
    
    printf("Welcome to the Futuristic Weather Simulator\n");
    printf("Generating weather forecast...\n\n");
    
    struct WeatherForecast forecast = generateWeatherForecast();
    
    printf("Today's Forecast:\n");
    printf("Temperature: %d degrees Celsius\n", forecast.temperature);
    printf("Humidity: %d percent\n", forecast.humidity);
    printf("Pressure: %d millibars\n", forecast.pressure);
    
    if(forecast.temperature >= 25 && forecast.humidity >= 60){
        printf("\nWarning: High temperature and humidity levels could cause health issues.\n");
    }
    else if(forecast.temperature <= 5){
        printf("\nWarning: Low temperature could cause hypothermia.\n");
    }
    else{
        printf("\nConditions are normal.\n");
    }
    
    return 0;
}