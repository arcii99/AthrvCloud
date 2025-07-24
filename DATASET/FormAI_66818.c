//FormAI DATASET v1.0 Category: Smart home automation ; Style: curious
// Welcome to the curious world of smart home automation!
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int timeOfDay;
    int temperature;
    int humidity;
    int presence;
    int security;

    srand(time(0)); // Seed for randomization

    // Determine time of day
    timeOfDay = rand() % 2; // 0 for day, 1 for night

    // Determine temperature and humidity
    temperature = rand() % 20 + 20; // Temperature between 20C and 40C
    humidity = rand() % 50 + 50; // Humidity between 50% and 100%

    // Determine presence of occupants
    presence = rand() % 2; // 0 for no presence, 1 for presence

    // Determine security status
    security = rand() % 2; // 0 for off, 1 for on

    // Display status to user
    printf("Current status of the smart home:\n");
    if(timeOfDay == 0) {
        printf("Time of day: Day\n");
    }
    else {
        printf("Time of day: Night\n");
    }
    printf("Temperature: %dC\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    if(presence == 0) {
        printf("Occupants: No presence\n");
    }
    else {
        printf("Occupants: Presence detected\n");
    }
    if(security == 0) {
        printf("Security: Off\n");
    }
    else {
        printf("Security: On\n");
    }

    // Automation rules based on status
    if(timeOfDay == 0 && temperature >= 25) {
        printf("Turning on air conditioning...\n");
        // Code to turn on air conditioning
    }
    if(timeOfDay == 1 && temperature <= 20) {
        printf("Turning on heater...\n");
        // Code to turn on heater
    }
    if(humidity >= 80) {
        printf("Turning on dehumidifier...\n");
        // Code to turn on dehumidifier
    }
    if(presence == 1 && security == 0) {
        printf("Turning on security system...\n");
        // Code to turn on security system
    }

    return 0;
}