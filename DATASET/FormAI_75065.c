//FormAI DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float getTemperature();
float getHumidity();
float getWindSpeed();
float getAirPressure();
char *getWeatherCondition(float temperature, float humidity, float windSpeed, float airPressure);

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // retrieve weather data
    float temperature = getTemperature();
    float humidity = getHumidity();
    float windSpeed = getWindSpeed();
    float airPressure = getAirPressure();
    
    // determine weather condition based on retrieved weather data
    char *weatherCondition = getWeatherCondition(temperature, humidity, windSpeed, airPressure);
    
    // print out retrieved weather data and resulting condition
    printf("Temperature: %.2f °F\n", temperature);
    printf("Humidity: %.2f %%\n", humidity);
    printf("Wind Speed: %.2f mph\n", windSpeed);
    printf("Air Pressure: %.2f inHg\n", airPressure);
    printf("Weather Condition: %s\n", weatherCondition);
    
    return 0;
}

float getTemperature() {
    // generate random temperature between -40 and 120 Fahrenheit
    float temperature = rand() % 161 - 40;
    return temperature;
}

float getHumidity() {
    // generate random humidity between 0 and 100%
    float humidity = rand() % 101;
    return humidity;
}

float getWindSpeed() {
    // generate random wind speed between 0 and 60 mph
    float windSpeed = rand() % 61;
    return windSpeed;
}

float getAirPressure() {
    // generate random air pressure between 28 and 32 inHg
    float airPressure = ((float)rand() / RAND_MAX) * 4 + 28;
    return airPressure;
}

char *getWeatherCondition(float temperature, float humidity, float windSpeed, float airPressure) {
    // check temperature and humidity to determine if it's raining or snowing
    if (temperature <= 32) {
        if (humidity >= 50) {
            return "Snow";
        } else {
            return "Clear";
        }
    } else if (temperature > 32 && temperature < 50) {
        if (humidity >= 80) {
            return "Snow";
        } else if (humidity >= 50 && humidity < 80) {
            return "Rain";
        } else {
            return "Clear";
        }
    } else if (temperature >= 50 && temperature < 70) {
        if (humidity >= 80) {
            return "Rain";
        } else if (humidity >= 50 && humidity < 80) {
            return "Cloudy";
        } else {
            return "Clear";
        }
    } else if (temperature >= 70 && temperature < 90) {
        if (windSpeed >= 20) {
            return "Windy";
        } else if (humidity >= 50 && humidity < 80) {
            return "Sunny";
        } else if (humidity < 50) {
            return "Clear";
        } else {
            return "Cloudy";
        }
    } else {
        if (windSpeed >= 30) {
            return "Hurricane";
        } else if (humidity >= 50 && humidity < 80) {
            return "Sunny";
        } else if (humidity < 50) {
            return "Clear";
        } else {
            return "Cloudy";
        }
    }
}