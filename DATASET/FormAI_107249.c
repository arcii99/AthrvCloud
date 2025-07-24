//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL_SECONDS 3600 // 1 hour simulation
#define MIN_CAR_GAP 2 // minimum gap between cars in seconds
#define MAX_CAR_SPEED 100 // maximum speed of a car in kmph
#define CAR_LENGTH 4 // length of a car in metres
#define DISTANCE_BETWEEN_SENSORS 20 // distance in metres between consecutive sensors
#define DISTANCE_BETWEEN_LIGHTS 50 // distance in metres between consecutive traffic lights
#define LIGHT_GREEN_TIME 30 // time in seconds for green light
#define LIGHT_RED_TIME 20 // time in seconds for red light

struct car { 
    int id; // unique id for each car
    int speed; // car speed in kmph
    float position; // car position in metres from its origin
    float time_since_last_sensor; // time since car passed last sensor
    float time_in_system; // total time car is in the system
};

struct traffic_light { 
    float position; // position of traffic light in metres from its origin
    int state; // 0 for red, 1 for green
    float time_remaining; // time remaining for current state
};

int main() {

    // initialize variables and constants
    srand(time(NULL));
    int car_count = 0;
    float current_time = 0.0;
    struct car cars[1000];
    struct traffic_light lights[10];
    float car_gap;

    // initialize traffic lights
    for(int i=0; i<10; i++) {
        lights[i].position = DISTANCE_BETWEEN_LIGHTS * i;
        lights[i].state = 0;
        lights[i].time_remaining = LIGHT_RED_TIME;
    }

    // simulate traffic flow for 1 hour
    while(current_time < TOTAL_SECONDS) {

        // spawn new car
        if(rand()%10 == 1) {
            car_gap = rand()%(MAX_CAR_SPEED*1000/3600) + MIN_CAR_GAP;
            if((car_count==0) || (cars[car_count-1].position - cars[car_count-1].time_since_last_sensor*MAX_CAR_SPEED*1000/3600 - DISTANCE_BETWEEN_SENSORS > car_gap+CAR_LENGTH)) {
                car_count++;
                cars[car_count-1].id = car_count;
                cars[car_count-1].speed = rand()%MAX_CAR_SPEED + 1;
                cars[car_count-1].position = 0;
                cars[car_count-1].time_since_last_sensor = 0;
                cars[car_count-1].time_in_system = 0;
            }
        }

        // update cars and check if they have passed a sensor
        for(int i=0; i<car_count; i++) {
            cars[i].position += cars[i].speed * (1.0/3600);
            cars[i].time_since_last_sensor += (1.0/3600);
            cars[i].time_in_system += (1.0/3600);

            if(cars[i].position - cars[i].time_since_last_sensor*MAX_CAR_SPEED*1000/3600 >= DISTANCE_BETWEEN_SENSORS) {
                printf("Car %d passed a sensor at time %.2f.\n", cars[i].id, current_time);
                cars[i].time_since_last_sensor = 0;
            }
        }

        // update traffic lights
        for(int i=0; i<10; i++) {
            if(lights[i].state == 0) {
                lights[i].time_remaining -= (1.0/3600);
                if(lights[i].time_remaining <= 0) {
                    lights[i].state = 1;
                    lights[i].time_remaining = LIGHT_GREEN_TIME;
                }
            }
            else {
                lights[i].time_remaining -= (1.0/3600);
                if(lights[i].time_remaining <= 0) {
                    lights[i].state = 0;
                    lights[i].time_remaining = LIGHT_RED_TIME;
                }
            }
        }

        current_time += (1.0/3600);

    }

    // print statistics for cars
    printf("\n");
    for(int i=0; i<car_count; i++) {
        printf("Car %d traveled a distance of %.2f metres in %.2f seconds at an average speed of %.2f kmph and was in the system for %.2f seconds.\n", 
                cars[i].id, cars[i].position, current_time, cars[i].position/current_time*3600/1000, cars[i].time_in_system);
    }

    return 0;
}