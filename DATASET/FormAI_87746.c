//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Claude Shannon
/*
 * C Temperature Monitor Example Program
 *
 * This program reads temperature values from a sensor and outputs the current temperature,
 * as well as the average temperature over the past 10 readings.
 *
 * The program uses a circular buffer to store the last 10 temperature readings, and updates
 * the average temperature after each new reading is added to the buffer.
 *
 * The program also includes error handling for when the sensor is not functioning or when
 * there is an issue with the buffer.
 *
 * Written by Claude Shannon
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10 // Size of circular buffer
#define MAX_TEMP 100.0 // Maximum allowed temperature
#define MIN_TEMP -100.0 // Minimum allowed temperature
#define ERROR_TEMP -999.0 // Indicator for when there is an error with the sensor

// Circular buffer struct
typedef struct {
    double temperatures[BUFFER_SIZE];
    int head; // Index of the first element in the buffer
    int count; // Number of elements currently in the buffer
} Buffer;

// Function declarations
double get_temperature(void);
void update_buffer(Buffer *buf, double temp);
double get_average_temperature(Buffer buf);

int main(void) {

    Buffer buffer = { .head = 0, .count = 0 };

    printf("C Temperature Monitor\n");

    while (1) {
        double temperature = get_temperature();
        if (temperature == ERROR_TEMP) {
            printf("Error: Sensor not functioning properly. Exiting program.\n");
            exit(EXIT_FAILURE);
        }
        if (temperature > MAX_TEMP || temperature < MIN_TEMP) {
            printf("Warning: Temperature out of range (must be between %.1f and %.1f). Reading ignored.\n", MIN_TEMP, MAX_TEMP);
            continue;
        }
        update_buffer(&buffer, temperature);
        double average_temperature = get_average_temperature(buffer);
        printf("Current temperature: %.1f\nAverage temperature (last 10 readings): %.1f\n", temperature, average_temperature);
    }

    return 0;
}

// Simulates getting temperature readings from a sensor
double get_temperature(void) {
    // Generate random number between -100 and 100
    double temperature = ((double) rand() / (double) RAND_MAX) * 200.0 - 100.0;
    // Simulate error when temperature is negative
    if (temperature < 0.0) {
        return ERROR_TEMP;
    }
    return temperature;
}

// Adds the given temperature to the buffer and updates the head and count
void update_buffer(Buffer *buf, double temp) {
    buf->temperatures[buf->head] = temp;
    buf->head = (buf->head + 1) % BUFFER_SIZE;
    if (buf->count < BUFFER_SIZE) {
        buf->count++;
    }
}

// Calculates the average temperature of the last BUFFER_SIZE readings in the buffer
double get_average_temperature(Buffer buf) {
    double sum = 0.0;
    for (int i = 0; i < buf.count; i++) {
        sum += buf.temperatures[(buf.head - i - 1 + BUFFER_SIZE) % BUFFER_SIZE];
    }
    return sum / (double) buf.count;
}