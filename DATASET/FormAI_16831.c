//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 50

typedef struct Road {
    int id;
    int length;
    int speed_limit;
    int traffic_jam;
    int cars_count;
    int cars[MAX_CARS];
} Road;

Road roads[MAX_ROADS];
int cars_on_road[MAX_ROADS][MAX_CARS];

void init_roads() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i].id = i;
        roads[i].length = rand() % 100 + 10;
        roads[i].speed_limit = rand() % 50 + 10;
        roads[i].traffic_jam = 0;
        roads[i].cars_count = 0;
        for (int j = 0; j < MAX_CARS; j++) {
            cars_on_road[i][j] = -1;
        }
    }
}

void print_roads() {
    printf("Roads:\n");
    for (int i = 0; i < MAX_ROADS; i++) {
        printf("Road %d: length=%d, speed_limit=%d, traffic_jam=%d, cars_count=%d\n",
               roads[i].id, roads[i].length, roads[i].speed_limit, roads[i].traffic_jam, roads[i].cars_count);
        printf("Cars on road %d: [", i);
        for (int j = 0; j < roads[i].cars_count; j++) {
            printf(" %d", cars_on_road[i][j]);
        }
        printf(" ]\n");
    }
}

void update_traffic_jam() {
    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i].traffic_jam = 0;
        for (int j = 0; j < roads[i].cars_count; j++) {
            int k = cars_on_road[i][j];
            int car_speed = roads[i].speed_limit;
            if (k > 0 && roads[i].cars[k-1] < roads[i].length) {
                int distance_to_car_in_front = roads[i].cars[k-1] - k;
                if (distance_to_car_in_front < car_speed) {
                    car_speed = distance_to_car_in_front;
                }
            }
            roads[i].cars[k] += car_speed;
            if (roads[i].cars[k] >= roads[i].length) {
                roads[i].cars[k] = -1;
                cars_on_road[i][j] = -1;
                roads[i].cars_count--;
            }
            if (car_speed < roads[i].speed_limit) {
                roads[i].traffic_jam = 1;
            }
        }
    }
}

int main() {
    init_roads();
    print_roads();
    while (1) {
        update_traffic_jam();
        print_roads();
        sleep(1);
    }
    return 0;
}