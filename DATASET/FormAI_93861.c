//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

pthread_mutex_t mutex;

int curr_light = RED;
int green_duration = 10;
int yellow_duration = 2;
int red_duration = 10;

void change_light() {
    if(curr_light == RED) {
        printf("From RED to GREEN\n");
        curr_light = GREEN;
    } else if(curr_light == GREEN) {
        printf("From GREEN to YELLOW\n");
        curr_light = YELLOW;
    } else if(curr_light == YELLOW) {
        printf("From YELLOW to RED\n");
        curr_light = RED;
    }
}

void *traffic_light(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        if(curr_light == RED) {
            printf("RED light is on\n");
            sleep(red_duration);
        } else if(curr_light == GREEN) {
            printf("GREEN light is on\n");
            sleep(green_duration);
        } else if(curr_light == YELLOW) {
            printf("YELLOW light is on\n");
            sleep(yellow_duration);
        }
        change_light();
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_mutex_init(&mutex, NULL);

    printf("STARTING TRAFFIC LIGHT CONTROLLER\n");

    if(pthread_create(&tid, NULL, traffic_light, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}