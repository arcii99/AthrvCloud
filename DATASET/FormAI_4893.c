//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int main() {

    int traffic_light = RED;
    int seconds = 0;

    while (true) {

        printf("The traffic light is currently %s\n", 
               traffic_light == GREEN ? "green" :
               traffic_light == YELLOW ? "yellow" : "red");

        if (traffic_light == GREEN) {
            sleep(10);
            traffic_light = YELLOW;
        } else if (traffic_light == YELLOW) {
            sleep(3);
            traffic_light = RED;
        } else {
            sleep(15);
            traffic_light = GREEN;
        }

        seconds = 0;

        while (seconds < 20) {
            printf("The pedestrian light is currently %s\n", seconds < 10 ? "flashing red" : "red");
            seconds++;
            sleep(1);
        }

        printf("The pedestrian light is now green!\n");

    }

    return EXIT_SUCCESS;
}