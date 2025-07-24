//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define MAX_REDS 5
#define MAX_GREENS 5
#define MAX_YELLOWS 2

int current_light;

pthread_mutex_t lock;
pthread_cond_t red_cond;
pthread_cond_t yellow_cond;
pthread_cond_t green_cond;

int red_count = 0;
int yellow_count = 0;
int green_count = 0;

void change_light(int light) {
    pthread_mutex_lock(&lock);

    if (current_light == RED) {
        red_count++;
        printf("Red Light [Red Count = %d]\n", red_count);

        if (red_count == MAX_REDS) {
            current_light = GREEN;
            green_count = 0;
            pthread_cond_signal(&green_cond);
        } else {
            pthread_cond_wait(&red_cond, &lock);
        }

    } else if (current_light == YELLOW) {
        yellow_count++;
        printf("Yellow Light [Yellow Count = %d]\n", yellow_count);

        if (yellow_count == MAX_YELLOWS) {
            current_light = RED;
            red_count = 0;
            pthread_cond_signal(&red_cond);
        } else {
            pthread_cond_wait(&yellow_cond, &lock);
        }

    } else if (current_light == GREEN) {
        green_count++;
        printf("Green Light [Green Count = %d]\n", green_count);

        if (green_count == MAX_GREENS) {
            current_light = YELLOW;
            yellow_count = 0;
            pthread_cond_signal(&yellow_cond);
        } else {
            pthread_cond_wait(&green_cond, &lock);
        }

    }

    pthread_mutex_unlock(&lock);
}

void *light_controller(void *arg) {
    while (true) {
        change_light(current_light);
    }
}

int main() {

    current_light = RED;
    pthread_t controller_thread;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&red_cond, NULL);
    pthread_cond_init(&yellow_cond, NULL);
    pthread_cond_init(&green_cond, NULL);

    pthread_create(&controller_thread, NULL, light_controller, NULL);

    pthread_join(controller_thread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&red_cond);
    pthread_cond_destroy(&yellow_cond);
    pthread_cond_destroy(&green_cond);

    return 0;
}