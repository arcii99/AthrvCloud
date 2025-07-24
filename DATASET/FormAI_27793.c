//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

enum State {STOP, CAUTION, GO};

typedef struct Traffic_Light {
    enum State currentState;
    int blinkCount;
} TL;

TL trafficLight;

pthread_mutex_t lock;
pthread_cond_t cond;

bool isRunning = true;

void* trafficLightController(void* args) {
    while(isRunning) {
        switch(trafficLight.currentState) {
            case STOP:
                printf("RED Light is ON\n");
                sleep(10);
                trafficLight.currentState = CAUTION;
                break;
            case CAUTION:
                printf("YELLOW Light is ON\n");
                sleep(2);
                trafficLight.currentState = GO;
                break;
            case GO:
                printf("GREEN Light is ON\n");
                sleep(20); 
                trafficLight.currentState = CAUTION;
                break;
        }
    }
    pthread_exit(NULL);
}

void* blinker(void* args) {
    while(trafficLight.blinkCount-- > 0) {
        printf("YELLOW Light is BLINKING\n");
        sleep(1);
    }
    pthread_mutex_lock(&lock);
    trafficLight.currentState = STOP;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    trafficLight.currentState = STOP;
    pthread_t trafficLightControllerThread, blinkerThread;

    while(1) {
        pthread_mutex_lock(&lock);
        int blinks = rand() % 4 + 1;
        trafficLight.blinkCount = blinks;

        if(trafficLight.currentState == CAUTION) {
            pthread_create(&blinkerThread, NULL, blinker, NULL);
        }

        pthread_create(&trafficLightControllerThread, NULL, trafficLightController, NULL);
        pthread_cond_wait(&cond, &lock);
        pthread_cancel(blinkerThread);
        sleep(1);
        pthread_mutex_unlock(&lock);
    }

    isRunning = false;
    pthread_join(trafficLightControllerThread, NULL);
    pthread_join(blinkerThread, NULL);

    return 0;
}