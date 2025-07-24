//FormAI DATASET v1.0 Category: Weather simulation ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DAYS 7
#define HOURS 24

// Return a random temperature between -10 and 30 degrees
float get_random_temperature() {
    return (float)(rand() % 40 - 10);
}

// Initialize the 2D array with random temperatures
void initialize_array(float weather[DAYS][HOURS]) {
    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < HOURS; j++) {
            weather[i][j] = get_random_temperature();
        }
    }
}

// Calculate and return the average temperature of a given day
float get_average_temperature_of_day(float weather[DAYS][HOURS], int day) {
    float sum = 0.0;
    for (int i = 0; i < HOURS; i++) {
        sum += weather[day][i];
    }
    return sum / HOURS;
}

// Print the 2D array in a well-formatted table
void print_weather_table(float weather[DAYS][HOURS]) {
    printf("\nWeather forecast for the next %d days:\n", DAYS);
    printf("-------------------------------------------------------\n");
    printf("| Day | %02d:00 | %02d:00 | %02d:00 | ... | %02d:00 |\n", 
           (int)0, (int)6, (int)12, (int)18);
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < DAYS; i++) {
        printf("|  %d  |", i+1);
        for (int j = 0; j < HOURS; j+=6) {
            printf("  %.1f   |", weather[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------------------\n");
}

int main() {
    // Initialize the random seed
    srand(time(NULL));
    
    // Declare and initialize the 2D array
    float weather[DAYS][HOURS];
    initialize_array(weather);
    
    // Print the weather forecast table
    print_weather_table(weather);
    
    // Calculate and display the average temperature of each day
    printf("\nAverage temperatures of each day:\n");
    for (int i = 0; i < DAYS; i++) {
        printf("Day %d: %.1f\n", i+1, get_average_temperature_of_day(weather, i));
    }
    
    return 0;
}