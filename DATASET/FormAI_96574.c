//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialization
    int temp;
    time_t current_time;
    char* c_time_string;

    // Get current time
    current_time = time(NULL);

    // Convert current time to string
    c_time_string = ctime(&current_time);

    // Generate random temperature between 0-50 Celsius
    srand(time(NULL));
    temp = rand() % 51;

    // Display temperature and current time
    printf("Current temperature: %d Celsius\n", temp);
    printf("Time: %s\n", c_time_string);

    // Check if the temperature exceeds 40 Celsius and alert the user
    if (temp > 40) {
        printf("WARNING: Temperature exceeds 40 Celsius!\n");
        // Send email to notify someone about high temperature
        // Code for sending email goes here...
    }

    return 0;
}