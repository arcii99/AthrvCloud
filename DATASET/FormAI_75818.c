//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 40
#define MIN_TEMPERATURE 0
#define MAX_HISTORY 10

int main() {
    float temperature;
    float history[MAX_HISTORY];
    int history_index = 0;

    srand(time(NULL)); // Initialize random number generator

    while(1) {
        // Generate a random temperature between 0 and 40
        temperature = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;

        // Save the temperature in the history array
        history[history_index] = temperature;

        // Print the current temperature
        printf("Current Temperature: %.1f°C\n", temperature);

        // Print the temperature history
        printf("Temperature History: ");
        for(int i = 0; i <= history_index; i++) {
            printf("%.1f°C ", history[i]);
        }
        printf("\n");

        // Increment the history_index
        history_index++;

        // If the history_index reaches the MAX_HISTORY, reset it to 0
        if(history_index >= MAX_HISTORY) {
            history_index = 0;
        }

        // Wait for 1 second
        printf("\n");
        for(int i = 0; i < 100000000; i++);
    }

    return 0;
}