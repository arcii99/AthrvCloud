//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 10

struct vehicle {
    int id;
    int speed;
    int direction;
};

typedef struct vehicle Vehicle;

void move(Vehicle *v, int speed, int direction) {
    v->speed = speed > MAX_SPEED ? MAX_SPEED : speed;
    if (v->speed < 0) v->speed = 0;
    if (direction < 0) {
        v->direction = (v->direction + direction) % 360;
        if (v->direction < 0) v->direction += 360;
    } else if (direction > 0) {
        v->direction = (v->direction + direction) % 360;
    }
    printf("Vehicle %d is moving at %d mph, heading %d degrees\n", v->id, v->speed, v->direction);
}

int main() {
    Vehicle v1 = {1, 0, 0};
    Vehicle v2 = {2, 0, 180};
    
    move(&v1, 5, 90); // Vehicle 1 is moving at 5 mph, heading 90 degrees
    move(&v1, -2, 0); // Vehicle 1 is stopped, heading 90 degrees
    move(&v1, 15, 45); // Vehicle 1 is moving at 10 mph, heading 135 degrees
    move(&v2, 8, -90); // Vehicle 2 is moving at 8 mph, heading 90 degrees
    move(&v2, -5, 0); // Vehicle 2 is stopped, heading 90 degrees
    
    return 0;
}