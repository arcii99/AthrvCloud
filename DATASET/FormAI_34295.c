//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int currentSignal = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;
int timer = 0;

void* trafficController(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(timer > 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        if(currentSignal == RED) {
            currentSignal = GREEN;
            timer = 20;
            printf("\nGREEN LIGHT ON\n");
        }
        else if(currentSignal == GREEN) {
            currentSignal = YELLOW;
            timer = 5;
            printf("\nYELLOW LIGHT ON\n");
        }
        else {
            currentSignal = RED;
            timer = 15;
            printf("\nRED LIGHT ON\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* timerTick(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        if(timer > 0) {
            timer--;
        }
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main() {
    pthread_t trafficThread, timerThread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&trafficThread, NULL, trafficController, NULL);
    pthread_create(&timerThread, NULL, timerTick, NULL);
    pthread_join(trafficThread, NULL);
    return 0;
}