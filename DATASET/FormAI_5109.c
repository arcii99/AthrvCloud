//FormAI DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temperature;
    srand(time(0)); // initialize random seed

    for(int i=1; i<=10; i++) {
        temperature = (rand() % 30) + 10; // generate a random temperature between 10 and 40 degrees Celsius
        printf("Temperature reading %d: %.1f°C\n", i, temperature);
        if(temperature < 20) { // if temperature is less than 20 degrees Celsius
            printf("WARNING: Temperature is too low! Please take necessary measures.\n\n");
        } else if(temperature > 30) { // if temperature is greater than 30 degrees Celsius
            printf("WARNING: Temperature is too high! Please take necessary measures.\n\n");
        } else { // if temperature is between 20 and 30 degrees Celsius
            printf("Temperature is normal.\n\n");
        }
        sleep(1); // wait for 1 second before taking next reading
    }

    return 0;
}