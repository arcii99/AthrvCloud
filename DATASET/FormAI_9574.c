//FormAI DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    float temp = 20.0; // Start temperature at 20 degrees Celsius
    float threshold = 25.0; // Set temperature threshold at 25 degrees Celsius
    int iterations = 0; // Counter to keep track of iterations
    
    while(1) {
        float currentTemp = temp + (rand() % 5) - 2; // Generate random temperature between -2 and 2 degrees Celsius
        printf("Current temperature: %.2fC\n", currentTemp); // Print current temperature
        
        if(currentTemp >= threshold) {
            printf("Temperature is too high!\n");
            // SEND ALERT MESSAGE TO CONTROL ROOM
            sleep(1); // Wait for 1 second
            continue; // Continue loop without incrementing iterations counter
        }
        
        iterations++; // Increment iterations counter
        
        if(iterations >= 10) { // Check if 10 iterations have occurred
            printf("10 iterations have occurred. Checking for anomalies...\n");
            int anomaly = rand() % 2; // Generate random anomaly boolean
            if(anomaly) {
                printf("Anomaly detected!\n");
                // SEND ALERT MESSAGE TO CONTROL ROOM
                sleep(1); // Wait for 1 second
            }
            iterations = 0; // Reset iterations counter
        }
        
        sleep(1); // Wait for 1 second
    }
    
    return 0;
}