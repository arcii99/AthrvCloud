//FormAI DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

// Structure to hold the state of the devices in the smart home
typedef struct {
    bool motion_sensor;
    bool door_sensor;
    bool lights_on;
    bool music_on;
} SmartHomeState;

// Global variable to represent the current state of the smart home
SmartHomeState current_state;

// Function to handle motion detection
void handle_motion_detection() {
    printf("Motion Detected!\n");
    current_state.motion_sensor = true;
    current_state.lights_on = true;
    current_state.music_on = true;
}

// Function to handle door sensor
void handle_door_sensor() {
    printf("Door opened!\n");
    current_state.door_sensor = true;
    current_state.lights_on = true;
    current_state.music_on = false;
}

// Thread function to continuously monitor the state of the smart home
void* monitor_smart_home(void* arg) {
    while (true) {
        // Check if motion sensor or door sensor is activated
        if (current_state.motion_sensor) {
            printf("Turning off lights and music after 5 seconds\n");
            sleep(5);
            current_state.motion_sensor = false;
            current_state.lights_on = false;
            current_state.music_on = false;
        } else if (current_state.door_sensor) {
            printf("Turning off lights and music after 10 seconds\n");
            sleep(10);
            current_state.door_sensor = false;
            current_state.lights_on = false;
            current_state.music_on = false;
        }

        // Check if lights or music is turned on/off
        if (current_state.lights_on) {
            printf("Turning on lights\n");
        } else {
            printf("Turning off lights\n");
        }

        if (current_state.music_on) {
            printf("Playing music\n");
        } else {
            printf("Stopping music\n");
        }

        sleep(1);
    }
}

int main() {
    // Initialize the current state of the smart home
    current_state.motion_sensor = false;
    current_state.door_sensor = false;
    current_state.lights_on = false;
    current_state.music_on = false;

    // Start the thread to monitor the state of the smart home
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor_smart_home, NULL);

    // Loop to simulate activity in the smart home
    while (true) {
        // Simulate motion detection and door opening randomly
        int random_num = rand() % 10;
        if (random_num == 0 && !current_state.motion_sensor && !current_state.door_sensor) {
            handle_motion_detection();
        } else if (random_num == 1 && !current_state.door_sensor && !current_state.motion_sensor) {
            handle_door_sensor();
        }

        sleep(1);
    }

    // Join the thread
    pthread_join(monitor_thread, NULL);

    return 0;
}