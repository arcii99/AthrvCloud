//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_OF_LIGHTS 3

typedef enum {RED, YELLOW, GREEN} color_t;
color_t current_color = RED;
pthread_mutex_t color_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t color_change_cond = PTHREAD_COND_INITIALIZER;

void* light_thread(void* arg) {
    color_t light_color = (color_t)arg;
    while(1) {
        pthread_mutex_lock(&color_mutex);
        while(light_color != current_color) {
            pthread_cond_wait(&color_change_cond, &color_mutex);
        }
        printf("Light %d: %s\n", light_color, light_color == RED ? "RED" : light_color == YELLOW ? "YELLOW" : "GREEN");
        sleep(light_color == YELLOW ? 3 : 5);
        current_color = (current_color + 1) % NUM_OF_LIGHTS;
        pthread_cond_broadcast(&color_change_cond);
        pthread_mutex_unlock(&color_mutex);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t light_threads[NUM_OF_LIGHTS];
    for(int i = 0; i < NUM_OF_LIGHTS; i++) {
        pthread_create(&light_threads[i], NULL, light_thread, (void*)i);
    }
    for(int i = 0; i < NUM_OF_LIGHTS; i++) {
        pthread_join(light_threads[i], NULL);
    }
    return EXIT_SUCCESS;
}