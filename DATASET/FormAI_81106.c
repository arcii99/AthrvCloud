//FormAI DATASET v1.0 Category: Temperature monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to simulate temperature reading */
int get_temperature() {
    int temp = rand() % 40;
    return temp;
}

int main() {
    int current_temp = 0;
    int count = 0;
    float avg_temp = 0;

    /* Seed the random number generator */
    srand(time(0));

    /* Loop to simulate temperature readings */
    while (count < 10) {
        current_temp = get_temperature();
        printf("Current Temperature: %d\n", current_temp);
        avg_temp = (avg_temp * count + current_temp) / (count + 1);
        printf("Average Temperature: %f\n", avg_temp);
        count++;
    }

    /* Determine if the temperature is safe */
    if (avg_temp >= 10 && avg_temp <= 30) {
        printf("Temperature is within safe limits.\n");
    } else {
        printf("Temperature is not safe!\n");
    }

    return 0;
}