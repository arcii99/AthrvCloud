//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>

struct droneRemoteControl {
    int powerLevel;
    int speedLevel;
    int altitude;
    int direction;
    char mode[20];
};

void printStatus(struct droneRemoteControl remote) {
    printf("Remote Control Status:\n");
    printf("Power Level: %d\n", remote.powerLevel);
    printf("Speed Level: %d\n", remote.speedLevel);
    printf("Altitude: %d\n", remote.altitude);
    printf("Direction: %d\n", remote.direction);
    printf("Mode: %s\n", remote.mode);
}

void takeOff(struct droneRemoteControl* remote) {
    printf("Drone taking off...\n");
    remote->altitude = 50;
}

void ascend(struct droneRemoteControl* remote) {
    printf("Ascending...\n");
    remote->altitude += 10;
}

void descend(struct droneRemoteControl* remote) {
    printf("Descending...\n");
    remote->altitude -= 10;
}

void moveLeft(struct droneRemoteControl* remote) {
    printf("Moving left...\n");
    remote->direction -= 1;
}

void moveRight(struct droneRemoteControl* remote) {
    printf("Moving right...\n");
    remote->direction += 1;
}

void increaseSpeed(struct droneRemoteControl* remote) {
    printf("Increasing speed...\n");
    remote->speedLevel += 1;
}

void decreaseSpeed(struct droneRemoteControl* remote) {
    printf("Decreasing speed...\n");
    remote->speedLevel -= 1;
}

int main() {
    struct droneRemoteControl remote = { 100, 0, 0, 0, "Beginner" };
    printStatus(remote); // should print initial values

    takeOff(&remote);
    ascend(&remote);
    moveLeft(&remote);
    increaseSpeed(&remote);
    printStatus(remote); // should reflect changes made to drone

    return 0;
}