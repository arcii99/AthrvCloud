//FormAI DATASET v1.0 Category: Temperature monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
    // Set up variables for temperature and time
    float temperature;
    char current_time[20];
    
    // Display welcome message
    printf("Welcome to the Unique Temperature Monitor Program\n");
    printf("-----------------------------------------------\n");
    
    // Continuously monitor temperature and display current temperature and time
    while(1) {
        // Get current time
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(current_time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
        
        // Generate random temperature between -10 and 40 degrees Celsius
        temperature = (rand() % 500) / 10.0 - 10.0;
        
        // Check if temperature is too high or too low
        if (temperature < -5.0) {
            printf("ALERT! Temperature is too low: %.1f degrees Celsius at %s\n", temperature, current_time);
        } else if (temperature > 35.0) {
            printf("ALERT! Temperature is too high: %.1f degrees Celsius at %s\n", temperature, current_time);
        } else {
            printf("Current temperature is %.1f degrees Celsius at %s\n", temperature, current_time);
        }
        
        // Wait for 3 seconds before checking temperature again
        sleep(3);
    }
    
    return 0;
}