//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: innovative
#include <stdio.h>

struct Drone {
    int id;
    double x, y, z;
};

struct RemoteControl {
    void (*move_up)(struct Drone*);
    void (*move_down)(struct Drone*);
    void (*move_left)(struct Drone*);
    void (*move_right)(struct Drone*);
};

void move_up(struct Drone* drone) {
    printf("Moving Drone %d up!\n", drone->id);
    drone->z += 5.0;
}

void move_down(struct Drone* drone) {
    printf("Moving Drone %d down!\n", drone->id);
    drone->z -= 5.0;
}

void move_left(struct Drone* drone) {
    printf("Moving Drone %d left!\n", drone->id);
    drone->x -= 5.0;
}

void move_right(struct Drone* drone) {
    printf("Moving Drone %d right!\n", drone->id);
    drone->x += 5.0;
}

int main() {
    struct Drone drone1 = {1, 0.0, 0.0, 0.0};
    struct Drone drone2 = {2, 10.0, 10.0, 10.0};

    struct RemoteControl rc1 = {move_up, move_down, move_left, move_right};
    struct RemoteControl rc2 = {move_up, move_down, move_left, move_right};

    printf("Controlling Drone 1...\n");
    rc1.move_up(&drone1);
    rc1.move_right(&drone1);
    rc1.move_down(&drone1);
    rc1.move_left(&drone1);
    printf("Drone 1 is at (%.2lf, %.2lf, %.2lf)\n", drone1.x, drone1.y, drone1.z);

    printf("\nControlling Drone 2...\n");
    rc2.move_down(&drone2);
    rc2.move_left(&drone2);
    rc2.move_up(&drone2);
    rc2.move_right(&drone2);
    printf("Drone 2 is at (%.2lf, %.2lf, %.2lf)\n", drone2.x, drone2.y, drone2.z);

    return 0;
}