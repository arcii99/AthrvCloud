//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
// SMART HOME LIGHT CONTROL EXAMPLE PROGRAM
// By: [Your Name]
// Date: [Date]

#include<stdio.h>
#include<stdlib.h>

int main() {
    // Declare and initialize variables
    int current_time = 0;
    int light_status = 0;
    int light_intensity = 0;
    int motion_sensor_status = 0;

    // Loop for 24 hours
    for(int i = 0; i < 24; i++) {

        // Get current time
        printf("Current time is %d\n", current_time);
        current_time++;

        // Check motion sensor status
        motion_sensor_status = rand() % 2;
        if(motion_sensor_status == 1) {
            printf("Motion detected! Turning on lights.\n");
            light_status = 1;
            light_intensity = 100;
        } else {
            printf("No motion detected. Turning off lights.\n");
            light_status = 0;
            light_intensity = 0;
        }

        // Adjust light intensity based on time
        if(current_time >=6 && current_time < 12) {
            printf("It's morning. Setting light intensity to 70.\n");
            light_intensity = 70;
        } else if(current_time >= 12 && current_time < 18) {
            printf("It's afternoon. Setting light intensity to 80.\n");
            light_intensity = 80;
        } else if(current_time >= 18 && current_time < 22) {
            printf("It's evening. Setting light intensity to 60.\n");
            light_intensity = 60;
        } else {
            printf("It's night. Setting light intensity to 50.\n");
            light_intensity = 50;
        }

        // Set light intensity
        if(light_status == 1) {
            printf("Setting light intensity to %d\n", light_intensity);
        }

        // Wait for one hour
        printf("Time passed. Waiting for one hour...\n");
        printf("\n");
    }

    return 0;
}