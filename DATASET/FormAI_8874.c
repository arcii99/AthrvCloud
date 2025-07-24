//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 150       // maximum temperature value
#define MIN_TEMP -50       // minimum temperature value
#define MAX_READINGS 1000  // maximum number of readings
#define MAX_LENGTH 50      // maximum length of input string

struct reading {
    char timestamp[MAX_LENGTH];
    float temperature;
};

int main() {
    struct reading readings[MAX_READINGS];
    int num_readings = 0;
    char input[MAX_LENGTH];
    float current_temp;

    // loop until user inputs "quit"
    while (1) {
        printf("Enter current temperature (or 'quit' to exit): ");
        fgets(input, MAX_LENGTH, stdin);
        strtok(input, "\n");  // remove newline character from input

        // check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // otherwise, convert input to float and save it
        current_temp = strtof(input, NULL);

        // check if temperature is within range
        if (current_temp < MIN_TEMP || current_temp > MAX_TEMP) {
            printf("Invalid temperature value. Try again.\n");
            continue;
        }

        // save current time and temperature as a new reading
        time_t rawtime;
        time(&rawtime);
        struct tm* time_info = localtime(&rawtime);
        strftime(readings[num_readings].timestamp, MAX_LENGTH, "%Y-%m-%d %H:%M:%S", time_info);
        readings[num_readings].temperature = current_temp;
        num_readings++;

        // print out current temperature and number of readings
        printf("Current temperature: %.2f C\n", current_temp);
        printf("Number of readings: %d\n", num_readings);
    }

    // print out all the readings
    printf("\n\nTemperatures\n");
    printf("------------\n");
    printf("%-20s %s\n", "Timestamp", "Temperature (C)");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_readings; i++) {
        printf("%-20s %.2f\n", readings[i].timestamp, readings[i].temperature);
    }

    return 0;
}