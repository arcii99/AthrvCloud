//FormAI DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    // Initializing temperature variables
    double temperature = 10.0, humidity = 50.0;
    double max_temp = 40.0, min_temp = -20.0;
    double max_humidity = 100.0, min_humidity = 0.0;

    // Initializing other variables
    int day = 1, month = 1, year = 2021;
    char weather_condition[10];

    while(day <= 31){
        
        // Generate a random temperature and humidity value
        double temp_change = ((double) rand() / RAND_MAX) * 5.0 - 2.5;
        temperature += temp_change;
        humidity += ((double) rand() / RAND_MAX) * 10.0 - 5.0;

        // Limit the temperature and humidity values
        if (temperature > max_temp) {
            temperature = max_temp;
        }else if(temperature < min_temp){
            temperature = min_temp;
        }

        if (humidity > max_humidity) {
            humidity = max_humidity;
        }else if(humidity < min_humidity){
            humidity = min_humidity;
        }

        // Determine the weather condition based on temperature and humidity values
        if (temperature >= 35.0 && humidity >= 70.0) {
            snprintf(weather_condition, 10, "Hot & Humid");
        }else if (temperature >= 30.0 && temperature < 35.0 && humidity >= 60.0) {
            snprintf(weather_condition, 10, "Warm & Humid");
        }else if (temperature >= 25.0 && temperature < 30.0 && humidity >= 50.0) {
            snprintf(weather_condition, 10, "Mild & Humid");
        }else if (temperature >= 20.0 && temperature < 25.0 && humidity < 50.0) {
            snprintf(weather_condition, 10, "Mild & Dry");
        }else if (temperature >= 15.0 && temperature < 20.0 && humidity < 40.0) {
            snprintf(weather_condition, 10, "Cool & Dry");
        }else{
            snprintf(weather_condition, 10, "Cold & Dry");
        }

        // Print the weather for the current day
        printf("%02d/%02d/%d - Temperature: %.1lfC, Humidity: %.1lf%%, Condition: %s\n",
                day, month, year, temperature, humidity, weather_condition);

        // Increment day value
        day++;
    }

    return 0;
}