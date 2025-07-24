//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vehicle {
    int x; // x position of the vehicle
    int y; // y position of the vehicle
    int speed; // speed of the vehicle
    char direction[10]; // direction of the vehicle
};

void move(struct Vehicle* v, int distance)
{
    if(strcmp(v->direction, "up") == 0) {
        v->y += distance;
    } else if(strcmp(v->direction, "down") == 0) {
        v->y -= distance;
    } else if(strcmp(v->direction, "left") == 0) {
        v->x -= distance;
    } else if(strcmp(v->direction, "right") == 0) {
        v->x += distance;
    }
}

void turn(struct Vehicle* v, char* new_direction)
{
    strcpy(v->direction, new_direction);
}

int main()
{
    struct Vehicle my_vehicle = {0, 0, 5, "up"};

    printf("Starting position: (%d,%d), direction: %s\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);

    // turn right and move forward 10 units
    turn(&my_vehicle, "right");
    move(&my_vehicle, 10);

    printf("New position: (%d,%d), direction: %s\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);

    // turn down and move forward 5 units
    turn(&my_vehicle, "down");
    move(&my_vehicle, 5);

    printf("New position: (%d,%d), direction: %s\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);

    // turn left and move forward 7 units
    turn(&my_vehicle, "left");
    move(&my_vehicle, 7);

    printf("New position: (%d,%d), direction: %s\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);

    // turn up and move forward 2 units
    turn(&my_vehicle, "up");
    move(&my_vehicle, 2);

    printf("Final position: (%d,%d), direction: %s\n", my_vehicle.x, my_vehicle.y, my_vehicle.direction);

    return 0;
}