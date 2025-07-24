//FormAI DATASET v1.0 Category: Smart home automation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define global variables
int temperature = 0;
int motion_detected = 0;

// Function to toggle lights on and off
void toggle_lights() {
    static int lights_on = 0;
    if (lights_on == 0) {
        printf("Turning lights on.\n");
        lights_on = 1;
    } else {
        printf("Turning lights off.\n");
        lights_on = 0;
    }
}

// Function to adjust temperature
void adjust_temperature() {
    if (temperature < 60) {
        printf("Raising temperature to 70 degrees.\n");
        temperature = 70;
    } else {
        printf("Lowering temperature to 60 degrees.\n");
        temperature = 60;
    }
}

// Function to alert homeowner of motion detection
void alert_homeowner() {
    printf("Motion detected! Alerting homeowner.\n");
}

int main() {
    // Simulate a smart home environment
    printf("Simulating smart home environment...\n");

    // Set initial temperature to 65 degrees
    temperature = 65;

    // Loop infinitely to simulate smart home behavior
    while (1) {
        // Check for motion detection
        if (motion_detected == 1) {
            alert_homeowner();
            motion_detected = 0;
        }

        // Check temperature and adjust if necessary
        if (temperature > 65) {
            adjust_temperature();
        }

        // Toggle lights on and off every 30 seconds
        static int seconds_passed = 0;
        if (seconds_passed == 30) {
            toggle_lights();
            seconds_passed = 0;
        }

        // Wait one second before checking again
        sleep(1);
        seconds_passed++;
    }

    return 0;
}