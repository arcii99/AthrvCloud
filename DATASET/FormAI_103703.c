//FormAI DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to generate a random temperature between -10 to 50°C
float generate_temp() {
    float temp = (float)rand() / RAND_MAX; // Generate a random float between 0 and 1
    temp = (temp * 60) - 10; // Scale and shift the random number to the desired range
    return temp;
}

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[9];
    float temp = 0.0;
    int num_readings = 0;
    
    printf("Welcome to the Visionary C Temperature Monitor!\n");
    printf("-----------------------------------------------\n");
    
    // Continuously read temperature every 5 seconds
    while(1) {
        // Get the current time
        current_time = time(NULL);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
        
        // Generate a random temperature reading
        temp = generate_temp();
        num_readings++;
     
        // Print the temperature reading and time
        printf("Temperature Reading %d: %.1f°C\tTime: %s\n", num_readings, temp, time_string);
        
        // Wait 5 seconds before the next reading
        sleep(5);
    }
    
    return 0;
}