//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROAD_LENGTH 10
#define MAX_CARS 5
#define CAR_SPEED 2

typedef struct car {
    int position;
    int speed;
} car;

void initialize_cars(car *cars) {
    for(int i=0; i<MAX_CARS; i++) {
        cars[i].position = (i+1)*ROAD_LENGTH/(MAX_CARS+1);
        cars[i].speed = CAR_SPEED;
    }
}

void move_cars(car *cars) {
    for(int i=0; i<MAX_CARS; i++) {
        if(i == 0) {
            cars[i].position += cars[i].speed;
        }
        else {
            if(cars[i].position - cars[i-1].position > ROAD_LENGTH/MAX_CARS) {
                cars[i].position += cars[i].speed;
            }
            else {
                cars[i].speed = cars[i-1].speed;
                cars[i].position = cars[i-1].position + ROAD_LENGTH/MAX_CARS;
            }
        }
    }
}

void print_road(car *cars) {
    printf("|");
    for(int i=0; i<MAX_CARS; i++) {
        for(int j=0; j<ROAD_LENGTH/MAX_CARS; j++) {
            if(cars[i].position == (i+1)*ROAD_LENGTH/(MAX_CARS+1) + j) {
                printf("o");
            }
            else {
                printf(" ");
            }
        }
        printf("|");
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed random number generator
    car cars[MAX_CARS];
    int tick = 0;
    initialize_cars(cars);
    while(1) {
        system("clear"); // use "cls" instead if on Windows
        print_road(cars);
        move_cars(cars);
        tick++;
        if(tick == 100) {
            break;
        }
        usleep(500000); // wait for half a second
    }
    return 0;
}