//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef enum LightColor {
    RED,
    YELLOW,
    GREEN
} LightColor;

typedef struct TrafficLight {
    LightColor color;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} TrafficLight;

void* trafficLightController(void* arg) {
    TrafficLight* light = (TrafficLight*) arg;

    while (1) {
        // Lock the traffic light
        pthread_mutex_lock(&light->mutex);

        // Wait until signaled to change color
        pthread_cond_wait(&light->cond, &light->mutex);

        // Change the color of the traffic light
        switch (light->color) {
            case RED:
                light->color = GREEN;
                printf("Traffic light changed from RED to GREEN\n");
                break;
            case YELLOW:
                light->color = RED;
                printf("Traffic light changed from YELLOW to RED\n");
                break;
            case GREEN:
                light->color = YELLOW;
                printf("Traffic light changed from GREEN to YELLOW\n");
                break;
        }

        // Unlock the traffic light
        pthread_mutex_unlock(&light->mutex);
    }
}

int main() {
    TrafficLight northSouthLight = {RED, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};
    TrafficLight eastWestLight = {GREEN, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};

    pthread_t northSouthThreadId, eastWestThreadId;
    pthread_create(&northSouthThreadId, NULL, trafficLightController, &northSouthLight);
    pthread_create(&eastWestThreadId, NULL, trafficLightController, &eastWestLight);

    while (1) {
        printf("North-south traffic light is %d\n", northSouthLight.color);
        printf("East-west traffic light is %d\n", eastWestLight.color);

        // Sleep for one second
        sleep(1);

        // Signal the traffic lights to change color
        pthread_cond_signal(&northSouthLight.cond);
        pthread_cond_signal(&eastWestLight.cond);
    }

    return 0;
}