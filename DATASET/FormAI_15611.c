//FormAI DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float temperature_reading() {
    float temp = (float)rand() / (float)RAND_MAX;
    return temp * 100;
}

void check_temperature(float threshold, char unit) {
    float temp = temperature_reading();
    printf("Current temperature: %.2f%c\n", temp, unit);
    if (temp > threshold) {
        printf("Temperature is above the threshold of %.2f%c.\n", threshold, unit);
    } else {
        printf("Temperature is below the threshold of %.2f%c.\n", threshold, unit);
    }
}

int main() {
    float threshold = 60.0;
    char unit = 'C';
    bool running = true;
    
    printf("Welcome to the Temperature Monitor!\n");
    while (running) {
        printf("Press 'r' to take a new reading or 'q' to quit: ");
        char input;
        scanf(" %c", &input);
        
        if (input == 'r') {
            check_temperature(threshold, unit);
        } else if (input == 'q') {
            running = false;
            printf("Exiting the Temperature Monitor. Thank you for using!\n");
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}