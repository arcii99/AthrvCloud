//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_LANES 4
#define LANE_LENGTH 20
#define MAX_CAR_SPEED 5

struct Car {
    int speed;
    int position;
    int lane;
};

void update_cars_position(struct Car cars[]);
void move_car_forward(struct Car* car);
void add_random_car(struct Car cars[]);
void print_traffic_light(int current_tick);
void print_traffic(struct Car cars[]);
void sleep(int delay_in_seconds);

int main() {
    struct Car cars[NUM_OF_LANES * LANE_LENGTH] = {0};
    int current_tick = 0;
    int green_light_ticks = 3;
    int ticks_since_green_light = 0;

    srand(time(0));

    while (1) {
        if (ticks_since_green_light >= green_light_ticks) {
            printf("Green light for %d ticks.\n", green_light_ticks);
            ticks_since_green_light = 0;
        }

        printf("Tick: %d\n", current_tick);

        if (current_tick % 3 == 0) {
            add_random_car(cars);
        }

        update_cars_position(cars);

        print_traffic_light(current_tick % 5);
        print_traffic(cars);

        ticks_since_green_light++;
        current_tick++;

        sleep(1);
    }

    return 0;
}

void update_cars_position(struct Car cars[]) {
    int i;

    for (i = 0; i < NUM_OF_LANES * LANE_LENGTH; i++) {
        if (cars[i].speed > 0) {
            cars[i].position += cars[i].speed;
        }

        if (cars[i].position >= LANE_LENGTH) {
            cars[i].speed = 0;
            cars[i].position = 0;
        }

        if (i > 0 && cars[i].position == cars[i - 1].position && cars[i].lane == cars[i - 1].lane) {
            cars[i].speed = 0;
        }
    }
}

void move_car_forward(struct Car* car) {
    car->position += car->speed;
}

void add_random_car(struct Car cars[]) {
    struct Car new_car = {
        .speed = rand() % MAX_CAR_SPEED + 1,
        .position = 0,
        .lane = rand() % NUM_OF_LANES
    };

    int i;

    for (i = 0; i < LANE_LENGTH; i++) {
        int index = new_car.lane * LANE_LENGTH + i;

        if (cars[index].speed == 0) {
            cars[index] = new_car;
            break;
        }
    }
}

void print_traffic_light(int current_tick) {
    if (current_tick == 0) {
        printf("  ______\n");
        printf(" /      \\\n");
        printf("/        \\\n");
    } else if (current_tick == 1) {
        printf("  =======\n");
        printf(" /      \\\n");
        printf("/        \\\n");
    } else if (current_tick == 2) {
        printf("  ______\n");
        printf(" /      \\\n");
        printf("/========\\\n");
    } else if (current_tick == 3) {
        printf("  ______\n");
        printf(" /      \\\n");
        printf("/========\\\n");
    } else if (current_tick == 4) {
        printf("  ______\n");
        printf(" /=======\\\n");
        printf("/        \\\n");
    }

    printf("\n");
}

void print_traffic(struct Car cars[]) {
    int i, j;

    for (i = 0; i < NUM_OF_LANES; i++) {
        for (j = 0; j < LANE_LENGTH; j++) {
            int index = i * LANE_LENGTH + j;

            if (cars[index].speed == 0) {
                printf(".");
            } else {
                printf("=");
            }
        }

        printf("\n");
    }

    printf("\n");
}

void sleep(int delay_in_seconds) {
    time_t start_time, current_time;

    time(&start_time);
    current_time = start_time;

    while (current_time - start_time < delay_in_seconds) {
        time(&current_time);
    }
}