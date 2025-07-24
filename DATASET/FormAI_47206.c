//FormAI DATASET v1.0 Category: Weather simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 50;
    int humidity = rand() % 100;
    int windspeed = rand() % 50 + 1;

    printf("Welcome to the Weather Simulator!\n\n");

    if (temperature <= 10) {
        printf("Current temperature: %d°C. It's freezing outside, dress warmly!\n", temperature);
    } else if (temperature >= 30) {
        printf("Current temperature: %d°C. It's scorching outside, stay hydrated!\n", temperature);
    } else {
        printf("Current temperature: %d°C. It's a pleasant day outside.\n", temperature);
    }

    if (humidity <= 30) {
        printf("Current humidity: %d%%. It's dry outside, use moisturizer!\n", humidity);
    } else if (humidity >= 60) {
        printf("Current humidity: %d%%. It's humid outside, drink water regularly!\n", humidity);
    } else {
        printf("Current humidity: %d%%. It's a nice day outside.\n", humidity);
    }

    if (windspeed <= 10) {
        printf("Current windspeed: %d km/h. It's calm outside, enjoy the breeze!\n", windspeed);
    } else if (windspeed >= 30) {
        printf("Current windspeed: %d km/h. It's windy outside, hold onto your hats!\n", windspeed);
    } else {
        printf("Current windspeed: %d km/h. It's a peaceful day outside.\n", windspeed);
    }

    printf("\nThanks for using the Weather Simulator! Stay safe and be prepared!");

    return 0;
}