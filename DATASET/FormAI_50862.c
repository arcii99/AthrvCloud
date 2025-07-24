//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void turn_on_lights(int green_time, int yellow_time, int red_time) {
    printf("\nGreen Light ON for %d seconds...\n", green_time);
    sleep(green_time);

    printf("Yellow Light ON for %d seconds...\n", yellow_time);
    sleep(yellow_time);

    printf("Red Light ON for %d seconds...\n", red_time);
    sleep(red_time);
}

int main() {
    int total_time = 0;

    printf("Welcome to Traffic Light Controller!\n");

    while (1) {
        int green_time, yellow_time, red_time;

        printf("\nPlease enter Green Light time (in seconds): ");
        scanf("%d", &green_time);

        printf("\nPlease enter Yellow Light time (in seconds): ");
        scanf("%d", &yellow_time);

        printf("\nPlease enter Red Light time (in seconds): ");
        scanf("%d", &red_time);

        turn_on_lights(green_time, yellow_time, red_time);

        total_time += (green_time + yellow_time + red_time);

        printf("\nTotal Time Elapsed: %d seconds\n", total_time);
    }

    return 0;
}