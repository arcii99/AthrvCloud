//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature, humidity, light_intensity, smoke_detected;

    //Initializing random seed
    srand(time(NULL));

    //Simulating temperature, humidity, and light intensity readings
    temperature = rand() % 30 + 20;
    humidity = rand() % 60 + 40;
    light_intensity = rand() % 500 + 500;

    //Simulating smoke detection
    smoke_detected = rand() % 2;

    //Displaying current readings
    printf("Current Readings:\n");
    printf("Temperature: %d C\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Light intensity: %d lux\n", light_intensity);
    printf("Smoke detected: %s\n", smoke_detected ? "Yes" : "No");

    //Automating the smart home based on current readings
    printf("\nSmart Home Automation:\n");

    if (temperature > 25) {
        printf("Turning on air conditioning..\n");
    }

    if (humidity > 70) {
        printf("Turning on dehumidifier..\n");
    }

    if (light_intensity < 1000) {
        printf("Turning on lights..\n");
    } else {
        printf("Turning off lights..\n");
    }

    if (smoke_detected) {
        printf("Alerting fire department..\n");
    }

    return 0;
}