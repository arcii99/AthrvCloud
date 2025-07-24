//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROAD_LENGTH 1000
#define MAX_CARS 50

typedef struct car {
    int position;
    int speed;
} Car;

Car road[MAX_ROAD_LENGTH];
int total_cars = 0;

void move_cars() {
    int i;
    for (i = 0; i < total_cars; i++) {
        int current_pos = road[i].position;
        int speed = road[i].speed;
        int new_pos = current_pos + speed;
        
        if (new_pos > MAX_ROAD_LENGTH) {
            // Car goes off road
            total_cars--;
            continue;
        }
        
        int j;
        for (j = 0; j < total_cars; j++) {
            if (j == i) {
                continue;
            }
            
            int other_pos = road[j].position;
            int dist = other_pos - new_pos;
            if (dist < speed) {
                // Car collides with another car
                speed = dist - 1; // Slow down
                break;
            }
        }
        
        road[i].position = new_pos;
        road[i].speed = speed;
    }
}

void add_car() {
    if (total_cars == MAX_CARS) {
        return;
    }
    
    Car new_car;
    new_car.position = 0;
    new_car.speed = rand() % 10 + 1;
    
    road[total_cars] = new_car;
    total_cars++;
}

void print_road() {
    int i;
    for (i = 0; i < total_cars; i++) {
        printf("%d ", road[i].position);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    while (1) {
        // Add a car with certain probability
        int r = rand() % 100;
        if (r < 10) {
            add_car();
        }
        
        move_cars();
        print_road();
        usleep(500000);
    }
    
    return 0;
}