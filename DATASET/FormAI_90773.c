//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

// Data Structure Declaration
struct TrafficLight {
    int car_count;      // Number of cars waiting at a traffic light
    int light_state;    // Current state of the traffic light
};

// Function Prototypes
void printTrafficLight(struct TrafficLight*);
void changeState(struct TrafficLight*);
int getRand(int, int);

// Main Function
int main() {
    // Initializing Traffic Lights
    struct TrafficLight t1 = { getRand(0, 10), getRand(0, 2) };
    struct TrafficLight t2 = { getRand(0, 10), getRand(0, 2) };
    struct TrafficLight t3 = { getRand(0, 10), getRand(0, 2) };

    // Simulating Traffic Light Changes
    int TOTAL_ITERATIONS = 20;
    int iteration = 0;
    while(iteration++ < TOTAL_ITERATIONS) {
        // Printing Traffic Light States
        printf("\nTraffic Light 1:");
        printTrafficLight(&t1);
        printf("Traffic Light 2:");
        printTrafficLight(&t2);
        printf("Traffic Light 3:");
        printTrafficLight(&t3);
        printf("\n");

        // Changing Traffic Light States
        changeState(&t1);
        changeState(&t2);
        changeState(&t3);
        
        // Adding Random Number of Cars at Traffic Stop
        t1.car_count += getRand(-2, 2);
        t2.car_count += getRand(-2, 2);
        t3.car_count += getRand(-2, 2);

        // Ensuring Valid Car Count
        t1.car_count = t1.car_count > 0 ? t1.car_count : 0;
        t2.car_count = t2.car_count > 0 ? t2.car_count : 0;
        t3.car_count = t3.car_count > 0 ? t3.car_count : 0;

        // Sleeping for 1 Second
        sleep(1);
    }

    return 0;
}

// Function Definitions
void printTrafficLight(struct TrafficLight* t) {
    switch(t->light_state) {
        case GREEN:
            printf("[GREEN] ");
            break;
        case YELLOW:
            printf("[YELLOW] ");
            break;
        case RED:
            printf("[RED] ");
            break;
    }
    printf("Cars Waiting: %d\n", t->car_count);
}

void changeState(struct TrafficLight* t) {
    if(t->car_count == 0) {         // No Cars Waiting
        t->light_state = GREEN;
    } else if(t->light_state == GREEN) {     // Cars Waiting at Green
        t->light_state = YELLOW;
    } else if(t->light_state == YELLOW) {    // Switching from Yellow to Red
        t->light_state = RED;
        t->car_count = 0;           // Allowing Vehicles to Pass
    } else if(t->light_state == RED) {       // Switching from Red to Green
        t->light_state = GREEN;
    }
}

int getRand(int min, int max) {     // Random Number Generator
    return (rand() % (max - min + 1)) + min;
}