//FormAI DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMP_THRESHOLD 70
#define TEMP_SAMPLING_DELAY 5

int get_current_temperature(void) {
    return rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
}

bool is_temperature_above_threshold(int temperature) {
    return temperature > TEMP_THRESHOLD;
}

int main() {
    printf("Starting temperature monitor...\n");
    while (true) {
        int current_temp = get_current_temperature();
        printf("Current temperature: %d\n", current_temp);
        if (is_temperature_above_threshold(current_temp)) {
            printf("Temperature above threshold! Sending alert...\n");
            // Add code here to send alert (e.g. email, SMS, etc.)
        }
        sleep(TEMP_SAMPLING_DELAY);
    }
    return 0;
}