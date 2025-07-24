//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define MAX_SPEED 5
#define CAR_DENSITY 0.4

typedef struct {
    int position;
    int speed;
} Car;

void print_road(Car *road);
void move_car(Car *road, int idx);

int main() {
    srand(time(NULL));

    Car road[ROAD_LENGTH];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < CAR_DENSITY) {
            road[i].position = i;
            road[i].speed = rand() % MAX_SPEED + 1;
        }
        else {
            road[i].position = -1;
            road[i].speed = 0;
        }
    }

    printf("Initial state:\n");
    print_road(road);

    for (int t = 0; t < 10; t++) {
        printf("Time step %d:\n", t + 1);

        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i].position != -1) {
                move_car(road, i);
            }
        }

        print_road(road);
    }

    return 0;
}

void print_road(Car *road) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].position != -1) {
            printf("%d", road[i].position);
        }
        else {
            printf(".");
        }
    }
    printf("\n");
}

void move_car(Car *road, int idx) {
    int next_pos = (idx + road[idx].speed) % ROAD_LENGTH;
    int collision = 0;

    for (int i = 1; i <= road[idx].speed; i++) {
        int next_idx = (idx + i) % ROAD_LENGTH;
        if (road[next_idx].position != -1 && i <= road[next_idx].position - idx) {
            collision = 1;
            break;
        }
    }

    if (!collision) {
        road[next_pos].position = next_pos;
        road[next_pos].speed = road[idx].speed;
        road[idx].position = -1;
        road[idx].speed = 0;
    }
    else {
        road[idx].speed = road[next_pos].position - road[idx].position - 1;
    }
}