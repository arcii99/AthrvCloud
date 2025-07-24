//FormAI DATASET v1.0 Category: Weather simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void weatherCondition(float temperature, float humidity, float pressure) {
    if (temperature < 0 && humidity > 80 && pressure < 1000) {
        printf("The weather is likely to be snowy and stormy.\n");
    } else if (temperature < 0 && humidity < 50 && pressure > 1000) {
        printf("The weather is likely to be sunny but cold.\n");
    } else if (temperature > 20 && humidity > 60 && pressure > 1000) {
        printf("The weather is likely to be hot and humid.\n");
    } else if (temperature > 30 && humidity < 40 && pressure > 1013) {
        printf("The weather is likely to be extremely hot and dry.\n");
    } else {
        printf("The weather is likely to be normal.\n");
    }
}

void generateWeather() {
    srand((unsigned) time(NULL)); // sets seed for random number generator
    float temperature = (float) rand() / (float) (RAND_MAX / 40); // generates temperature between 0 to 40 degree Celsius
    float humidity = (float) rand() / (float) (RAND_MAX / 100); // generates humidity between 0 to 100
    float pressure = (float) rand() / (float) (RAND_MAX / 1013); // generates pressure between 0 to 1013 hPa
    printf("Temperature: %.2fC\n", temperature);
    printf("Humidity: %.2f%%\n", humidity);
    printf("Pressure: %.2fhPa\n", pressure);
    weatherCondition(temperature, humidity, pressure); // calls weatherCondition function with generated values
}

int main() {
    printf("Generating weather condition...\n");
    generateWeather(); // call generateWeather function
    return 0;
}