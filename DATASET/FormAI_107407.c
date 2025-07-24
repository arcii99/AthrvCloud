//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_CARS 20
#define MIN_SPEED 30
#define MAX_SPEED 60

struct car {
    int speed;
    char direction;
    int distance;
};

void update_car(struct car *c) {
    if (rand() % 2 == 0) {
        if (c->speed == 0) {
            c->speed = MIN_SPEED;
        } else {
            c->speed--;
        }
    } else if (c->speed < MAX_SPEED) {
        c->speed++;
    }
    c->distance += c->speed;
}

void print_car(struct car c) {
    printf("Speed: %d, Direction: %c, Distance: %d\n", c.speed, c.direction, c.distance);
}

int main() {
    srand(time(NULL));
    struct car cars[MAX_CARS];
    int i, j, distance = 0, collisions = 0;
    char directions[2] = {'N', 'S'};

    for (i = 0; i < MAX_CARS; i++) {
        cars[i].speed = 0;
        cars[i].direction = directions[rand() % 2];
        cars[i].distance = distance;
        distance += (rand() % 200) + 100;
    }

    while (true) {
        system("clear");
        collisions = 0;
        for (i = 0; i < MAX_CARS; i++) {
            update_car(&cars[i]);
            print_car(cars[i]);
        }
        for (i = 0; i < MAX_CARS; i++) {
            for (j = i + 1; j < MAX_CARS; j++) {
                if (cars[i].direction == 'N' && cars[j].direction == 'S'
                        && cars[i].distance < cars[j].distance && cars[i].distance + 50 >= cars[j].distance) {
                    collisions++;
                } else if (cars[i].direction == 'S' && cars[j].direction == 'N'
                        && cars[j].distance < cars[i].distance && cars[j].distance + 50 >= cars[i].distance) {
                    collisions++;
                }
            }
        }
        printf("Collisions: %d\n", collisions);
        sleep(1);
    }

    return 0;
}