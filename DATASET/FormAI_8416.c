//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct remoteControl {
    int power; 
    int throttle;
    int pitch; 
    int roll;
};

void initializeRemoteControl(struct remoteControl* rc) {
    rc->power = 0;
    rc->throttle = 0;
    rc->pitch = 0;
    rc->roll = 0;
}

void printRemoteControlStatus(struct remoteControl* rc) {
    printf("Power: %d\n", rc->power);
    printf("Throttle: %d\n", rc->throttle);
    printf("Pitch: %d\n", rc->pitch);
    printf("Roll: %d\n\n", rc->roll);
}

int main() {
    struct remoteControl myRemoteControl;
    initializeRemoteControl(&myRemoteControl);
    printRemoteControlStatus(&myRemoteControl);

    printf("Turning remote control on...\n");
    myRemoteControl.power = 1;
    printRemoteControlStatus(&myRemoteControl);

    printf("Increasing throttle...\n");
    myRemoteControl.throttle = 50;
    printRemoteControlStatus(&myRemoteControl);

    printf("Moving pitch up...\n");
    myRemoteControl.pitch = 20;
    printRemoteControlStatus(&myRemoteControl);

    printf("Moving roll left...\n");
    myRemoteControl.roll = -10;
    printRemoteControlStatus(&myRemoteControl);

    printf("Turning remote control off...\n");
    myRemoteControl.power = 0;
    printRemoteControlStatus(&myRemoteControl);

    return 0;
}