//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdbool.h>

#define MAX_TEMP 100
#define MIN_TEMP 30
#define MAX_HUMIDITY 80
#define MIN_HUMIDITY 20

int tempSensor() {
    int temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    return temp;
}

int humiditySensor() {
    int humidity = (rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1)) + MIN_HUMIDITY;
    return humidity;
}

bool motionSensor() {
    bool motionDetected;
    int random = (rand() % 100) + 1;
    if (random <= 20) {
        motionDetected = true;
    } else {
        motionDetected = false;
    }
    return motionDetected;
}

int main() {
    int temp = tempSensor();
    int humidity = humiditySensor();
    bool motionDetected = motionSensor();

    if (temp > MAX_TEMP) {
        printf("Temperature is too high! Turning on cooling system...\n");
        // TODO: Turn on cooling system
    } else if (temp < MIN_TEMP) {
        printf("Temperature is too low! Turning on heating system...\n");
        // TODO: Turn on heating system
    } else {
        printf("Temperature is okay.\n");
    }

    if (humidity > MAX_HUMIDITY) {
        printf("Humidity is too high! Turning on dehumidifier...\n");
        // TODO: Turn on dehumidifier
    } else if (humidity < MIN_HUMIDITY) {
        printf("Humidity is too low! Turning on humidifier...\n");
        // TODO: Turn on humidifier
    } else {
        printf("Humidity is okay.\n");
    }

    if (motionDetected) {
        printf("Motion detected! Turning on alarm...\n");
        // TODO: Turn on alarm
    } else {
        printf("No motion detected.\n");
    }

    return 0;
}