//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100

typedef struct {
    int road_id;
    int pos;
    int speed;
} car;

typedef struct {
    int id;
    int speed_limit;
    int length;
    int num_cars;
    car cars[MAX_CARS];
} road;

int num_roads = 0;
road roads[MAX_ROADS];

void init_roads() {
    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i].id = i+1;
        roads[i].speed_limit = 30 + rand() % 70;
        roads[i].length = 100 + rand() % 1000;
        roads[i].num_cars = 0;
    }
    num_roads = MAX_ROADS;
}

void init_cars() {
    for (int i = 0; i < MAX_CARS; i++) {
        int rand_road = rand() % num_roads;
        if (roads[rand_road].num_cars < MAX_CARS) {
            car new_car;
            new_car.road_id = rand_road+1;
            new_car.pos = 0;
            new_car.speed = 10 + rand() % roads[rand_road].speed_limit;
            roads[rand_road].cars[roads[rand_road].num_cars] = new_car;
            roads[rand_road].num_cars++;
        }
    }
}

void update_car_position(car *car) {
    int road_speed_limit = roads[car->road_id-1].speed_limit;
    int max_speed = (car->speed < road_speed_limit) ? car->speed : road_speed_limit;
    car->pos += max_speed;
}

void update_road_positions(road *road) {
    for (int i = 0; i < road->num_cars; i++) {
        car *car = &road->cars[i];
        update_car_position(car);
    }
}

void update_traffic() {
    for (int i = 0; i < num_roads; i++) {
        update_road_positions(&roads[i]);
    }
}

void print_roads() {
    for (int i = 0; i < num_roads; i++) {
        printf("Road %d (Speed limit: %d, Length: %d, Number of cars: %d)\n",
                roads[i].id, roads[i].speed_limit, roads[i].length, roads[i].num_cars);
        for (int j = 0; j < roads[i].num_cars; j++) {
            printf("  Car %d (Position: %d, Speed: %d)\n",
                    j+1, roads[i].cars[j].pos, roads[i].cars[j].speed);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_roads();
    init_cars();

    while (1) {
        update_traffic();
        print_roads();
        printf("Press any key to continue...");
        getchar();
        printf("\n\n");
    }

    return 0;
}