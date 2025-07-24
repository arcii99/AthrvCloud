//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

enum TrafficColor { RED, YELLOW, GREEN } color;
bool allowLeftTurn = false;
bool allowPedestrianCrossing = false;

void* trafficController(void* arg){
    while(true){
        pthread_mutex_lock(&mutex);
        switch(color){
            case RED:
                printf("RED Light. \n");
                allowPedestrianCrossing = true;
                allowLeftTurn = false;
                sleep(10);
                color = GREEN;
                break;

            case YELLOW:
                printf("YELLOW Light. \n");
                allowLeftTurn = true;
                allowPedestrianCrossing = true;
                sleep(2);
                color = RED;
                break;

            case GREEN:
                printf("GREEN Light. \n");
                allowPedestrianCrossing = false;
                allowLeftTurn = true;
                sleep(10);
                color = YELLOW;
                break;
        }
        pthread_mutex_unlock(&mutex);
    }
}

void* pedestrianController(void* arg){
    while(true){
        pthread_mutex_lock(&mutex);
        if(allowPedestrianCrossing){
            printf("Pedestrian can cross the road. \n");
            sleep(5);
        }
        pthread_mutex_unlock(&mutex);
    }
}

void* carController(void* arg){
    while(true){
        pthread_mutex_lock(&mutex);
        if(allowLeftTurn){
            printf("Car is taking a left turn. \n");
            sleep(2);
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    color = RED;
    pthread_t trafficThread, pedestrianThread, carThread;

    pthread_create(&trafficThread, NULL, trafficController, NULL);
    pthread_create(&pedestrianThread, NULL, pedestrianController, NULL);
    pthread_create(&carThread, NULL, carController, NULL);

    pthread_join(trafficThread, NULL);
    pthread_join(pedestrianThread, NULL);
    pthread_join(carThread, NULL);

    return 0;
}