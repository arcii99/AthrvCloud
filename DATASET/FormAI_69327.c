//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define TIME_INTERVAL 5 //time interval for each light, in seconds

int main() {
    srand(time(NULL)); //initialize random seed

    int current_state = RED; //traffic light starts in red state
    int time_remaining = TIME_INTERVAL; //time remaining in current state

    while (1) {
        printf("Current state: ");
        switch (current_state) {
            case RED:
                printf("RED\n");
                break;
            case YELLOW:
                printf("YELLOW\n");
                break;
            case GREEN:
                printf("GREEN\n");
                break;
        }

        printf("Time remaining: %d\n\n", time_remaining);
        sleep(1); //pause program for a second

        if (time_remaining == 0) { //if time for current state is up, switch to next state
            switch (current_state) {
                case RED:
                    current_state = GREEN;
                    break;
                case YELLOW:
                    current_state = RED;
                    break;
                case GREEN:
                    current_state = YELLOW;
                    break;
            }
            time_remaining = TIME_INTERVAL; //reset time for new state
            printf("Switching state...\n\n");
        } else {
            time_remaining--; //decrease time remaining for current state
        }
    }

    return 0;
}