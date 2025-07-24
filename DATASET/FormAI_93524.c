//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SPEED 50
#define TURN_ANGLE 15

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int speed;
    int direction; // in degrees
} Velocity;

typedef struct {
    Position pos;
    Velocity vel;
} Vehicle;

void print_position(Position pos) {
    printf("(%d, %d)", pos.x, pos.y);
}

void print_vehicle(Vehicle veh) {
    printf("Car Position: ");
    print_position(veh.pos);
    printf("\nCar Speed: %d km/h\nCar Direction: %d degrees\n", veh.vel.speed, veh.vel.direction);
}

int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void set_random_direction(Vehicle *veh) {
    veh->vel.direction = rand_int(0, 359);
}

void accelerate(Vehicle *veh) {
    if (veh->vel.speed < MAX_SPEED) {
        veh->vel.speed++;
    }
}

void decelerate(Vehicle *veh) {
    if (veh->vel.speed > 0) {
        veh->vel.speed--;
    }
}

void turn_left(Vehicle *veh) {
    veh->vel.direction = (veh->vel.direction - TURN_ANGLE) % 360;
}

void turn_right(Vehicle *veh) {
    veh->vel.direction = (veh->vel.direction + TURN_ANGLE) % 360;
}

void move(Vehicle *veh) {
    // convert direction to radians and calculate x,y components of velocity
    double dir_radians = veh->vel.direction * 3.14159 / 180.0;
    int vel_x = veh->vel.speed * cos(dir_radians);
    int vel_y = veh->vel.speed * sin(dir_radians);
    veh->pos.x += vel_x;
    veh->pos.y += vel_y;
}

int main() {
    srand(time(NULL));

    Vehicle car = {{0, 0}, {0, 0}};
    print_vehicle(car);

    // drive the car for 10 seconds
    for (int i = 0; i < 100; i++) {
        int command = rand_int(1, 4);
        switch (command) {
            case 1:
                accelerate(&car);
                printf("Accelerated! ");
                print_vehicle(car);
                break;
            case 2:
                decelerate(&car);
                printf("Decelerated. ");
                print_vehicle(car);
                break;
            case 3:
                turn_left(&car);
                printf("Turned left. ");
                print_vehicle(car);
                break;
            case 4:
                turn_right(&car);
                printf("Turned right. ");
                print_vehicle(car);
                break;
        }
        move(&car);
        printf("Moved. ");
        print_vehicle(car);
        printf("\n");
    }

    return 0;
}