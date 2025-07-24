//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_SIZE 10
#define MAX_CARS 30

typedef struct Car {
    int speed;
    int position;
} Car;

typedef struct Lane {
    Car cars[MAX_CARS];
    int size;
} Lane;

int rand_int(int max) {
    return rand() % max;
}

void update_car_position(Car *car) {
    car->position += car->speed;
}

void update_lane(Lane *lane) {
    for (int i = 0; i < lane->size; i++) {
        update_car_position(&lane->cars[i]);
    }
}

void print_lane(Lane *lane) {
    for (int i = 0; i < LANE_SIZE; i++) {
        int printed = 0;
        for (int j = 0; j < lane->size; j++) {
            if (lane->cars[j].position == i) {
                printf("%d", j);
                printed = 1;
                break;
            }
        }
        if (!printed) {
            printf("-");
        }
    }
    printf("\n");
}

void add_car(Lane *lane, int speed) {
    if (lane->size == MAX_CARS) {
        return;
    }
    Car new_car = {speed, 0};
    lane->cars[lane->size] = new_car;
    lane->size++;
}

int main() {
    srand(time(0));
    Lane lane = {0};
    for (int i = 0; i < 10; i++) {
        add_car(&lane, rand_int(11));
    }
    while (1) {
        system("clear");
        print_lane(&lane);
        update_lane(&lane);
        for (int i = 0; i < lane.size; i++) {
            if (lane.cars[i].position > LANE_SIZE) {
                printf("Car %d has exited the lane\n", i);
                lane.cars[i] = lane.cars[lane.size - 1];
                lane.size--;
            }
        }
        if (rand_int(10) == 0) {
            add_car(&lane, rand_int(11));
        }
        sleep(1);
    }
    return 0;
}