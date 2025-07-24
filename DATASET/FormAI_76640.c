//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>

//define a function to control drone's movements
void droneControl(int aileron, int elevator, int throttle, int rudder) {
    printf("Drone controls: Aileron %d, Elevator %d, Throttle %d, Rudder %d\n", aileron, elevator, throttle, rudder);
}

int main() {
    //initialize variables for drone's movements
    int aileron = 0;
    int elevator = 0;
    int throttle = 0;
    int rudder = 0;

    //drone takes off and reaches an altitude of 50 feet
    throttle = 50;
    droneControl(aileron, elevator, throttle, rudder);
    printf("Drone takes off and reaches 50 feet altitude\n");

    //drone moves forward with a speed of 20 feet per second
    aileron = 10;
    elevator = 0;
    rudder = 0;
    droneControl(aileron, elevator, throttle, rudder);
    printf("Drone moves forward with a speed of 20 feet per second\n");

    //drone turns left by 45 degrees
    aileron = 0;
    elevator = 5;
    rudder = -45;
    droneControl(aileron, elevator, throttle, rudder);
    printf("Drone turns left by 45 degrees\n");

    //drone lands and stops moving
    throttle = 0;
    droneControl(aileron, elevator, throttle, rudder);
    printf("Drone lands and stops moving\n");

    return 0;
}