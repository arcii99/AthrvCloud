//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TICKS 100

// Car struct
typedef struct {
    int speed;
    int pos;
} car;

// Traffic struct
typedef struct {
    int length;
    int num_cars;
    car cars[MAX_CARS];
} traffic;

// Function to randomly generate traffic
void generate_traffic(traffic *t, int length) {
    t->length = length;
    t->num_cars = rand() % MAX_CARS;
    for (int i = 0; i < t->num_cars; i++) {
        t->cars[i].speed = rand() % 6 + 1;
        t->cars[i].pos = rand() % (t->length - 1);
    }
}

// Function to print the traffic simulation
void print_traffic(traffic t) {
    printf("Traffic Simulation\n");
    printf("Length: %d\n", t.length);
    printf("Number of Cars: %d\n", t.num_cars);
    printf("Cars: ");
    for (int i = 0; i < t.num_cars; i++) {
        printf("(%d,%d) ", t.cars[i].pos, t.cars[i].speed);
    }
    printf("\n\n");
}

// Function to simulate traffic flow for one tick
void simulate_traffic(traffic *t) {
    for (int i = 0; i < t->num_cars; i++) {
        if (t->cars[i].pos + t->cars[i].speed < t->length) {
            t->cars[i].pos += t->cars[i].speed;
        } else {
            t->cars[i].pos = t->length - 1;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));
    traffic t;
    generate_traffic(&t, 20);
    print_traffic(t);
    for (int i = 0; i < MAX_TICKS; i++) {
        simulate_traffic(&t);
        print_traffic(t);
        printf("Tick %d\n", i + 1);
    }
    return 0;
}