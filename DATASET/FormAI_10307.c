//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h> 
#include <stdint.h> 

int main() { 
    uint8_t temperature = 25; // initialize temperature to 25 degree Celsius
    uint8_t light_intensity = 70; // initialize light intensity to 70%
    uint8_t window_open = 0; // initialize window status to closed (0)

    printf("Welcome to the Smart Home Automation System!\n");

    // display current status
    printf("Current Temperature: %dC\n", temperature);
    printf("Current Light Intensity: %d%%\n", light_intensity);
    printf("Window Status: %s\n", window_open ? "Open" : "Closed");

    // update temperature and display new status
    temperature = 28;
    printf("Temperature updated to: %dC\n", temperature);

    // update light intensity and display new status
    light_intensity = 90;
    printf("Light Intensity updated to: %d%%\n", light_intensity);

    // open window and display new status
    window_open = 1;
    printf("Window Status updated to: %s\n", window_open ? "Open" : "Closed");

    // close window and display new status
    window_open = 0;
    printf("Window Status updated to: %s\n", window_open ? "Open" : "Closed");

    return 0; 
}