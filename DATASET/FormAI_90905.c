//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

#define TEMP_UPPER_LIMIT 30
#define TEMP_LOWER_LIMIT 10

volatile bool monitor_running = true;

void handle_ctrl_c(int sig) {
    printf("\nTemperature monitor shutting down...\n");
    monitor_running = false;
}

int get_temp() {
    // Implementation of getting current temperature information goes here
    // This is a mock function that will return a random number between 10 and 30
    return (rand() % (TEMP_UPPER_LIMIT - TEMP_LOWER_LIMIT + 1)) + TEMP_LOWER_LIMIT;
}

int main() {
    signal(SIGINT, handle_ctrl_c);
    printf("Temperature monitor started!\n");
    while (monitor_running) {
        int current_temp = get_temp();
        printf("Current Temperature: %d°C\n", current_temp );
        if (current_temp > TEMP_UPPER_LIMIT) {
            printf("WARNING: Temperature is above the upper limit!\n");
        } else if (current_temp < TEMP_LOWER_LIMIT) {
            printf("WARNING: Temperature is below the lower limit!\n");
        }
        // Check temperature every 5 seconds
        sleep(5);
    }
    printf("Temperature monitor terminated\n");
    return 0;
}