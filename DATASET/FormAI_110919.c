//FormAI DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TEMP 100
#define MIN_TEMP -20

bool is_valid_temperature(float temp);

int main() {
    float temperature;
    
    printf("Enter the current temperature in Celsius: ");
    scanf("%f", &temperature);

    if (!is_valid_temperature(temperature)) {
        printf("Invalid temperature value. Temperature should be between %d and %d Celsius.\n", MIN_TEMP, MAX_TEMP);
        return EXIT_FAILURE;
    }

    // Temperature is valid. Store the temperature in a file or database
    
    printf("Temperature %f Celsius is valid.\n", temperature);
    return EXIT_SUCCESS;
}

bool is_valid_temperature(float temp) {
    if (temp < MIN_TEMP || temp > MAX_TEMP) {
        return false;
    }
    return true;
}