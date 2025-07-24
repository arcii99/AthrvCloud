//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t signal_red, signal_green;

void* red_light(){
    while(1){
        pthread_mutex_lock(&lock);
        pthread_cond_wait(&signal_red, &lock);
        printf("Red Light ON.\n");
        sleep(5);
        printf("Red Light OFF.\n");
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&signal_green);
    }
}

void* green_light(){
    while(1){
        pthread_mutex_lock(&lock);
        pthread_cond_wait(&signal_green, &lock);
        printf("Green Light ON.\n");
        sleep(5);
        printf("Green Light OFF.\n");
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&signal_red);
    }
}

int main(){
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&signal_red, NULL);
    pthread_cond_init(&signal_green, NULL);

    // Start the red light
    pthread_t red;
    if(pthread_create(&red, NULL, red_light, NULL)){
        printf("Error creating Red Thread!");
        return 1;
    }

    // Start the green light
    pthread_t green;
    if(pthread_create(&green, NULL, green_light, NULL)){
        printf("Error creating Green Thread!");
        return 1;
    }

    // Loop indefinitely to toggle lights
    while(1){
        pthread_cond_signal(&signal_red);
        sleep(10);
        pthread_cond_signal(&signal_green);
        sleep(10);
    }
}