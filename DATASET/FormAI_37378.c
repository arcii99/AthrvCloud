//FormAI DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global weather variables
int humidity = 0;
int temperature = 0;
int wind_speed = 0;

// Function to generate random integer within range
int random_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate weather changes randomly
void simulate_weather() {
    // Generate random values for each weather variable
    humidity = random_range(40, 100);
    temperature = random_range(10, 35);
    wind_speed = random_range(5, 30);
}

// Function to print out the current weather conditions
void print_weather() {
    printf("Current weather conditions:\n");
    printf("Humidity: %d%%\n", humidity);
    printf("Temperature: %d°C\n", temperature);
    printf("Wind speed: %dkm/h\n", wind_speed);
}

// Main function to run the weather simulation
int main() {
    // Seed the random number generator using current time
    srand(time(NULL));

    // Initialize the weather variables
    simulate_weather();

    // Print out the initial weather conditions
    print_weather();

    // Loop through 24 hours of weather simulation
    for (int i = 1; i <= 24; i++) {
        printf("\nHour %d:\n", i);

        // Simulate weather changes randomly every 3 hours
        if (i % 3 == 0) {
            simulate_weather();
            printf("Weather changes:\n");
        }

        // Print out the current weather conditions
        print_weather();

        // Sleep for 1 second to simulate real time
        sleep(1);
    }

    printf("\nWeather simulation ended.\n");

    return 0;
}