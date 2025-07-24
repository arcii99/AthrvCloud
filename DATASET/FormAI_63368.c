//FormAI DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare a function to read temperature
void readTemp(int sensorID);

int main(void) {
    // Declare integer variables to store temperature values from sensors
    int temp1, temp2, temp3;
    
    srand(time(NULL)); // Initialize random seed
    
    // Print title of program and instructions
    printf("Temperature Monitor\n");
    printf("-------------------\n\n");
    printf("This program will read the temperature of three sensors and display the current temperature.\n\n");
    
    // Loop indefinitely to continuously display temperature readings
    while(1) {
        readTemp(1); // Read temperature from sensor 1
        readTemp(2); // Read temperature from sensor 2
        readTemp(3); // Read temperature from sensor 3
        
        // Pause for 5 seconds to allow time for temperature to change
        sleep(5);
    }
    
    return 0;
}

// Function to read temperature from a sensor and display the current temperature
void readTemp(int sensorID) {
    int temp = (rand() % 50) + 50; // Generate a random temperature between 50 and 100 degrees
    
    printf("Sensor %d temperature: %d degrees Celsius\n", sensorID, temp);
}