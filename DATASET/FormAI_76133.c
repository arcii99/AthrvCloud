//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void* trafficLight(void*);

pthread_mutex_t controllerLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t redLight = PTHREAD_COND_INITIALIZER;
pthread_cond_t yellowLight = PTHREAD_COND_INITIALIZER;
pthread_cond_t greenLight = PTHREAD_COND_INITIALIZER;
int currentLight = RED;

int main(){
    printf("\nTraffic Control Room Opened\n");
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, trafficLight, NULL);
    pthread_create(&tid2, NULL, trafficLight, NULL);
    pthread_create(&tid3, NULL, trafficLight, NULL);
    pthread_join(tid1, NULL); 
    pthread_join(tid2, NULL); 
    pthread_join(tid3, NULL); 
    printf("\nTraffic Control Room Closed\n");
    return 0;
}

void* trafficLight(void* arg){
    int lightTime;
    pthread_mutex_lock(&controllerLock);
    while(1){
        if(currentLight == RED){
            lightTime = 5;
            printf("\nRed Light is ON");
            pthread_cond_wait(&redLight, &controllerLock);
            printf("\nRed Light is OFF");
        } else if(currentLight == YELLOW){
            lightTime = 2;
            printf("\nYellow Light is ON");
            pthread_cond_wait(&yellowLight, &controllerLock);
            printf("\nYellow Light is OFF");
        } else if(currentLight == GREEN){
            lightTime = 10;
            printf("\nGreen Light is ON");
            pthread_cond_wait(&greenLight, &controllerLock);
            printf("\nGreen Light is OFF");
        }
        pthread_mutex_unlock(&controllerLock);
        sleep(lightTime);
        pthread_mutex_lock(&controllerLock);
        if(currentLight == RED){
            currentLight = GREEN;
            pthread_cond_signal(&greenLight);
        } else if(currentLight == YELLOW){
            currentLight = RED;
            pthread_cond_signal(&redLight);
        } else if(currentLight == GREEN){
            currentLight = YELLOW;
            pthread_cond_signal(&yellowLight);
        }
    }
}