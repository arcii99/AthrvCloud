//FormAI DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generate_temperature(int, int);
int generate_humidity(int, int);
int generate_pressure(int, int);
void print_summary(int, int, int);

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate weather variables
    int temperature = generate_temperature(60, 100);
    int humidity = generate_humidity(40, 100);
    int pressure = generate_pressure(950, 1050);

    // Print weather summary
    print_summary(temperature, humidity, pressure);

    return 0;
}

// Generates a random temperature between min and max
int generate_temperature(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generates a random humidity between min and max
int generate_humidity(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generates a random pressure between min and max
int generate_pressure(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Prints a summary of the weather
void print_summary(int temperature, int humidity, int pressure) {
    printf("Temperature: %d F\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Pressure: %d hPa\n", pressure);

    // Determine the weather condition
    if (temperature >= 85 && humidity >= 70) {
        printf("The weather is hot and humid.\n");
    } else if (temperature >= 85) {
        printf("The weather is hot and dry.\n");
    } else if (temperature < 60) {
        printf("The weather is cold.\n");
    } else {
        printf("The weather is pleasant.\n");
    }
}