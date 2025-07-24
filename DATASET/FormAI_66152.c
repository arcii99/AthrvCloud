//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Define the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the delay times for each state
#define RED_DELAY 5
#define YELLOW_DELAY 2
#define GREEN_DELAY 4

// Define the traffic light's directions
#define NORTH_SOUTH 0
#define EAST_WEST 1

// Define the traffic light struct
typedef struct traffic_light {
    int direction;
    int state;
} traffic_light;

// Define the function that controls a single traffic light
void *control_traffic_light(void *arg) {
    traffic_light *tl = (traffic_light*) arg;

    while(1) {
        switch(tl->state) {
            case RED:
                printf("Traffic light %d is RED\n", tl->direction);
                sleep(RED_DELAY);
                tl->state = GREEN;
                break;
            case YELLOW:
                printf("Traffic light %d is YELLOW\n", tl->direction);
                sleep(YELLOW_DELAY);
                if(tl->direction == NORTH_SOUTH) {
                    tl->direction = EAST_WEST;
                } else {
                    tl->direction = NORTH_SOUTH;
                }
                tl->state = RED;
                break;
            case GREEN:
                printf("Traffic light %d is GREEN\n", tl->direction);
                sleep(GREEN_DELAY);
                tl->state = YELLOW;
                break;
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Initialize the two traffic lights
    traffic_light north_south_tl = {NORTH_SOUTH, RED};
    traffic_light east_west_tl = {EAST_WEST, GREEN};

    // Create the two threads to control each traffic light
    pthread_t north_south_tid, east_west_tid;

    pthread_create(&north_south_tid, NULL, control_traffic_light, &north_south_tl);
    pthread_create(&east_west_tid, NULL, control_traffic_light, &east_west_tl);

    // Wait for the threads to exit
    pthread_join(north_south_tid, NULL);
    pthread_join(east_west_tid, NULL);

    return 0;
}