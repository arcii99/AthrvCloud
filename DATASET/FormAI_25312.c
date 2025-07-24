//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    float temperature = ((float)rand()/(float)(RAND_MAX)) * 50 - 15;
    float humidity = ((float)rand()/(float)(RAND_MAX)) * 100;
    float windSpeed = ((float)rand()/(float)(RAND_MAX)) * 30;
    
    printf("Temperature: %.2fC\n", temperature);
    printf("Humidity: %.2f%%\n", humidity);
    printf("Wind Speed: %.2fkm/h\n", windSpeed);
    
    if (temperature < 0) {
        printf("It is very cold outside. Make sure to wear warm clothes!\n");
    } else if (temperature >= 0 && temperature < 10) {
        printf("It is cold outside. Wear a jacket for extra warmth!\n");
    } else if (temperature >= 10 && temperature < 20) {
        printf("The temperature is mild. You should be comfortable in thin clothing.\n");
    } else if (temperature >= 20 && temperature < 30) {
        printf("It is warm outside. Wear light clothing!\n");
    } else {
        printf("It is very hot outside. Make sure to stay hydrated and wear sunscreen!\n");
    }
    
    if (humidity < 30) {
        printf("The air is very dry. Consider using moisturizer or a humidifier if necessary.\n");
    } else if (humidity >= 30 && humidity <= 60) {
        printf("The humidity level is comfortable. Enjoy the fresh air!\n");
    } else {
        printf("The air is very humid. Be careful not to get too sweaty or overheated!\n");
    }
    
    if (windSpeed < 5) {
        printf("There is not much wind today. Enjoy the calm weather!\n");
    } else if (windSpeed >= 5 && windSpeed <= 15) {
        printf("There is a gentle breeze in the air. Perfect for outdoor activities!\n");
    } else {
        printf("The wind is blowing quite strongly. Be careful not to get blown away!\n");
    }
    
    return 0;
}