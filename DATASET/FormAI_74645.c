//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
 * Function to generate a random temperature
 * between the given minimum and maximum
 */
double generate_temperature(double min, double max) {
    double range = (max - min);
    double rand_num = rand() / (double) RAND_MAX;
    double temp = rand_num * range + min;
    return temp;
}

int main() {
    double min_temp = 10.0;     // minimum temperature
    double max_temp = 30.0;     // maximum temperature
    double threshold_temp = 25.0;   // threshold temperature
    bool is_above_threshold = false; // flag to keep track of threshold status
    double current_temp;    // variable to store current temperature
    time_t current_time;    // variable to store current time

    // Seed the random number generator with current time
    srand(time(NULL));

    // Continuously generate and display temperature readings
    while (true) {
        current_temp = generate_temperature(min_temp, max_temp);
        printf("Current Temperature: %.1lf°C\n", current_temp);

        // Check if current temperature is above threshold temperature
        if (current_temp >= threshold_temp) {
            if (!is_above_threshold) {
                is_above_threshold = true;
                current_time = time(NULL);
                printf("Alert! Temperature has crossed the threshold at %s", ctime(&current_time));
            }
        } else {
            is_above_threshold = false;
        }

        // Wait for some time before next reading
        sleep(5);
    }

    return 0;
}