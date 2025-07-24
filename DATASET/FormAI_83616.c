//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_SPEED 4
#define LANE_LENGTH 100

struct car {
    int position;
    int speed;
};

void move_cars(struct car * cars, int car_count) {
    int i;
    for (i = 0; i < car_count; i++) {
        if (cars[i].speed > 0) {
            cars[i].position += cars[i].speed;

            if (cars[i].position >= LANE_LENGTH) {
                cars[i].position = 0;
            }
        }
    }
}

void update_car_speed(struct car * cars, int car_count) {
    int i, j;

    // find the distance to the next car
    for (i = 0; i < car_count; i++) {
        int distance_to_next = -1;
        for (j = i + 1; j < car_count; j++) {
            if (cars[j].position > cars[i].position) {
                distance_to_next = cars[j].position - cars[i].position;
                break;
            }
        }
        if (distance_to_next == -1) {
            distance_to_next = LANE_LENGTH - cars[i].position;
            for (j = 0; j < i; j++) {
                if (cars[j].position < cars[i].position) {
                    int distance_to_prev = cars[i].position - cars[j].position;
                    if (distance_to_prev < distance_to_next) {
                        distance_to_next = distance_to_prev;
                    }
                }
            }
        }
        int desired_speed = distance_to_next - 1;
        if (desired_speed > cars[i].speed + 1) {
            cars[i].speed += 1;
        } else if (desired_speed < cars[i].speed - 1) {
            cars[i].speed -= 1;
        }
        if (cars[i].speed > MAX_SPEED) {
            cars[i].speed = MAX_SPEED;
        } else if (cars[i].speed < 0) {
            cars[i].speed = 0;
        }
    }
}

void print_lane(struct car * cars, int car_count) {
    int i, j;
    char lane[LANE_LENGTH + 1];
    for (i = 0; i < LANE_LENGTH; i++) {
        lane[i] = ' ';
    }
    lane[LANE_LENGTH] = '\0';
    for (i = 0; i < car_count; i++) {
        lane[cars[i].position] = '@';
    }
    printf("%s\n", lane);
}

int main() {
    srand(time(NULL));

    struct car cars[MAX_CARS];
    int i;
    int car_count = 0;
    for (i = 0; i < MAX_CARS; i++) {
        if (rand() % 4 == 0) {
            cars[car_count].position = i * 2;
            cars[car_count].speed = rand() % (MAX_SPEED + 1);
            car_count += 1;
            if (car_count >= MAX_CARS) {
                break;
            }
        }
    }

    int time_step;
    printf("Starting traffic simulation\n");
    for (time_step = 0;; time_step++) {
        printf("Time step %d\n", time_step);
        print_lane(cars, car_count);
        update_car_speed(cars, car_count);
        move_cars(cars, car_count);
        int i, at_end = 1;
        for (i = 0; i < car_count; i++) {
            if (cars[i].position < LANE_LENGTH - 1) {
                at_end = 0;
                break;
            }
        }
        if (at_end) {
            break;
        }
    }

    printf("Simulation completed in %d time steps\n", time_step);

    return 0;
}