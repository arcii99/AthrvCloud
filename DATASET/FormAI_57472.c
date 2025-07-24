//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int temperature = 0;
    int min_temperature = 100;
    int max_temperature = -100;
    int sensor_count = 3;

    printf("Initializing temperature sensors...\n");
    printf("Scanning for available sensors...\n");

    // Initialize sensor array
    int sensors[sensor_count];

    for (int i = 1; i <= sensor_count; i++) {
        sensors[i-1] = i;
        printf("Found sensor #%d\n", i);
    }

    printf("Press any key to start monitoring...\n");
    getchar();

    while (1) {
        // Simulate temperature reading from sensors
        for (int i = 0; i < sensor_count; i++) {
            int temp_reading = (rand() % 50) - 20;
            temperature += temp_reading;

            if (temp_reading < min_temperature) {
                min_temperature = temp_reading;
            }

            if (temp_reading > max_temperature) {
                max_temperature = temp_reading;
            }
        }

        // Calculate average temperature
        temperature /= sensor_count;

        printf("Current temperature: %d°C\n", temperature);
        printf("Minimum temperature: %d°C\n", min_temperature);
        printf("Maximum temperature: %d°C\n", max_temperature);

        if (temperature > 50 || temperature < -20) {
            printf("WARNING: Temperature is outside safe range!\n");
        }

        // Wait for 5 seconds before taking next reading
        sleep(5);
    }

    return 0;
}