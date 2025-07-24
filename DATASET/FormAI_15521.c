//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Drone {
    int x;
    int y;
    int z;
    bool isFlying;
};

void takeOff(struct Drone* drone, int height) {
    printf("Taking off to height %d\n", height);
    drone->z = height;
    drone->isFlying = true;
}

void land(struct Drone* drone) {
    printf("Landing the drone\n");
    drone->z = 0;
    drone->isFlying = false;
}

void move(struct Drone* drone, int dx, int dy, int dz) {
    if(!drone->isFlying) {
        printf("The drone is not flying! Cannot move.\n");
        return;
    }
    drone->x += dx;
    drone->y += dy;
    drone->z += dz;
    printf("Moved the drone to (%d, %d, %d)\n", drone->x, drone->y, drone->z);
}

void status(struct Drone* drone) {
    printf("Status of drone: ");
    if(drone->isFlying) {
        printf("Flying at (%d, %d, %d)\n", drone->x, drone->y, drone->z);
    } else {
        printf("Landed at (%d, %d, %d)\n", drone->x, drone->y, drone->z);
    }
}

int main() {
    struct Drone myDrone;
    myDrone.x = 0;
    myDrone.y = 0;
    myDrone.z = 0;
    myDrone.isFlying = false;
    
    takeOff(&myDrone, 10);
    status(&myDrone);
    move(&myDrone, 5, 0, 10);
    status(&myDrone);
    land(&myDrone);
    status(&myDrone);
    
    return 0;
}