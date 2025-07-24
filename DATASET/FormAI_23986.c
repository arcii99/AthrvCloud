//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Constants for the traffic light intervals
#define GREEN_INTERVAL 10
#define YELLOW_INTERVAL 2
#define RED_INTERVAL 5

// Structs to represent the traffic lights and their state
typedef struct {
    bool is_green;
    bool is_yellow;
    bool is_red;
} TrafficLightState;

typedef struct {
    TrafficLightState north_south_state;
    TrafficLightState east_west_state;
    bool is_pedestrian_green;
} TrafficLight;

// Function prototypes
void print_traffic_light(TrafficLight *tl);
void *traffic_light_controller(void *arg);

int main() {
    // Create the traffic light and initialize their state
    TrafficLight tl = {
        .north_south_state = { .is_green = true, .is_yellow = false, .is_red = false },
        .east_west_state = { .is_green = false, .is_yellow = false, .is_red = true },
        .is_pedestrian_green = false,
    };

    // Create the traffic light controller thread
    pthread_t controller_thread;
    pthread_create(&controller_thread, NULL, &traffic_light_controller, &tl);

    // Keep the main thread alive to let the controller thread do its work
    while (true) {
        usleep(100000); // Sleep for 100ms to reduce CPU usage
    }

    return 0;
}

// Function to print the current state of the traffic lights
void print_traffic_light(TrafficLight *tl) {
    printf("\nTraffic Light:\n");
    printf("    North-South: ");
    if (tl->north_south_state.is_green) {
        printf("GREEN\n");
    } else if (tl->north_south_state.is_yellow) {
        printf("YELLOW\n");
    } else {
        printf("RED\n");
    }
    printf("    East-West: ");
    if (tl->east_west_state.is_green) {
        printf("GREEN\n");
    } else if (tl->east_west_state.is_yellow) {
        printf("YELLOW\n");
    } else {
        printf("RED\n");
    }
    printf("    Pedestrian: ");
    if (tl->is_pedestrian_green) {
        printf("GREEN\n");
    } else {
        printf("RED\n");
    }
}

// Function to control the traffic lights
void *traffic_light_controller(void *arg) {
    TrafficLight *tl = (TrafficLight *) arg;
    while (true) {
        // Start with the north-south traffic light being green
        tl->north_south_state.is_green = true;
        tl->north_south_state.is_yellow = false;
        tl->north_south_state.is_red = false;
        tl->east_west_state.is_green = false;
        tl->east_west_state.is_yellow = true;
        tl->east_west_state.is_red = false;
        print_traffic_light(tl);
        sleep(GREEN_INTERVAL);

        // Switch to yellow for both traffic lights
        tl->north_south_state.is_green = false;
        tl->north_south_state.is_yellow = true;
        tl->north_south_state.is_red = false;
        tl->east_west_state.is_green = false;
        tl->east_west_state.is_yellow = true;
        tl->east_west_state.is_red = false;
        print_traffic_light(tl);
        sleep(YELLOW_INTERVAL);

        // Switch to east-west traffic light being green
        tl->north_south_state.is_green = false;
        tl->north_south_state.is_yellow = false;
        tl->north_south_state.is_red = true;
        tl->east_west_state.is_green = true;
        tl->east_west_state.is_yellow = false;
        tl->east_west_state.is_red = false;
        print_traffic_light(tl);
        sleep(GREEN_INTERVAL);

        // Switch to yellow for both traffic lights
        tl->north_south_state.is_green = false;
        tl->north_south_state.is_yellow = true;
        tl->north_south_state.is_red = false;
        tl->east_west_state.is_green = false;
        tl->east_west_state.is_yellow = true;
        tl->east_west_state.is_red = false;
        print_traffic_light(tl);
        sleep(YELLOW_INTERVAL);
    }
    pthread_exit(NULL);
}