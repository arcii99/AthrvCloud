//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random temperature value in Celsius
double generate_temp() {
    double min = -10.0, max = 40.0;
    double temp_range = max - min;
    double temp = ((double) rand() / (double) RAND_MAX) * temp_range + min;
    return temp;
}

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32.0;
    return fahrenheit;
}

int main() {
    srand(time(NULL));  // Initialize random seed using system time

    double temp_celsius = generate_temp();  // Generate initial temperature in Celsius

    printf("Temperature Monitor (Celsius)\n");
    printf("=============================\n");

    while (1) {
        printf("Current Temperature: %.2f C\n", temp_celsius);

        if (temp_celsius >= 37.5) {
            printf("WARNING: High temperature detected. Seek medical attention if necessary.\n");
        }

        double temp_fahrenheit = celsius_to_fahrenheit(temp_celsius);
        printf("Current Temperature: %.2f F\n", temp_fahrenheit);

        printf("Waiting 5 seconds...\n");
        sleep(5);

        temp_celsius = generate_temp();  // Generate new temperature in Celsius
    }

    return 0;
}