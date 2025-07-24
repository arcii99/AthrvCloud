//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t green_light_condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t yellow_light_condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t red_light_condition = PTHREAD_COND_INITIALIZER;

int current_light = GREEN;

/* Function to control the green light */
void *green_light_controller(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (current_light != GREEN) {
            pthread_cond_wait(&green_light_condition, &mutex);
        }
        printf("\nGreen light is on!\n");
        sleep(5);
        current_light = YELLOW;
        pthread_cond_signal(&yellow_light_condition);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

/* Function to control the yellow light */
void *yellow_light_controller(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (current_light != YELLOW) {
            pthread_cond_wait(&yellow_light_condition, &mutex);
        }
        printf("\nYellow light is on!\n");
        sleep(2);
        current_light = RED;
        pthread_cond_signal(&red_light_condition);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

/* Function to control the red light */
void *red_light_controller(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (current_light != RED) {
            pthread_cond_wait(&red_light_condition, &mutex);
        }
        printf("\nRed light is on!\n");
        sleep(3);
        current_light = GREEN;
        pthread_cond_signal(&green_light_condition);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_t green_thread, yellow_thread, red_thread;

    pthread_create(&green_thread, NULL, green_light_controller, NULL);
    pthread_create(&yellow_thread, NULL, yellow_light_controller, NULL);
    pthread_create(&red_thread, NULL, red_light_controller, NULL);

    pthread_join(green_thread, NULL);
    pthread_join(yellow_thread, NULL);
    pthread_join(red_thread, NULL);

    return EXIT_SUCCESS;
}