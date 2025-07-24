//FormAI DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to check if the door or window is open
bool is_open(int sensor_reading) {
    if (sensor_reading > 50) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int door_sensor = 40; // assume door sensor reading of 40
    int window_sensor = 60; // assume window sensor reading of 60

    bool door_open = is_open(door_sensor);
    bool window_open = is_open(window_sensor);

    if (door_open) {
        printf("Door is open. Turning on the lights.\n");
        // code to turn on lights
    } else {
        printf("Door is closed. Checking windows.\n");
        if (window_open) {
            printf("Window is open. Turning off the AC.\n");
            // code to turn off AC
        } else {
            printf("Window is closed. Everything is fine.\n");
        }
    }

    return 0;
}