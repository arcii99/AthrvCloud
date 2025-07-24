//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 5
#define MAX_CARS 100

typedef struct Car {
    int id;
    int speed;
    int position;
    int road_id;
} Car;

typedef struct Road {
    int id;
    int length;
    int max_speed;
    Car cars_on_road[MAX_CARS];
    int num_cars_on_road;
} Road;

Road roads[MAX_ROADS];
int num_roads = 0;

void init_road(int id, int length, int max_speed) {
    Road road;
    road.id = id;
    road.length = length;
    road.max_speed = max_speed;
    road.num_cars_on_road = 0;
    roads[num_roads++] = road;
}

void add_car_on_road(int road_id, int speed, int position) {
    Road *road = &roads[road_id];
    Car car;
    car.id = road->num_cars_on_road;
    car.speed = speed;
    car.position = position;
    car.road_id = road_id;
    road->cars_on_road[road->num_cars_on_road++] = car;
}

int get_distance_to_closest_car(int road_id, int position, int speed) {
    Road *road = &roads[road_id];
    int min_distance = road->length;
    for(int i = 0; i < road->num_cars_on_road; i++) {
        Car c = road->cars_on_road[i];
        int distance = c.position - position;
        if(c.position < position) distance += road->length;
        if(distance < min_distance) {
            min_distance = distance;
            int time_to_reach_car = distance / speed;
            if(time_to_reach_car == 0) return -1;
        }
    }
    return min_distance;
}

void move_car(Car *car, int distance) {
    car->position += distance;
}

void simulate_traffic(int num_iterations) {
    for(int i = 0; i < num_iterations; i++) {
        for(int j = 0; j < num_roads; j++) {
            Road *road = &roads[j];
            for(int k = 0; k < road->num_cars_on_road; k++) {
                Car *car = &road->cars_on_road[k];
                int d = get_distance_to_closest_car(road->id, car->position, car->speed);
                if(d != -1 && d <= car->speed) {
                    move_car(car, d);
                } else {
                    move_car(car, car->speed);
                }
            }
        }
    }
}

void print_traffic() {
    for(int i = 0; i < num_roads; i++) {
        Road *road = &roads[i];
        printf("Road %d:\n", road->id);
        for(int j = 0; j < road->num_cars_on_road; j++) {
            Car car = road->cars_on_road[j];
            printf("Car %d on position %d\n", car.id, car.position);
        }
    }
}

int main() {
    srand(time(NULL));
    init_road(0, 100, 10);
    init_road(1, 200, 15);
    
    for(int i = 0; i < 30; i++) {
        add_car_on_road(0, 5 + rand() % 6, rand() % 100);
    }
    
    for(int i = 0; i < 50; i++) {
        add_car_on_road(1, 8 + rand() % 8, rand() % 200);
    }
    
    simulate_traffic(10);
    print_traffic();
    
    return 0;
}