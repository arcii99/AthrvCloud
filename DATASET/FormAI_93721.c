//FormAI DATASET v1.0 Category: Temperature monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature;
    int sensor_id;
    while (1) {
        printf("Enter the sensor ID and temperature: ");
        scanf("%d %f", &sensor_id, &temperature); // read inputs from user

        if (sensor_id <= 0) { // exit the program if the sensor_id is zero or negative
            printf("Invalid sensor ID. Exiting program.\n");
            break;
        }

        if (temperature < 0) { // print warning message if temperature is negative
            printf("Warning: Temperature below 0 degrees Celsius\n");
        } else if (temperature > 100) { // print warning message if temperature is above 100 degrees Celsius
            printf("Warning: Temperature above 100 degrees Celsius\n");
        }

        // log temperature data to file
        FILE *f = fopen("temperature_log.txt", "a");
        if (f == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }
        fprintf(f, "Sensor ID: %d Temperature: %.2f\n", sensor_id, temperature);
        fclose(f);
    }
    return 0;
}