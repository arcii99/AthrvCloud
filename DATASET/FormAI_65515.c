//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_READINGS 10

int main() {
    int readings[NUM_READINGS];
    int sum = 0;
    float avg;
    srand(time(NULL));

    printf("Starting temperature monitor...\n");

    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = (rand() % 30) + 1;
        sum += readings[i];
        printf("Reading %d: %d degrees Celsius\n", i+1, readings[i]);
        sleep(1);
    }

    avg = (float)sum / NUM_READINGS;

    printf("\nAll readings complete.\n");
    printf("Average temperature: %0.2f degrees Celsius\n", avg);

    if (avg >= 20.0) {
        printf("Temperature is higher than normal. Alerting authorities.\n");
    } else {
        printf("Temperature is within normal range. No action required.\n");
    }

    return 0;
}