//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define MAX_SPEED 5

typedef enum { NS, EW } Direction;
typedef struct {
    int position;
    int speed;
    Direction direction;
} Car;

int random_speed() {
    return rand() % (MAX_SPEED + 1);
}

void print_state(Car *cars) {
    char road[ROAD_LENGTH];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '-';
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < ROAD_LENGTH; j++) {
            if (cars[i].direction == EW && cars[i].position == j) {
                road[j] = 'E';
            } else if (cars[i].direction == NS && cars[i].position == j) {
                road[j] = 'N';
            }
        }
    }

    printf("%s\n", road);
}

void tick(Car *cars) {
    for (int i = 0; i < 2; i++) {
        if (cars[i].direction == EW) {
            for (int j = i + 1; j < 2; j++) {
                if (cars[j].position > cars[i].position) {
                    cars[i].speed = cars[j].position - cars[i].position - 1;
                    break;
                }
            }
            if (cars[i].position + cars[i].speed < ROAD_LENGTH) {
                cars[i].position += cars[i].speed;
            } else {
                cars[i].position = 0;
                cars[i].speed = random_speed();
            }
        } else {
            for (int j = i + 1; j < 2; j++) {
                if (cars[j].position < cars[i].position) {
                    cars[i].speed = cars[i].position - cars[j].position - 1;
                    break;
                }
            }
            if (cars[i].position - cars[i].speed >= 0) {
                cars[i].position -= cars[i].speed;
            } else {
                cars[i].position = ROAD_LENGTH - 1;
                cars[i].speed = random_speed();
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Car car1 = {2, 3, NS};
    Car car2 = {7, 2, EW};
    Car cars[2] = {car1, car2};

    for (int i = 0; i < 10; i++) {
        print_state(cars);
        tick(cars);
    }

    return 0;
}