//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100

float generate_random_temp() {
    float temp = MIN_TEMP + (rand() / (float)(RAND_MAX)) * (MAX_TEMP - MIN_TEMP);
    return temp;
}

int main() {
    srand(time(NULL));
    int count = 0, max_count = 10;
    float current_temp = 0, temp_sum = 0, avg_temp = 0;

    printf("Temperature Monitor Program\n");

    while (count < max_count) {
        current_temp = generate_random_temp();
        printf("Current Temperature: %.2f °C\n", current_temp);
        temp_sum += current_temp;
        count++;
    }

    avg_temp = temp_sum / max_count;
    printf("\nAverage Temperature: %.2f °C\n", avg_temp);

    if (avg_temp >= 70) {
        printf("Warning: Temperature above safe limits. Please take action!\n");
    } else if (avg_temp <= 10) {
        printf("Warning: Temperature below safe limits. Please take action!\n");
    } else {
        printf("Temperature within safe limits. No action required.\n");
    }

    return 0;
}