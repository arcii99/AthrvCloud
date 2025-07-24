//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANES 3
#define CARS_PER_LANE 10
#define MAX_SPEED 80

typedef struct {
    int lane;
    int position;
    int speed;
} car;

void print_road(car cars[LANES][CARS_PER_LANE]) {
    int i, j;
    
    for (i = 0; i < LANES; i++) {
        for (j = 0; j < CARS_PER_LANE; j++) {
            if (cars[i][j].position == -1) {
                printf("~ ");
            } else {
                printf("%d ", cars[i][j].position);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void update_car_positions(car cars[LANES][CARS_PER_LANE]) {
    int i, j;
    
    // Move cars forward
    for (i = 0; i < LANES; i++) {
        for (j = 0; j < CARS_PER_LANE; j++) {
            if (cars[i][j].position != -1) {
                if (cars[i][j].position + cars[i][j].speed + 1 < CARS_PER_LANE) {
                    cars[i][j].position += cars[i][j].speed + 1;
                } else {
                    cars[i][j].position = -1;
                }
            }
        }
    }
    
    // Adjust car speeds
    for (i = 0; i < LANES; i++) {
        for (j = 0; j < CARS_PER_LANE; j++) {
            if (cars[i][j].position != -1) {
                if (j == 0 || cars[i][j-1].position == -1) {
                    cars[i][j].speed++;
                } else {
                    int gap = cars[i][j-1].position - cars[i][j].position - 1;
                    if (gap <= cars[i][j].speed) {
                        cars[i][j].speed = gap;
                    } else if (gap > cars[i][j].speed + 1) {
                        cars[i][j].speed++;
                    }
                }
                if (cars[i][j].speed > MAX_SPEED) {
                    cars[i][j].speed = MAX_SPEED;
                }
            }
        }
    }
}

void spawn_cars(car cars[LANES][CARS_PER_LANE], int spawn_lane) {
    int i;
    
    for (i = 0; i < CARS_PER_LANE; i++) {
        if (cars[spawn_lane][i].position == -1) {
            cars[spawn_lane][i].position = 0;
            cars[spawn_lane][i].speed = rand() % MAX_SPEED + 1;
            break;
        }
    }
}

int main() {
    int i, j;
    car cars[LANES][CARS_PER_LANE];
    srand(time(NULL));
    
    // Initialize road
    for (i = 0; i < LANES; i++) {
        for (j = 0; j < CARS_PER_LANE; j++) {
            cars[i][j] = (car) {i, -1, 0};
        }
    }
    
    // Spawn initial cars
    for (i = 0; i < LANES; i++) {
        spawn_cars(cars, i);
    }
    
    // Simulate traffic flow
    for (i = 0; i < 100; i++) {
        update_car_positions(cars);
        for (j = 0; j < LANES; j++) {
            if (rand() % 10 == 0) {
                spawn_cars(cars, j);
            }
        }
        print_road(cars);
    }
    
    return 0;
}