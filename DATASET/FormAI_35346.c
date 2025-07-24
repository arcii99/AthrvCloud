//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature = 0;
    srand(time(0)); // initialize random seed
    int max_temperature = 50;
    int min_temperature = -50;

    while (1) { // loop forever
        temperature = (float)rand() / (float)(RAND_MAX) * (max_temperature - min_temperature) + min_temperature; // generate random temperature
        printf("Current temperature: %.1f°C\n", temperature);
        if (temperature > 30) { // if temperature is above 30°C
            printf("It's too hot! Turn on the air conditioner.\n");
        }
        else if (temperature < 10) { // if temperature is below 10°C
            printf("It's too cold! Turn on the heater.\n");
        }
        else { // if temperature is between 10°C and 30°C
            printf("Temperature is comfortable.\n");
        }
        sleep(1); // wait for 1 second before generating new temperature
    }

    return 0;
}