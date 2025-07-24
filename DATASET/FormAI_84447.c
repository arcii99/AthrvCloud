//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMP_READ_INTERVAL 5
#define TEMP_READ_DURATION 30

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int current_temp = MIN_TEMP;
    int iterations = TEMP_READ_DURATION / TEMP_READ_INTERVAL;

    printf("Starting Temperature Monitoring System...\n");
    printf("-----------------------------------------\n");

    for(int i=0; i<iterations; i++) {
        int current_iteration = i+1;
        int random_number = rand() % 10; // Generate a random number between 0 and 9
        int temp_change = (random_number > 4) ? 1 : -1; // Decide if the temperature should increase or decrease

        current_temp += temp_change; // Update the temperature

        printf("Iteration %d - Current Temperature: %d\n", current_iteration, current_temp);

        if(current_temp <= MIN_TEMP) {
            printf("WARNING: Temperature has dropped below minimum limit of %d!\n", MIN_TEMP);
            break;
        }

        if(current_temp >= MAX_TEMP) {
            printf("WARNING: Temperature has exceeded maximum limit of %d!\n", MAX_TEMP);
            break;
        }

        printf("\n");

        sleep(TEMP_READ_INTERVAL); // Wait for the specified time interval before reading the temperature again
    }

    printf("-----------------------------------------\n");
    printf("Temperature Monitoring System Stopped.\n");

    return 0;
}