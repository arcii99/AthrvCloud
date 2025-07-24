//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Generate random temperature values
    srand(time(NULL));
    float temperature = rand() % 50;
    int count = 0;

    // Continuously monitor temperature and print the output
    while (count < 10) {
        // Sleep for a random time between 1 to 5 seconds
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);

        // Generate a new temperature value and print it with the current time
        temperature += (float)rand() / RAND_MAX * 5 - 2.5;
        time_t current_time = time(NULL);
        char* c_time_string = ctime(&current_time);
        c_time_string[strlen(c_time_string) - 1] = '\0'; // Remove the newline character
        printf("%s: Temperature is %.2f degrees Celsius\n", c_time_string, temperature);

        // Check if the temperature has exceeded a certain limit
        if (temperature > 30) {
            printf("WARNING: Temperature is too high! Cooling system activated\n");
        }

        count++;
    }

    return 0;
}