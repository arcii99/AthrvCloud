//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the maximum number of allowed cars on the road
#define MAX_CARS_ALLOWED 10

// Define the waiting time for green and yellow lights
#define GREEN_WAIT_TIME 10
#define YELLOW_WAIT_TIME 3

// Define the traffic light states
typedef enum {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT
} LightState;

// Define the traffic light controller states
typedef enum {
    NORMAL_STATE,
    CONGESTION_STATE
} ControllerState;

// Define a traffic light struct
typedef struct {
    LightState state;
    int timeLeft;
} TrafficLight;

// Define a list of traffic lights for each lane
TrafficLight lane1[3];
TrafficLight lane2[3];
TrafficLight lane3[3];

// Define the controller state variable
ControllerState controllerState = NORMAL_STATE;

// Define a function to print the current traffic light states
void printTrafficLights() {
    printf("Lane 1: ");
    for (int i = 0; i < 3; i++) {
        if (lane1[i].state == RED_LIGHT) {
            printf("RED ");
        } else if (lane1[i].state == YELLOW_LIGHT) {
            printf("YELLOW ");
        } else {
            printf("GREEN ");
        }
    }
    printf("\n");

    printf("Lane 2: ");
    for (int i = 0; i < 3; i++) {
        if (lane2[i].state == RED_LIGHT) {
            printf("RED ");
        } else if (lane2[i].state == YELLOW_LIGHT) {
            printf("YELLOW ");
        } else {
            printf("GREEN ");
        }
    }
    printf("\n");

    printf("Lane 3: ");
    for (int i = 0; i < 3; i++) {
        if (lane3[i].state == RED_LIGHT) {
            printf("RED ");
        } else if (lane3[i].state == YELLOW_LIGHT) {
            printf("YELLOW ");
        } else {
            printf("GREEN ");
        }
    }
    printf("\n");
}

// Define a function to check if a lane has cars waiting
int hasCarsWaiting(TrafficLight lane[]) {
    for (int i = 0; i < 3; i++) {
        if (lane[i].timeLeft > 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Initialize the traffic lights
    for (int i = 0; i < 3; i++) {
        lane1[i].state = RED_LIGHT;
        lane1[i].timeLeft = 0;
        lane2[i].state = RED_LIGHT;
        lane2[i].timeLeft = 0;
        lane3[i].state = RED_LIGHT;
        lane3[i].timeLeft = 0;
    }

    // Start the simulation
    int carCount1 = 0;
    int carCount2 = 0;
    int carCount3 = 0;
    int totalTime = 0;
    while (totalTime < 60) {
        printf("********** Time: %d seconds **********\n", totalTime);

        // Update the traffic light states
        for (int i = 0; i < 3; i++) {
            // Update lane 1
            if (lane1[i].state == RED_LIGHT) {
                if (hasCarsWaiting(lane1) || controllerState == CONGESTION_STATE) {
                    // Switch to green if there are cars waiting or if the controller is in congestion state
                    printf("Lane 1: Switching to GREEN\n");
                    lane1[i].state = GREEN_LIGHT;
                    lane1[i].timeLeft = GREEN_WAIT_TIME;
                }
            } else if (lane1[i].state == YELLOW_LIGHT) {
                // Switch to red after yellow light is up
                printf("Lane 1: Switching to RED\n");
                lane1[i].state = RED_LIGHT;
                lane1[i].timeLeft = 0;
            } else {
                // Update the green light timer
                if (lane1[i].timeLeft == 0) {
                    // Switch to yellow light when the green light time is up
                    printf("Lane 1: Switching to YELLOW\n");
                    lane1[i].state = YELLOW_LIGHT;
                    lane1[i].timeLeft = YELLOW_WAIT_TIME;
                } else {
                    // Decrement the green light timer
                    lane1[i].timeLeft--;
                }
            }

            // Update lane 2
            if (lane2[i].state == RED_LIGHT) {
                if (hasCarsWaiting(lane2) || controllerState == CONGESTION_STATE) {
                    // Switch to green if there are cars waiting or if the controller is in congestion state
                    printf("Lane 2: Switching to GREEN\n");
                    lane2[i].state = GREEN_LIGHT;
                    lane2[i].timeLeft = GREEN_WAIT_TIME;
                }
            } else if (lane2[i].state == YELLOW_LIGHT) {
                // Switch to red after yellow light is up
                printf("Lane 2: Switching to RED\n");
                lane2[i].state = RED_LIGHT;
                lane2[i].timeLeft = 0;
            } else {
                // Update the green light timer
                if (lane2[i].timeLeft == 0) {
                    // Switch to yellow light when the green light time is up
                    printf("Lane 2: Switching to YELLOW\n");
                    lane2[i].state = YELLOW_LIGHT;
                    lane2[i].timeLeft = YELLOW_WAIT_TIME;
                } else {
                    // Decrement the green light timer
                    lane2[i].timeLeft--;
                }
            }

            // Update lane 3
            if (lane3[i].state == RED_LIGHT) {
                if (hasCarsWaiting(lane3) || controllerState == CONGESTION_STATE) {
                    // Switch to green if there are cars waiting or if the controller is in congestion state
                    printf("Lane 3: Switching to GREEN\n");
                    lane3[i].state = GREEN_LIGHT;
                    lane3[i].timeLeft = GREEN_WAIT_TIME;
                }
            } else if (lane3[i].state == YELLOW_LIGHT) {
                // Switch to red after yellow light is up
                printf("Lane 3: Switching to RED\n");
                lane3[i].state = RED_LIGHT;
                lane3[i].timeLeft = 0;
            } else {
                // Update the green light timer
                if (lane3[i].timeLeft == 0) {
                    // Switch to yellow light when the green light time is up
                    printf("Lane 3: Switching to YELLOW\n");
                    lane3[i].state = YELLOW_LIGHT;
                    lane3[i].timeLeft = YELLOW_WAIT_TIME;
                } else {
                    // Decrement the green light timer
                    lane3[i].timeLeft--;
                }
            }
        }

        // Generate some random cars
        if (rand() % 4 == 0 && carCount1 < MAX_CARS_ALLOWED) {
            printf("Car added to lane 1\n");
            lane1[2].timeLeft = GREEN_WAIT_TIME + YELLOW_WAIT_TIME;
            carCount1++;
        }
        if (rand() % 3 == 0 && carCount2 < MAX_CARS_ALLOWED) {
            printf("Car added to lane 2\n");
            lane2[2].timeLeft = GREEN_WAIT_TIME + YELLOW_WAIT_TIME;
            carCount2++;
        }
        if (rand() % 5 == 0 && carCount3 < MAX_CARS_ALLOWED) {
            printf("Car added to lane 3\n");
            lane3[2].timeLeft = GREEN_WAIT_TIME + YELLOW_WAIT_TIME;
            carCount3++;
        }

        // Check if any cars have left the lane
        if (lane1[0].state != GREEN_LIGHT && lane1[1].state != GREEN_LIGHT && lane1[2].state != GREEN_LIGHT) {
            carCount1 = 0;
        }
        if (lane2[0].state != GREEN_LIGHT && lane2[1].state != GREEN_LIGHT && lane2[2].state != GREEN_LIGHT) {
            carCount2 = 0;
        }
        if (lane3[0].state != GREEN_LIGHT && lane3[1].state != GREEN_LIGHT && lane3[2].state != GREEN_LIGHT) {
            carCount3 = 0;
        }

        printTrafficLights();

        // Increment the simulation time
        totalTime++;

        // Check if the traffic is congested
        if (carCount1 + carCount2 + carCount3 > MAX_CARS_ALLOWED * 3) {
            controllerState = CONGESTION_STATE;
            printf("Controller is in congestion state\n");
        } else {
            controllerState = NORMAL_STATE;
        }

        // Wait for one second
        sleep(1);
    }

    return 0;
}