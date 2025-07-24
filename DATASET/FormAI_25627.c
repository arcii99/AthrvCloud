//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = (rand() % (50 - (-50) + 1)) + (-50); //generate temperature between -50°C to 50°C
    float humidity = ((float) rand() / RAND_MAX) * 100; //generate humidity between 0% to 100%
    char weatherDescription[50];

    if (temperature >= 30 && humidity >= 60) {
        sprintf(weatherDescription, "It's hot and humid outside! Temperature: %d°C, Humidity: %.2f%%", temperature, humidity);
    } else if (temperature >= 20 && temperature < 30 && humidity <= 50) {
        sprintf(weatherDescription, "It's a sunny day! Temperature: %d°C, Humidity: %.2f%%", temperature, humidity);
    } else if (temperature >= 10 && temperature < 20 && humidity <= 50) {
        sprintf(weatherDescription, "It's a beautiful day! Temperature: %d°C, Humidity: %.2f%%", temperature, humidity);
    } else if (temperature >= -10 && temperature < 10 && humidity <= 50) {
        sprintf(weatherDescription, "It's a chilly day! Temperature: %d°C, Humidity: %.2f%%", temperature, humidity);
    } else if (temperature < -10 && humidity <= 50) {
        sprintf(weatherDescription, "It's freezing outside! Temperature: %d°C, Humidity: %.2f%%", temperature, humidity);
    } else {
        printf("Invalid weather condition!");
        exit(1);
    }

    printf("%s", weatherDescription);
    return 0;
}