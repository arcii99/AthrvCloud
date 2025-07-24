//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TEMP_THRESHOLD 25.0
#define DATA_SIZE 100

int main(int argc, char *argv[]) {
    float temperature;
    float temp_data[DATA_SIZE];
    int temp_index = 0;
    float temp_sum = 0.0;
    float temp_avg = 0.0;
    int i;

    printf("Starting temperature monitor...\n");

    while (1) {
        // Simulate reading temperature data from device
        temperature = rand() % 50;

        // Add temperature data to array
        temp_data[temp_index] = temperature;

        // Increment index and sum
        temp_index++;
        temp_sum += temperature;

        // If index reaches DATA_SIZE, reset index and sum
        if (temp_index >= DATA_SIZE) {
            temp_index = 0;
            temp_sum = 0.0;
        }

        // Calculate average temperature
        temp_avg = temp_sum / DATA_SIZE;

        // Print temperature and average temperature
        printf("Current temperature: %.2f°C\n", temperature);
        printf("Average temperature: %.2f°C\n", temp_avg);

        // Check if temperature is above threshold
        if (temperature > TEMP_THRESHOLD) {
            printf("WARNING: Temperature above threshold!\n");
        }

        // Wait for one second before repeating loop
        sleep(1);
    }

    return 0;
}