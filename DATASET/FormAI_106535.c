//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

typedef struct {
    int id;
    int status; // 0=GREEN, 1=YELLOW, 2=RED
} TrafficLight;

typedef struct {
    TrafficLight lights[3];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Intersection;

void* traffic_light_controller(void* arg) {
    TrafficLight* light = (TrafficLight*)arg;
    int status = GREEN;
    printf("Traffic light %d turned green\n", light->id);
    while (1) {
        sleep(5); // lights stay green for 5 seconds
        status = (status + 1) % 3; // go to next status
        if (status == GREEN) {
            printf("Traffic light %d turned green\n", light->id);
        } else if (status == YELLOW) {
            printf("Traffic light %d turned yellow\n", light->id);
        } else {
            printf("Traffic light %d turned red\n", light->id);
        }
        light->status = status;
    }
}

void* intersection_controller(void* arg) {
    Intersection* intersection = (Intersection*)arg;
    int cars_count = 0;
    while (1) {
        // wait until all lights are green
        pthread_mutex_lock(&intersection->mutex);
        while (intersection->lights[0].status != GREEN ||
               intersection->lights[1].status != GREEN ||
               intersection->lights[2].status != GREEN) {
            pthread_cond_wait(&intersection->cond, &intersection->mutex);
        }
        pthread_mutex_unlock(&intersection->mutex);
        
        // simulate cars passing through intersection
        printf("Cars passing through intersection...\n");
        sleep(2);
        cars_count++;
        printf("Total cars passed: %d\n", cars_count);
        
        // set lights to yellow
        pthread_mutex_lock(&intersection->mutex);
        intersection->lights[0].status = YELLOW;
        intersection->lights[1].status = YELLOW;
        pthread_mutex_unlock(&intersection->mutex);
        printf("Traffic lights turning yellow...\n");
        sleep(2); // lights stay yellow for 2 seconds
        
        // set lights to red
        pthread_mutex_lock(&intersection->mutex);
        intersection->lights[0].status = RED;
        intersection->lights[1].status = RED;
        intersection->lights[2].status = RED;
        pthread_mutex_unlock(&intersection->mutex);
        printf("Traffic lights turning red...\n");
        sleep(5); // lights stay red for 5 seconds
        
        // set lights to green
        pthread_mutex_lock(&intersection->mutex);
        intersection->lights[1].status = GREEN;
        intersection->lights[2].status = GREEN;
        pthread_mutex_unlock(&intersection->mutex);
        printf("Traffic lights turning green...\n");
        pthread_cond_broadcast(&intersection->cond);
    }
}

int main() {
    pthread_t tlc1, tlc2, tlc3, ic;
    Intersection intersection = {
        .lights = {
            { .id = 0, .status = GREEN },
            { .id = 1, .status = YELLOW },
            { .id = 2, .status = RED }
        },
        .mutex = PTHREAD_MUTEX_INITIALIZER,
        .cond = PTHREAD_COND_INITIALIZER
    };
    pthread_create(&tlc1, NULL, traffic_light_controller, &intersection.lights[0]);
    pthread_create(&tlc2, NULL, traffic_light_controller, &intersection.lights[1]);
    pthread_create(&tlc3, NULL, traffic_light_controller, &intersection.lights[2]);
    pthread_create(&ic, NULL, intersection_controller, &intersection);
    pthread_join(tlc1, NULL);
    pthread_join(tlc2, NULL);
    pthread_join(tlc3, NULL);
    pthread_join(ic, NULL);
    return 0;
}