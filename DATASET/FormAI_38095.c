//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define GREEN_TIME 5    //in seconds
#define YELLOW_TIME 2   //in seconds
#define RED_TIME 5      //in seconds

enum light_state {GREEN, YELLOW, RED}; //enum to represent traffic light states

pthread_mutex_t mutex; //mutex to synchronize threads
pthread_cond_t green_light, yellow_light, red_light; //condition variables for specific light states

enum light_state light; //current traffic light state

void *green_thread(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        light = GREEN;
        printf("Green Light ON\n");
        pthread_cond_signal(&green_light); //signal for green light
        pthread_cond_wait(&yellow_light, &mutex); //wait for next light signal
        pthread_mutex_unlock(&mutex);
    }
}

void *yellow_thread(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&green_light, &mutex); //wait for green light signal
        sleep(GREEN_TIME); //for GREEN_TIME seconds
        light = YELLOW;
        printf("Yellow Light ON\n");
        pthread_cond_signal(&yellow_light); //signal for yellow light
        pthread_cond_wait(&red_light, &mutex); //wait for next light signal
        pthread_mutex_unlock(&mutex);
    }
}

void *red_thread(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&yellow_light, &mutex); //wait for yellow light signal
        sleep(YELLOW_TIME); //for YELLOW_TIME seconds
        light = RED;
        printf("Red Light ON\n");
        pthread_cond_signal(&red_light); //signal for red light
        pthread_cond_wait(&green_light, &mutex); //wait for next light signal
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t green, yellow, red;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&green_light, NULL);
    pthread_cond_init(&yellow_light, NULL);
    pthread_cond_init(&red_light, NULL);
    light = RED; //starting with RED light
    pthread_create(&green, NULL, green_thread, NULL);
    pthread_create(&yellow, NULL, yellow_thread, NULL);
    pthread_create(&red, NULL, red_thread, NULL);
    pthread_join(green, NULL);
    pthread_join(yellow, NULL);
    pthread_join(red, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&green_light);
    pthread_cond_destroy(&yellow_light);
    pthread_cond_destroy(&red_light);
    return 0;
}