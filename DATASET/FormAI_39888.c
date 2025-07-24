//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define LANE_LENGTH 100

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction_t;

typedef struct {
    int position;
    direction_t direction;
} car_t;

void print_lane(int lane[]) {
    for(int i = 0; i < LANE_LENGTH; i++) {
        if(lane[i] == 0) {
            printf("-");
        } else {
            printf("%d", lane[i]);
        }
    }
    printf("\n");
}

int main() {
    int north_lane[LANE_LENGTH] = {0};
    int east_lane[LANE_LENGTH] = {0};
    int south_lane[LANE_LENGTH] = {0};
    int west_lane[LANE_LENGTH] = {0};

    car_t cars[MAX_CARS];

    int car_count = 0;

    srand(time(NULL));

    for(int i = 0; i < 100; i++) {
        if(rand()%3 == 0) {
            int lane = rand()%4;
            if(car_count >= MAX_CARS) {
                printf("Lane %d is full\n", lane);
            } else {
                car_t new_car = {0, (direction_t) lane};
                switch(lane) {
                    case NORTH:
                        north_lane[0] = 1;
                        break;
                    case EAST:
                        east_lane[0] = 1;
                        break;
                    case SOUTH:
                        south_lane[0] = 1;
                        break;
                    case WEST:
                        west_lane[0] = 1;
                        break;
                    default:
                        printf("Invalid lane\n");
                        exit(EXIT_FAILURE);
                }
                cars[car_count] = new_car;
                car_count++;
            }
        }

        for(int j = 0; j < car_count; j++) {
            if(cars[j].position == LANE_LENGTH - 1) {
                switch(cars[j].direction) {
                    case NORTH:
                        north_lane[LANE_LENGTH-1] = 0;
                        break;
                    case EAST:
                        east_lane[LANE_LENGTH-1] = 0;
                        break;
                    case SOUTH:
                        south_lane[LANE_LENGTH-1] = 0;
                        break;
                    case WEST:
                        west_lane[LANE_LENGTH-1] = 0;
                        break;
                    default:
                        printf("Invalid lane\n");
                        exit(EXIT_FAILURE);
                }
                cars[j] = cars[car_count-1];
                car_count--;
                j--;
            } else {
                switch(cars[j].direction) {
                    case NORTH:
                        north_lane[cars[j].position] = 0;
                        cars[j].position++;
                        north_lane[cars[j].position] = j+1;
                        break;
                    case EAST:
                        east_lane[cars[j].position] = 0;
                        cars[j].position++;
                        east_lane[cars[j].position] = j+1;
                        break;
                    case SOUTH:
                        south_lane[cars[j].position] = 0;
                        cars[j].position++;
                        south_lane[cars[j].position] = j+1;
                        break;
                    case WEST:
                        west_lane[cars[j].position] = 0;
                        cars[j].position++;
                        west_lane[cars[j].position] = j+1;
                        break;
                    default:
                        printf("Invalid lane\n");
                        exit(EXIT_FAILURE);
                }
            }
        }

        printf("====================\n");
        printf("North lane:\n");
        print_lane(north_lane);
        printf("East lane:\n");
        print_lane(east_lane);
        printf("South lane:\n");
        print_lane(south_lane);
        printf("West lane:\n");
        print_lane(west_lane);
    }

    return 0;
}