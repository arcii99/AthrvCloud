//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random temperature within a range */
float generate_temperature() {
    float min = 36.0, max = 38.0;
    float temperature = (min + rand() / (RAND_MAX / (max - min)));
    return temperature;
}

/* Function to check the temperature level */
void check_temperature_level(float temperature) {
    if (temperature > 37.5) {
        printf("WARNING: Temperature is high!\n");
    } else if (temperature < 35.0) {
        printf("WARNING: Temperature is low!\n");
    } else {
        printf("Temperature is normal.\n");
    }
}

int main() {
    printf("******* Temperature Monitor *******\n\n");

    srand(time(NULL));
    float temperature = generate_temperature();
    printf("Current temperature: %.1fC\n", temperature);
    check_temperature_level(temperature);
    printf("\n");

    // Simulating 10 seconds of wait time
    for (int i = 1; i <= 10; i++) {
        printf("Wait time: %d second(s).\n", i);
        temperature = generate_temperature();
        printf("Current temperature: %.1fC\n", temperature);
        check_temperature_level(temperature);
        printf("\n");
        sleep(1);  // Wait for 1 second
    }

    printf("******* End of monitoring *******\n");

    return 0;
}