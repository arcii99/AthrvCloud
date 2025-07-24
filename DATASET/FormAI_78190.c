//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

/* Configurable Variables */

// Time to turn off the lights in seconds (default: 120 seconds)
int time_to_turn_off = 120;

// Temperature threshold to turn on the fan (default: 25°C)
float temperature_threshold = 25.0;

// Humidity threshold to turn on the dehumidifier (default: 70%)
float humidity_threshold = 70.0;

/* End of Configurable Variables */

int main() {
    int lights_on = 0;
    int fan_on = 0;
    int dehumidifier_on = 0;

    float current_temperature = 23.5;
    float current_humidity = 65.0;

    int time_elapsed = 0;
    int motion_sensor_detected = 0;

    // Main loop
    while (1) {
        // Get sensor readings (in a real implementation, this would be done using sensors)
        if (time_elapsed % 10 == 0) {
            current_temperature += 0.5;
            current_humidity += 1.0;
        }

        // Check motion sensor (in a real implementation, this would be done using a motion sensor)
        if (time_elapsed % 30 == 0) {
            motion_sensor_detected = 1;
        } else {
            motion_sensor_detected = 0;
        }

        // Turn off lights after a certain amount of time
        if (lights_on && time_elapsed > time_to_turn_off) {
            printf("Turning off lights.\n");
            lights_on = 0;
        }

        // Turn on fan if temperature is above threshold
        if (current_temperature > temperature_threshold && !fan_on) {
            printf("Turning on fan.\n");
            fan_on = 1;
        } else if (current_temperature <= temperature_threshold && fan_on) {
            printf("Turning off fan.\n");
            fan_on = 0;
        }

        // Turn on dehumidifier if humidity is above threshold
        if (current_humidity > humidity_threshold && !dehumidifier_on) {
            printf("Turning on dehumidifier.\n");
            dehumidifier_on = 1;
        } else if (current_humidity <= humidity_threshold && dehumidifier_on) {
            printf("Turning off dehumidifier.\n");
            dehumidifier_on = 0;
        }

        // Turn on lights if motion is detected
        if (motion_sensor_detected && !lights_on) {
            printf("Turning on lights.\n");
            lights_on = 1;
        }

        // Sleep for 1 second
        time_elapsed += 1;
        sleep(1);
    }

    return 0;
}