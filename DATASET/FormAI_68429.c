//FormAI DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); // initialize random seed
    
    int temperature = (rand() % 41) - 20; // generate a random temperature between -20°C and 20°C
    int humidity = rand() % 101; // generate a random humidity between 0% and 100%
    int windSpeed = rand() % 101; // generate a random wind speed between 0 km/h and 100 km/h
    
    // print the current weather conditions
    printf("Current temperature: %d°C\n", temperature);
    printf("Current humidity: %d%%\n", humidity);
    printf("Current wind speed: %d km/h\n", windSpeed);
    
    // calculate the perceived temperature (wind chill)
    float perceivedTemperature;
    if (temperature <= 10 && windSpeed > 4.8){
        perceivedTemperature = 13.12 + (0.6215 * temperature) - (11.37 * pow(windSpeed, 0.16)) + (0.3965 * temperature * pow(windSpeed, 0.16));
        printf("Perceived temperature (wind chill): %.2f°C\n", perceivedTemperature);
    }
    
    // calculate the heat index
    float heatIndex;
    if (temperature >= 26){
        heatIndex = -8.784695 + (1.61139411 * temperature) + (2.338549 * humidity) - (0.14611605 * temperature * humidity) - (0.012308094 * pow(temperature, 2)) - (0.016424828 * pow(humidity, 2)) + (0.002211732 * pow(temperature, 2) * humidity) + (0.00072546 * temperature * pow(humidity, 2)) - (0.000003582 * pow(temperature, 2) * pow(humidity, 2));
        printf("Heat index: %.2f°C\n", heatIndex);
    }
    
    return 0;
}