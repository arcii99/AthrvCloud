//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The case: A curious mind sets out to gather information about the temperature
// and is on a mission to create a C program that will monitor the temperature.

int main() {
    
    int temperature;
    srand(time(0)); // A random seed generator
    
    // Gather information
    printf("Our mission is to monitor the temperature in the area.\n");
    printf("Let's start by taking a temperature reading.\n");
    
    // Take a temperature reading and display the results
    temperature = (rand() % 50) + 10; // Generate a random temperature between 10-60 degrees
    printf("The current temperature is: %dC\n", temperature);

    // The case gets more complicated: The curious mind realizes that
    // the program needs to keep monitoring the temperature and decide
    // if it is safe or not. They add a conditional statement to display
    // a warning message if the temperature is too high or too low.
    
    // Monitor the temperature
    while (1) { // A never-ending loop, as temperature is always changing
        
        temperature = (rand() % 50) + 10; // Generate a new random temperature
        
        // Check if the temperature is too high or too low and display a warning message
        if (temperature > 30) {
            printf("Warning: The temperature is too high! It is currently: %dC\n", temperature);
        } else if (temperature < 10) {
            printf("Warning: The temperature is too low! It is currently: %dC\n", temperature);
        } else {
            printf("The temperature is currently: %dC\n", temperature);
        }
        
        // Wait for 1 second before taking the next temperature reading
        sleep(1);
    }
    
    return 0;  
}