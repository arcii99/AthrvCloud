//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defining the different colors of traffic light */
#define RED 0
#define YELLOW 1
#define GREEN 2

/* Defining the time intervals for each color */
#define RED_TIME 30
#define YELLOW_TIME 5
#define GREEN_TIME 40

/* Defining the maximum number of iterations for the simulation */
#define MAX_ITERATIONS 100

/* Defining the structure of the traffic light */
typedef struct TrafficLight{
    int color;  // current color of the traffic light
    int time;   // time remaining for the current color
}TrafficLight;

/* Function to update the traffic light */
void updateTrafficLight(TrafficLight *t){
    switch(t->color){
        case RED:
            t->color = GREEN;
            t->time = GREEN_TIME;
            break;
        case YELLOW:
            t->color = RED;
            t->time = RED_TIME;
            break;
        case GREEN:
            t->color = YELLOW;
            t->time = YELLOW_TIME;
            break;
    }
}

int main(){
    TrafficLight tl;
    tl.color = RED;
    tl.time = RED_TIME;
    int iteration = 0;

    while(iteration < MAX_ITERATIONS){
        printf("Iteration %d - ", iteration);

        switch(tl.color){
            case RED:
                printf("RED\n");
                break;
            case YELLOW:
                printf("YELLOW\n");
                break;
            case GREEN:
                printf("GREEN\n");
                break;
        }

        tl.time--;
        if(tl.time == 0){
            updateTrafficLight(&tl);
        }

        iteration++;
    }

    printf("Simulation complete.\n");

    return 0;
}