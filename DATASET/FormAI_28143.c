//FormAI DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL)); // seed for random number generator
    
    int temperature = (rand() % (100 - 50 + 1)) + 50; // generate random temperature between 50 and 100 degrees
    
    int humidity = (rand() % (100 - 50 + 1)) + 50; // generate random humidity between 50% and 100%
    
    int windSpeed = (rand() % (20 - 5 + 1)) + 5; // generate random wind speed between 5 and 20 mph
    
    int cloudCover = (rand() % (80 - 20 + 1)) + 20; // generate random cloud cover between 20% and 80%
    
    printf("Temperature: %d degrees Fahrenheit\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d mph\n", windSpeed);
    printf("Cloud Cover: %d%%\n", cloudCover);
    
    if (temperature >= 90) {
        printf("It is extremely hot outside. Please stay hydrated!\n");
    } else if (temperature >= 80) {
        printf("It is hot outside. Wear light clothes!\n");
    } else if (temperature >= 70) {
        printf("It is warm outside. Enjoy the weather!\n");
    } else if (temperature >= 60) {
        printf("It is a bit chilly. Consider bringing a jacket!\n");
    } else {
        printf("It is very cold outside. Dress warmly!\n");
    }
    
    if (humidity >= 80) {
        printf("It is very humid outside. Be prepared to sweat!\n");
    } else if (humidity >= 60) {
        printf("It is moderately humid outside. You may feel sticky!\n");
    } else if (humidity >= 40) {
        printf("It is not very humid outside. Enjoy the dry air!\n");
    } else {
        printf("It is extremely dry outside. Don't forget to drink water!\n");
    }
    
    if (windSpeed >= 15) {
        printf("It is very windy outside. Hold onto your hat!\n");
    } else if (windSpeed >= 10) {
        printf("It is a bit windy outside. You may feel a breeze!\n");
    } else if (windSpeed >= 5) {
        printf("It is not very windy outside. The air is calm!\n");
    } else {
        printf("There is no wind outside. The air is still!\n");
    }
    
    if (cloudCover >= 70) {
        printf("It is very cloudy outside. You may expect rain!\n");
    } else if (cloudCover >= 40) {
        printf("It is partially cloudy outside. The sky is beautiful!\n");
    } else {
        printf("There are only a few clouds outside. It's a perfect day!\n");
    }
    
    return 0;
}