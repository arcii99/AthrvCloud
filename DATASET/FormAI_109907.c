//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature;
    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Temperature Monitor!\n\n");

    while(1) {  // Run the program indefinitely
        temperature = (rand() % 201) - 50;  // Generate a random temperature between -50.0°C and 150.0°C
        printf("Current temperature: %.1f°C\n", temperature);
        if(temperature >= 100.0) {
            printf("Warning: Temperature is above 100.0°C!\n");
        } else if (temperature >= 70.0) {
            printf("Caution: Temperature is between 70.0°C and 99.9°C\n");
        }
        printf("\n");
        sleep(1);  // Pause for 1 second
    }

    return 0;
}