//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 100
#define MAX_LANES 3
#define MIN_GAP 5
#define MAX_GAP 10
#define MIN_LENGTH 5
#define MAX_LENGTH 10

typedef struct {
    int speed;
    int length;
    int gap;
    int lane;
} Car;

int cars_on_road = 0;
Car cars[MAX_CARS];
int road[MAX_LANES][MAX_CARS];

void add_car(int speed, int length, int gap, int lane) {
    if (cars_on_road >= MAX_CARS) {
        return;
    }

    cars[cars_on_road].speed = speed;
    cars[cars_on_road].length = length;
    cars[cars_on_road].gap = gap;
    cars[cars_on_road].lane = lane;

    road[lane][cars_on_road] = 1;

    cars_on_road++;
}

void move_car(int car_index) {
    int lane = cars[car_index].lane;
    int gap = cars[car_index].gap;

    // if there is no car in front of this car
    if (car_index == 0 || (car_index > 0 && gap >= cars[car_index - 1].length + cars[car_index - 1].gap)) {
        road[cars[car_index].lane][car_index] = 0;
        cars[car_index].gap = gap - cars[car_index].speed;
        cars[car_index].gap = cars[car_index].gap < 0 ? 0 : cars[car_index].gap;
        cars[car_index].lane = lane;
        road[cars[car_index].lane][car_index] = 1;
    }
    // if there is a car in front of this car and we can't overtake it
    else if (gap < cars[car_index - 1].length + cars[car_index - 1].gap) {
        cars[car_index].gap = cars[car_index - 1].length + cars[car_index - 1].gap;
    }
    // if there is a car in front of this car and we can overtake it
    else if (gap >= cars[car_index - 1].length + cars[car_index - 1].gap && cars[car_index].lane > 0) {
        road[cars[car_index].lane][car_index] = 0;
        cars[car_index].gap = gap - cars[car_index].speed;
        cars[car_index].gap = cars[car_index].gap < 0 ? 0 : cars[car_index].gap;
        cars[car_index].lane = lane - 1;
        road[cars[car_index].lane][car_index] = 1;
    }
}

int main() {
    srand(time(NULL));

    // populate initial cars
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        int speed = rand() % MAX_SPEED + 1;
        int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
        int gap = rand() % (MAX_GAP - MIN_GAP + 1) + MIN_GAP;
        int lane = rand() % MAX_LANES;
        add_car(speed, length, gap, lane);
    }

    int iterations = 100;
    for (i = 0; i < iterations; i++) {
        // move cars
        int j;
        for (j = 0; j < MAX_CARS; j++) {
            move_car(j);
        }

        // print cars
        int k, l;
        for (k = 0; k < MAX_LANES; k++) {
            printf("lane %d: ", k);
            for (l = 0; l < MAX_CARS; l++) {
                if (road[k][l] == 1) {
                    printf("%c", 'A' + l);
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}