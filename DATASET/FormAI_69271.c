//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light colors
#define NONE "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"

// Define traffic light times
#define RED_TIME 10
#define YELLOW_TIME 3
#define GREEN_TIME 10

// Define traffic light status
typedef enum {
    RED_STATUS,
    YELLOW_STATUS,
    GREEN_STATUS
} TrafficLightStatus;

// Define traffic light
typedef struct {
    TrafficLightStatus status;
    int time;
} TrafficLight;

// Define traffic light controller
typedef struct {
    TrafficLight traffic_lights[3];
} TrafficLightController;

// Function to set traffic light status
void set_traffic_light_status(TrafficLight* traffic_light, TrafficLightStatus status, int time) {
    traffic_light->status = status;
    traffic_light->time = time;
}

// Function to print traffic light status
void print_traffic_light_status(TrafficLight* traffic_light) {
    switch(traffic_light->status) {
        case RED_STATUS:
            printf("%sRED%s\n", RED, NONE);
            break;
        case YELLOW_STATUS:
            printf("%sYELLOW%s\n", YELLOW, NONE);
            break;
        case GREEN_STATUS:
            printf("%sGREEN%s\n", GREEN, NONE);
            break;
        default:
            printf("Invalid Traffic Light Status\n");
    }
}

// Function to update traffic light controller
void update_traffic_light_controller(TrafficLightController* traffic_light_controller) {
    switch(traffic_light_controller->traffic_lights[0].status) {
        case RED_STATUS:
            if(traffic_light_controller->traffic_lights[0].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[0], GREEN_STATUS, GREEN_TIME);
                set_traffic_light_status(&traffic_light_controller->traffic_lights[1], RED_STATUS, RED_TIME);
            }
            break;
        case YELLOW_STATUS:
            if(traffic_light_controller->traffic_lights[0].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[1], GREEN_STATUS, GREEN_TIME);
                set_traffic_light_status(&traffic_light_controller->traffic_lights[0], RED_STATUS, RED_TIME);
            }
            break;
        case GREEN_STATUS:
            if(traffic_light_controller->traffic_lights[0].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[0], YELLOW_STATUS, YELLOW_TIME);
            }
            break;
    }

    switch(traffic_light_controller->traffic_lights[1].status) {
        case RED_STATUS:
            if(traffic_light_controller->traffic_lights[1].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[1], YELLOW_STATUS, YELLOW_TIME);
                set_traffic_light_status(&traffic_light_controller->traffic_lights[2], RED_STATUS, RED_TIME);
            }
            break;
        case YELLOW_STATUS:
            if(traffic_light_controller->traffic_lights[1].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[2], GREEN_STATUS, GREEN_TIME);
                set_traffic_light_status(&traffic_light_controller->traffic_lights[1], RED_STATUS, RED_TIME);
            }
            break;
        case GREEN_STATUS:
            if(traffic_light_controller->traffic_lights[1].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[1], YELLOW_STATUS, YELLOW_TIME);
            }
            break;
    }

    switch(traffic_light_controller->traffic_lights[2].status) {
        case RED_STATUS:
            if(traffic_light_controller->traffic_lights[2].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[0], RED_STATUS, RED_TIME);
                set_traffic_light_status(&traffic_light_controller->traffic_lights[2], YELLOW_STATUS, YELLOW_TIME);
            }
            break;
        case YELLOW_STATUS:
            if(traffic_light_controller->traffic_lights[2].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[0], GREEN_STATUS, GREEN_TIME);
                set_traffic_light_status(&traffic_light_controller->traffic_lights[2], RED_STATUS, RED_TIME);
            }
            break;
        case GREEN_STATUS:
            if(traffic_light_controller->traffic_lights[2].time == 0) {
                set_traffic_light_status(&traffic_light_controller->traffic_lights[2], YELLOW_STATUS, YELLOW_TIME);
            }
            break;
    }

    return;
}

// Function to print traffic light controller status
void print_traffic_light_controller_status(TrafficLightController* traffic_light_controller) {
    printf("                          TRAFFIC LIGHT CONTROLLER\n");
    printf("__________________________________________________________________________\n\n");
    printf("                             NORTH/SOUTH DIRECTION\n\n");
    printf("                                            |    \n");
    printf("       ");
    print_traffic_light_status(&traffic_light_controller->traffic_lights[0]);
    printf("                                            |    \n");
    printf("                  EAST/WEST DIRECTION        |\n");
    printf("__________________________          ________________\n");
    printf("|                         |        |               |\n");
    printf("       ");
    print_traffic_light_status(&traffic_light_controller->traffic_lights[1]);
    printf("                         |        |               |\n");
    printf("|                         |        |               |\n");
    printf("|      TRAFFIC LIGHT      |________|   TRAFFIC    |\n");
    printf("|                         |        |     LIGHT     |\n");
    printf("|                         |        |               |\n");
    printf("       ");
    print_traffic_light_status(&traffic_light_controller->traffic_lights[2]);
    printf("                         |        |               |\n");
    printf("|_________________________|        |_______________|\n\n");
}

// Main function
int main(void) {
    TrafficLightController traffic_light_controller;

    // Initialize random seed
    srand(time(0));

    // Initialize traffic light controller
    set_traffic_light_status(&traffic_light_controller.traffic_lights[0], GREEN_STATUS, rand() % (GREEN_TIME - 1) + 1);
    set_traffic_light_status(&traffic_light_controller.traffic_lights[1], RED_STATUS, RED_TIME);
    set_traffic_light_status(&traffic_light_controller.traffic_lights[2], RED_STATUS, RED_TIME);

    // Print initial traffic light controller status
    print_traffic_light_controller_status(&traffic_light_controller);

    // Loop through traffic light controller
    while(true) {
        // Update traffic light controller
        update_traffic_light_controller(&traffic_light_controller);

        // Print current traffic light controller status
        print_traffic_light_controller_status(&traffic_light_controller);

        // Wait for 1 second
        printf("\033[1A");
        printf("\033[0G");
        printf("\033[2K");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}