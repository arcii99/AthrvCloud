//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define macros for easier code readability
#define LIGHT_PIN 11
#define TEMP_SENSOR_PIN 12
#define HUMIDITY_SENSOR_PIN 13

#define MAX_TEMP 25
#define MIN_HUMIDITY 40

// Function to check if the light should turn on based on the time of day
bool isDaytime(int hour) {
    return (hour >= 7 && hour <= 18); // Daytime is from 7AM to 6PM
}

int main() {
    int hour, temperature, humidity;
    bool lightOn = false;

    // Simulate getting the hour from a real-time clock (RTC)
    hour = 12;

    // Simulate getting the temperature and humidity from sensors
    temperature = 20; // Degrees Celsius
    humidity = 50; // Percentage

    if (isDaytime(hour)) {
        // If it's daytime, turn on the light if the temperature is below a certain threshold
        if (temperature < MAX_TEMP) {
            lightOn = true;
        }
    } else {
        // If it's nighttime, turn on the light if the temperature is below a certain threshold and the humidity is above a certain threshold
        if (temperature < MAX_TEMP && humidity > MIN_HUMIDITY) {
            lightOn = true;
        }
    }

    if (lightOn) {
        // Turn on the light using GPIO output
        printf("Turning on light...\n");
    } else {
        // Turn off the light using GPIO output
        printf("Turning off light...\n");
    }

    return 0;
}