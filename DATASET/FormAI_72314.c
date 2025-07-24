//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 10

typedef struct
{
    bool is_running;
    int current_state; // 0: RED, 1: GREEN, 2: YELLOW
    pthread_mutex_t mutex;
} TrafficLight;

void* traffic_light_controller(void* arg)
{
    TrafficLight* traffic_light = (TrafficLight*)arg;
    printf("Starting traffic light controller...\n");
    while (traffic_light->is_running)
    {
        pthread_mutex_lock(&(traffic_light->mutex));
        // Turn RED light on for RED_LIGHT_DURATION seconds
        traffic_light->current_state = 0;
        printf("RED light is on for %d seconds...\n", RED_LIGHT_DURATION);
        sleep(RED_LIGHT_DURATION);
        
        // Turn YELLOW light on for YELLOW_LIGHT_DURATION seconds
        traffic_light->current_state = 2;
        printf("YELLOW light is on for %d seconds...\n", YELLOW_LIGHT_DURATION);
        sleep(YELLOW_LIGHT_DURATION);

        // Turn GREEN light on for GREEN_LIGHT_DURATION seconds
        traffic_light->current_state = 1;
        printf("GREEN light is on for %d seconds...\n", GREEN_LIGHT_DURATION);
        sleep(GREEN_LIGHT_DURATION);

        pthread_mutex_unlock(&(traffic_light->mutex));
    }
    printf("Stopping traffic light controller...\n");
    pthread_exit(NULL);
}

int main()
{
    TrafficLight traffic_light = {
        .is_running = true,
        .current_state = 0,
        .mutex = PTHREAD_MUTEX_INITIALIZER
    };
    pthread_t controller_thread;
    pthread_create(&controller_thread, NULL, traffic_light_controller, (void*)&traffic_light);
    printf("Traffic light is ready!\n");
    while (true)
    {
        printf("Current state: ");
        switch (traffic_light.current_state)
        {
            case 0: printf("RED\n"); break;
            case 1: printf("GREEN\n"); break;
            case 2: printf("YELLOW\n"); break;
        }
        sleep(1); // Update every second
    }
    traffic_light.is_running = false;
    pthread_join(controller_thread, NULL);
    return EXIT_SUCCESS;
}