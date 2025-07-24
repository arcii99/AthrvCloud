//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP -30

int main() {
    srand(time(NULL)); // Seed for random number generation
    int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // Generate a random temperature between MIN_TEMP and MAX_TEMP
    bool is_celsius = true; // Initialized to celsius scale
    char scale[] = "Celsius"; // Initialize scale
    printf("Temperature reading: %d degrees %s\n", temp, scale);

    while(true) { // Loop for continuous monitoring
        int choice = 0;
        printf("Choose an option:\n1. Switch to Fahrenheit\n2. Switch to Celsius\n3. Exit program\n");
        scanf("%d", &choice);
        if(choice == 1 && is_celsius) { // If option 1 and in celsius scale
            temp = 9 * temp / 5 + 32; // Convert to fahrenheit scale
            is_celsius = false; // Set scale to fahrenheit
            scale[0] = 'F'; // Change scale to fahrenheit
            printf("Temperature reading: %d degrees %s\n", temp, scale);
        }
        else if(choice == 2 && !is_celsius) { // If option 2 and in fahrenheit scale
            temp = (temp - 32) * 5 / 9; // Convert to celsius scale
            is_celsius = true; // Set scale to celsius
            scale[0] = 'C'; // Change scale to celsius
            printf("Temperature reading: %d degrees %s\n", temp, scale);
        }
        else if(choice == 3) { // If option 3
            printf("Program terminated.\n");
            break; // Exit loop
        }
        else { // If invalid option
            printf("Invalid option selected.\n");
            continue; // Skip to next iteration
        }
    }

    return 0;
}