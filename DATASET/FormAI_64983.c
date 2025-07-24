//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
// Robot Movement Control Example Program in C
// Written in Donald Knuth Style

#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 1
#define RIGHT -1

struct Robot {
    int x, y;
    int angle;
};

int main() {
    struct Robot r;
    r.x = 0;
    r.y = 0;
    r.angle = 0;
    
    printf("Starting Position: (%d,%d)\n", r.x, r.y);
    
    // move forward 5 units
    move(FORWARD, 5, &r);
    printf("Moved 5 units forward. New Position: (%d,%d)\n", r.x, r.y);
    
    // turn left 45 degrees
    turn(LEFT, 45, &r);
    printf("Turned 45 degrees left. New Angle: %d\n", r.angle);
    
    // move backward 3 units
    move(BACKWARD, 3, &r);
    printf("Moved 3 units backward. New Position: (%d,%d)\n", r.x, r.y);
    
    // turn right 90 degrees
    turn(RIGHT, 90, &r);
    printf("Turned 90 degrees right. New Angle: %d\n", r.angle);
    
    // move forward 7 units
    move(FORWARD, 7, &r);
    printf("Moved 7 units forward. New Position: (%d,%d)\n", r.x, r.y);

    return 0;
}

// move robot in the current direction it is facing
void move(int direction, int units, struct Robot *r) {
    if (r->angle == 0) {
        r->x += direction * units;
    } else if (r->angle == 90) {
        r->y += direction * units;
    } else if (r->angle == 180) {
        r->x -= direction * units;
    } else if (r->angle == 270) {
        r->y -= direction * units;
    }
}

// turn robot in the specified direction (LEFT/RIGHT) and angle (degrees)
void turn(int direction, int angle, struct Robot *r) {
    if (direction == LEFT) {
        r->angle = (r->angle + angle) % 360;
    } else if (direction == RIGHT) {
        r->angle = (r->angle - angle) % 360;
    }
}