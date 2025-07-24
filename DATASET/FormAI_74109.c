//FormAI DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWER_LIMIT 0
#define UPPER_LIMIT 100

int main() {
    time_t currentTime = time(NULL); // Get current time
    srand(currentTime); // Use current time as seed for random number generation

    float temperature = (rand() % (UPPER_LIMIT - LOWER_LIMIT + 1)) + LOWER_LIMIT; // Generate random temperature between 0 and 100
    printf("Current temperature: %.2f\n", temperature);

    if (temperature >= 0 && temperature < 20) {
        printf("It's quite chilly outside.\n");
    }
    else if (temperature >= 20 && temperature < 30) {
        printf("The temperature is moderate.\n");
    }
    else if (temperature >= 30 && temperature < 40) {
        printf("It's getting hot!\n");
    }
    else if (temperature >= 40) {
        printf("Dangerously hot temperature.\n");
    }
    else {
        printf("Invalid temperature value.\n");
    }

    return 0;
}