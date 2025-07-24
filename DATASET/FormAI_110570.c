//FormAI DATASET v1.0 Category: Temperature monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READINGS 10 // Maximum number of readings to store in the array
#define WARNING_TEMP 30 // Temperature threshold to trigger warning message

// Structure to hold temperature reading information
typedef struct TemperatureReading {
    int id;
    char timestamp[20];
    int temperature;
} TemperatureReading;

// Function to get current timestamp in format YYYY-MM-DD hh:mm:ss
void getTimestamp(char *timestamp) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
}

// Function to add new temperature reading to array
void addTemperatureReading(TemperatureReading *readings, int *numReadings, int temperature) {
    TemperatureReading newReading;
    getTimestamp(newReading.timestamp);
    newReading.temperature = temperature;
    newReading.id = (*numReadings) + 1;

    readings[*numReadings] = newReading;
    (*numReadings)++;

    printf("Temperature reading added successfully.\n\n");
}

// Function to print all temperature readings in array
void printTemperatureReadings(TemperatureReading *readings, int numReadings) {
    printf("Temperature Readings:\n");
    printf("%-5s %-20s %-10s\n", "ID", "Timestamp", "Temperature (C)");

    for (int i = 0; i < numReadings; i++) {
        printf("%-5d %-20s %-10d\n", readings[i].id, readings[i].timestamp, readings[i].temperature);
    }

    printf("\n");
}

// Function to check if the last reading exceeds warning temperature and print a warning message
void checkTemperatureWarning(TemperatureReading *readings, int numReadings) {
    if (readings[numReadings - 1].temperature > WARNING_TEMP) {
        printf("WARNING: Temperature is above the threshold of %d degrees Celsius.\n\n", WARNING_TEMP);
    }
}

int main() {
    printf("Welcome to the Temperature Monitor program.\n\n");

    int numReadings = 0;
    TemperatureReading readings[MAX_READINGS];

    char input[10];

    while (1) {
        printf("Enter a command (add, print, exit): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "add") == 0) {
            int temperature;
            printf("Enter temperature in degrees Celsius: ");
            scanf("%d", &temperature);
            getchar(); // Get rid of extra newline character from scanf

            addTemperatureReading(readings, &numReadings, temperature);

            // Check for warning message
            if (numReadings > 0) {
                checkTemperatureWarning(readings, numReadings);
            }

            if (numReadings == MAX_READINGS) {
                printf("Maximum number of readings reached. Exiting program.\n");
                break;
            }
        } else if (strcmp(input, "print") == 0) {
            printTemperatureReadings(readings, numReadings);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Command not recognized. Please try again.\n\n");
        }
    }

    return 0;
}