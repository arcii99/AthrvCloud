//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define TRAFFIC_DENSITY 0.3
#define MAX_SPEED 3
#define MIN_DISTANCE 1

typedef struct Car {
    int pos;
    int speed;
    int size;
    char symbol;
} Car;

void display(Car road[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%c", road[i].symbol);
    }
    printf("\n");
}

void simulate(Car road[], int size) {
    for(int i = size - 1; i >= 1; i--) {
        if(road[i].speed == MAX_SPEED) {
            continue;
        }
        int distance = size;
        for(int j = i + 1; j <= i + road[i].speed; j++) {
            if(j >= size) {
                break;
            }
            if(road[j].symbol != '-') {
                distance = j - i - road[j].size - 1;
                break;
            }
        }
        if(distance > road[i].speed) {
            distance = road[i].speed;
        }
        if(distance < MIN_DISTANCE) {
            road[i].speed = distance - 1;
        } else {
            road[i].speed = MAX_SPEED;
        }
    }
    for(int i = size - 1; i >= 1; i--) {
        road[i].pos = road[i-1].pos;
    }
    for(int i = 1; i < size; i++) {
        if(road[i].speed == 0) {
            continue;
        }
        road[i].pos += road[i].speed;
        if(road[i].pos >= (ROAD_LENGTH)) {
            road[i].pos -= (ROAD_LENGTH);
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < road[i].pos; j++) {
            printf(" ");
        }
        printf("%c", road[i].symbol);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Car road[ROAD_LENGTH];
    int size = ROAD_LENGTH;
    int num_cars = (int)(TRAFFIC_DENSITY * ROAD_LENGTH);
    for(int i = 0; i < size; i++) {
        road[i].symbol = '-';
    }
    for(int i = 0; i < num_cars; i++) {
        int pos = rand() % (size - 2);
        if(road[pos].symbol != '-' || road[pos+1].symbol != '-') {
            i--;
            continue;
        }
        road[pos].symbol = '>';
        road[pos+1].symbol = '<';
        road[pos].size = 1;
        road[pos+1].size = 1;
        road[pos].speed = rand() % (MAX_SPEED+1);
    }
    display(road, size);
    for(int i = 0; i < 20; i++) {
        simulate(road, size);
    }
    return 0;
}