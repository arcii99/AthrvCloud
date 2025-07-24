//FormAI DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the random temperature between -10 and 40 degrees Celsius
float get_temperature() {
    float temperature = (rand() % 51) - 10;
    return temperature;
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Initialize variables
    int day = 1;
    float temperature;
    float total_temperature = 0.0;
    float average_temperature;
    
    // Print the title of the program
    printf("~~~~~WEATHER SIMULATION~~~~~\n\n");
    
    // Loop through 7 days
    for(int i = 0; i < 7; i++) {
        // Get the temperature for the day
        temperature = get_temperature();
        
        // Print the day number and temperature for the day
        printf("Day %d: %.1f degrees Celsius\n", day++, temperature);
        
        // Add the temperature to the total
        total_temperature += temperature;
        
        // Check if the temperature is below 0 or above 30 and print an appropriate message
        if(temperature < 0.0) {
            printf("Brr! It's freezing cold today.\n");
        } else if(temperature > 30.0) {
            printf("It's scorching hot today!\n");
        }
        
        // Wait for a second before printing the next day's data
        // This is to simulate real-time updates
        sleep(1);
    }
    
    // Calculate the average temperature
    average_temperature = total_temperature / 7.0;
    
    // Print the average temperature of the week
    printf("\nAverage temperature for the week: %.1f degrees Celsius\n", average_temperature);
    
    return 0;
}