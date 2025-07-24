//FormAI DATASET v1.0 Category: Smart home automation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int temp_sensor = 0;
    int light_sensor = 0;
    int fan_speed = 0;
    int bulb_brightness = 0;
    int room_temp = 0;
    int room_light = 0;

    // Simulate temperature and light sensor values
    temp_sensor = rand() % 101; // Values range from 0 to 100
    light_sensor = rand() % 101;

    // Determine room temperature and light
    if (temp_sensor < 20) {
        room_temp = 1; // Cold
    } else if (temp_sensor >= 20 && temp_sensor <= 25) {
        room_temp = 2; // Comfortable
    } else {
        room_temp = 3; // Hot
    }

    if (light_sensor < 30) {
        room_light = 1; // Dark
    } else if (light_sensor >= 30 && light_sensor <= 80) {
        room_light = 2; // Dim
    } else {
        room_light = 3; // Bright
    }

    // Adjust fan speed based on temperature
    if (room_temp == 1) {
        fan_speed = 3; // High
    } else if (room_temp == 2) {
        fan_speed = 2; // Medium
    } else {
        fan_speed = 1; // Low
    }

    // Adjust bulb brightness based on light
    if (room_light == 1) {
        bulb_brightness = 3; // Bright
    } else if (room_light == 2) {
        bulb_brightness = 2; // Dim
    } else {
        bulb_brightness = 1; // Off
    }

    // Output the current room conditions
    printf("Current room conditions:\n");
    printf("Temperature: %d\n", temp_sensor);
    printf("Light level: %d\n", light_sensor);
    printf("Fan speed: %d\n", fan_speed);
    printf("Bulb brightness: %d\n", bulb_brightness);

    // If temperature is too high, turn on air conditioning
    if (room_temp == 3) {
        printf("Temperature is too high. Turning on air conditioning.\n");
        // Code to turn on air conditioning goes here
    }

    // If light level is too low, turn on hallway light
    if (room_light == 1) {
        printf("Light level is too low. Turning on hallway light.\n");
        // Code to turn on hallway light goes here
    }

    return 0;
}