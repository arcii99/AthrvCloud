//FormAI DATASET v1.0 Category: Temperature monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TEMP_THRESHOLD 25.0f

float read_temperature() {
    // Simulate reading temperature from hardware
    float temperature = ((float) rand() / RAND_MAX) * 10 + 20;
    return temperature;
}

int main(int argc, char **argv) {
    printf("Starting temperature monitor...\n");
    printf("Threshold temperature: %.2f degrees Celsius\n", TEMP_THRESHOLD);

    while (1) {
        float temperature = read_temperature();

        printf("Current temperature: %.2f degrees Celsius\n", temperature);

        if (temperature >= TEMP_THRESHOLD) {
            printf("Temperature above threshold!\n");
            // TODO: Add action to take when temperature is above threshold
        }

        sleep(1);
    }

    return 0;
}