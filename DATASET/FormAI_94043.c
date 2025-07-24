//FormAI DATASET v1.0 Category: Weather simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature, humidity;
    char weather[20];
    
    srand(time(0));
    temperature = rand() % 101 - 50; // generate a random temperature between -50 and 50 Celsius
    humidity = rand() % 101; // generate a random humidity between 0% and 100%
    
    if (temperature <= 0) {
        if (humidity < 50) {
            sprintf(weather, "It's cold and dry outside.");
        } else {
            sprintf(weather, "It's cold and humid outside.");
        }
    } else if (temperature <= 20) {
        if (humidity < 50) {
            sprintf(weather, "It's cool and dry outside.");
        } else {
            sprintf(weather, "It's cool and humid outside.");
        }
    } else if (temperature <= 30) {
        if (humidity < 50) {
            sprintf(weather, "It's warm and dry outside.");
        } else {
            sprintf(weather, "It's warm and humid outside.");
        }
    } else {
        if (humidity < 50) {
            sprintf(weather, "It's hot and dry outside.");
        } else {
            sprintf(weather, "It's hot and humid outside.");
        }
    }
    
    printf("%d degrees Celsius and %d%% humidity. %s\n", temperature, humidity, weather);
    
    return 0;
}