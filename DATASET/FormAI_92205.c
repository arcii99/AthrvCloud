//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: creative
/* 
   TRAFFIC LIGHT CONTROLLER EXAMPLE PROGRAM
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum TrafficLightState {
    RED,
    YELLOW,
    GREEN
};

void delay(int seconds) {
    sleep(seconds);
}

int main() {
    enum TrafficLightState current_state = RED;
    int counter = 0;

    while (1) {
        switch (current_state) {
            case RED:
                printf("RED\n");
                delay(5);
                current_state = GREEN;
                break;
            case YELLOW:
                printf("YELLOW\n");
                delay(2);
                current_state = RED;
                break;
            case GREEN:
                printf("GREEN\n");
                delay(5);
                current_state = YELLOW;
                break;
            default:
                printf("ERROR: Invalid traffic light state.\n");
                exit(EXIT_FAILURE);
        }

        counter++;
        if (counter == 10) {
            printf("MAINTENANCE MODE - ALL LIGHTS FLASHING\n");
            delay(3);
            counter = 0;
        }
    }

    return 0;
}