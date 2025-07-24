//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define NUM_CARS 5

typedef struct {
    int position;
    int speed;
} Car;

void print_road(Car cars[NUM_CARS]) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        char symbol = '-';
        for (int j = 0; j < NUM_CARS; j++) {
            if (cars[j].position == i) {
                symbol = 'C';
            }
        }
        printf("%c", symbol);
    }
    printf("\n");
}

void drive(Car cars[NUM_CARS]) {
    for (int i = 0; i < NUM_CARS; i++) {
        int distance_to_next_car = ROAD_LENGTH;
        for (int j = 0; j < NUM_CARS; j++) {
            if (i != j && cars[j].position > cars[i].position) {
                int distance = cars[j].position - cars[i].position;
                if (distance < distance_to_next_car) {
                    distance_to_next_car = distance;
                }
            }
        }
        if (cars[i].speed < distance_to_next_car && cars[i].speed < ROAD_LENGTH - cars[i].position) {
            cars[i].speed++;
        } else if (cars[i].speed > distance_to_next_car) {
            cars[i].speed = distance_to_next_car;
        }
        cars[i].position += cars[i].speed;
        if (cars[i].position >= ROAD_LENGTH) {
            cars[i].position = 0;
        }
    }
}

int main() {
    Car cars[NUM_CARS] = {
        {2, 2},
        {5, 3},
        {8, 1},
        {12, 4},
        {16, 2}
    };

    srand(time(NULL));
    int time_elapsed = 0;
    while (time_elapsed < 100) {
        printf("Time: %d\n", time_elapsed);
        print_road(cars);
        drive(cars);
        time_elapsed++;
    }

    return 0;
}