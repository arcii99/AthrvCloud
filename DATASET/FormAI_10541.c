//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define NUM_CARS 15
#define MAX_SPEED 5

void initialize_road(int road[ROAD_LENGTH]) {
    int i;
    for (i = 0; i < ROAD_LENGTH; i++) {
        road[i] = -1;
    }
}

void print_road(int road[ROAD_LENGTH]) {
    int i;
    for (i = 0; i < ROAD_LENGTH; i++) {
        if (road[i] == -1) {
            printf("-");
        } else {
            printf("%d", road[i]);
        }
    }
    printf("\n");
}

void add_cars(int road[ROAD_LENGTH]) {
    int i, pos;
    srand(time(NULL));
    for (i = 0; i < NUM_CARS; i++) {
        do {
            pos = rand() % ROAD_LENGTH;
        } while (road[pos] != -1);
        road[pos] = rand() % MAX_SPEED;
    }
}

void move_cars(int road[ROAD_LENGTH]) {
    int i, j, new_pos;
    for (i = 0; i < ROAD_LENGTH; i++) {
        if (road[i] != -1) {
            new_pos = i + road[i];
            if (new_pos >= ROAD_LENGTH) {
                road[i] = -1;
            } else if (road[new_pos] == -1) {
                road[new_pos] = road[i];
                road[i] = -1;
            }
        }
    }
}

int main() {
    int road[ROAD_LENGTH];
    int time_step = 1;
    initialize_road(road);
    add_cars(road);
    print_road(road);
    while (1) {
        move_cars(road);
        print_road(road);
        time_step++;
        if (time_step > 10) {
            break;
        }
    }
    return 0;
}