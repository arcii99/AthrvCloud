//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: safe
#include <stdio.h>

// Drone struct definition
typedef struct Drone {
    int x, y, z;
    int speed;
    char *name;
    // Custom initialization method
    void (*init)(struct Drone *, char *, int);
    // Custom move method
    void (*move)(struct Drone *, int, int, int);
} Drone;

// Custom initialization method
void initDrone(Drone *drone, char *name, int speed) {
    drone->name = name;
    drone->speed = speed;
    drone->x = 0;
    drone->y = 0;
    drone->z = 0;
}

// Custom move method
void moveDrone(Drone *drone, int x, int y, int z) {
    printf("%s is moving from (%d, %d, %d) to (%d, %d, %d) at %d speed.\n", drone->name, drone->x, drone->y, drone->z, x, y, z, drone->speed);
    drone->x = x;
    drone->y = y;
    drone->z = z;
}

int main() {
    // Create a new drone
    Drone drone1;
    // Initialize drone
    drone1.init = initDrone;
    drone1.init(&drone1, "Drone 1", 100);
    // Move drone to position (10, 20, 30)
    drone1.move = moveDrone;
    drone1.move(&drone1, 10, 20, 30);

    // Create another drone
    Drone drone2;
    // Initialize drone
    drone2.init = initDrone;
    drone2.init(&drone2, "Drone 2", 150);
    // Move drone to position (50, 70, 90)
    drone2.move = moveDrone;
    drone2.move(&drone2, 50, 70, 90);

    return 0;
}