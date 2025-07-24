//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 1000
#define MAX_SPEED 60
#define MIN_SPEED 20

void display_road(int road[ROAD_LENGTH], int current_car_pos) {
    for(int i = 0; i < ROAD_LENGTH; i++){
        if(i == current_car_pos){
            printf("|");
        } else if (road[i] != 0){
            printf("#");
        } else {
            printf("-");
        }
    }

    printf("\n");
}

void accelerate(int road[ROAD_LENGTH], int current_pos, int current_speed) {
    while(current_pos + current_speed < ROAD_LENGTH && !road[current_pos + current_speed]) {
        current_speed++;
    }

    if(current_speed > MAX_SPEED) {
        current_speed = MAX_SPEED;
    }

    road[current_pos] = 0;
    road[current_pos + current_speed] = 1;
    display_road(road, current_pos + current_speed);
    printf("Current speed: %d\n", current_speed);
    printf("\n");

    int distance_to_car_in_front = 0;

    for(int i = current_pos + current_speed + 1; i < ROAD_LENGTH; i++) {
        if(road[i] != 0) {
            distance_to_car_in_front = i - current_pos - current_speed - 1;
            break;
        }
    }

    if(distance_to_car_in_front <= current_speed) {
        current_speed = distance_to_car_in_front - 1;
    }

    if(current_speed < MIN_SPEED) {
        current_speed = MIN_SPEED;
    }

    if(current_pos + current_speed >= ROAD_LENGTH) {
        printf("Car has reached the end of the road.\n");
        exit(0);
    }

    accelerate(road, current_pos + current_speed, current_speed);
}


int main() {
    srand(time(NULL));
    int road[ROAD_LENGTH] = {0};
    int initial_car_position = rand() % 900 + 50;
    road[initial_car_position] = 1;
    display_road(road, initial_car_position);
    printf("\n");

    int current_speed = MIN_SPEED;
    accelerate(road, initial_car_position, current_speed);

    return 0;
}