//FormAI DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the temperature string
#define MAX_TEMP_LENGTH 10

// Function to validate if the input is a valid temperature value
int is_valid_temperature(char *temp) {
    // Check if the temperature string is empty
    if (strlen(temp) == 0) {
        return 0;
    }

    // Check if the temperature string has more than one decimal point
    int decimal_points = 0;
    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] == '.') {
            decimal_points++;
        }
    }
    if (decimal_points > 1) {
        return 0;
    }

    // Check if the temperature string only contains valid characters
    for (int i = 0; i < strlen(temp); i++) {
        if (!((temp[i] >= '0' && temp[i] <= '9') || temp[i] == '.' || temp[i] == '-')) {
            return 0;
        }
    }

    return 1;
}

// Function to check if the temperature exceeds a certain threshold
int is_over_temperature_threshold(char *temp, float threshold) {
    float temperature = atof(temp);
    if (temperature > threshold) {
        return 1;
    }
    return 0;
}

int main() {
    char temperature[MAX_TEMP_LENGTH];

    // Get the temperature input
    printf("Enter the temperature in Celsius: ");
    fgets(temperature, MAX_TEMP_LENGTH, stdin);
    temperature[strcspn(temperature, "\n")] = '\0';

    // Validate the temperature input
    while (!is_valid_temperature(temperature)) {
        printf("Invalid temperature value. Please enter a valid temperature in Celsius: ");
        fgets(temperature, MAX_TEMP_LENGTH, stdin);
        temperature[strcspn(temperature, "\n")] = '\0';
    }

    // Check if the temperature is over the threshold (in this case, 30 degrees Celsius)
    if (is_over_temperature_threshold(temperature, 30.0)) {
        printf("Temperature exceeded threshold of 30 degrees Celsius.\n");
        // Here, you can trigger an alarm or send a notification to a monitoring service
    } else {
        printf("Temperature is within normal range.\n");
    }

    return 0;
}