//FormAI DATASET v1.0 Category: Temperature monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp" // Path to temperature file
#define MAX_TEMP 90.0 // Maximum allowed temperature
#define SLEEP_SECONDS 10 // Time in seconds between temperature checks

float get_temperature(){
    FILE* temp_file = fopen(TEMP_PATH, "r"); // Open the temperature file for reading
    if(temp_file == NULL){
        fprintf(stderr, "Error opening temperature file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    float temperature;
    fscanf(temp_file, "%f", &temperature); // Read the temperature value
    fclose(temp_file); // Close the temperature file

    return temperature / 1000.0; // Convert temperature from milli-degrees Celsius to degrees Celsius
}

int main(){
    printf("Starting temperature monitor... (press CTRL+C to exit)\n");

    while(true){
        float temperature = get_temperature(); // Get the current temperature

        printf("Current temperature: %.1f°C\n", temperature);

        if(temperature >= MAX_TEMP){
            printf("WARNING: Temperature is too high! Shutting down...\n");
            system("sudo shutdown -P now"); // Send shutdown command
            exit(EXIT_SUCCESS);
        }

        sleep(SLEEP_SECONDS); // Wait for a few seconds before checking the temperature again
    }

    return 0;
}