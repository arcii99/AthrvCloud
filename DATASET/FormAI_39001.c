//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 15 // Minimum temperature limit
#define MAX_TEMP 30 // Maximum temperature limit
#define MONITOR_INTERVAL 10 // Time interval in seconds for monitoring temperature

float generate_random_temp() {
    return ((float)rand() / (float)RAND_MAX) * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
}

int main() {
    float current_temp = generate_random_temp(); // initialize current temperature
    time_t last_monitored_time = time(NULL); // initialize last monitored time
    printf("Current temperature: %.2f\n", current_temp);
    while (1) {
        time_t now = time(NULL);
        if (now - last_monitored_time >= MONITOR_INTERVAL) {
            current_temp = generate_random_temp();
            last_monitored_time = now;
            printf("Current temperature: %.2f\n", current_temp);
            if (current_temp >= MAX_TEMP) {
                printf("Temperature is too high! Cooling system is being activated.\n");
                // code to activate cooling system
            } else if (current_temp <= MIN_TEMP) {
                printf("Temperature is too low! Heating system is being activated.\n");
                // code to activate heating system
            }
        }
    }
    return 0;
}