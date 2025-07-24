//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;

int redTimer = 15;
int yellowTimer = 3;
int greenTimer = 15;
int lightIndex = 0;

void *redLight(void *arg){
    while (1){
        pthread_mutex_lock(&mutex);
        printf("Red Light ON\n");
        sleep(redTimer);
        printf("Red Light OFF\n");
        lightIndex = 1;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *yellowLight(void *arg){
    while (1){
        pthread_mutex_lock(&mutex);
        if (lightIndex == 1){
            printf("Yellow Light ON\n");
            sleep(yellowTimer);
            printf("Yellow Light OFF\n");
            lightIndex = 2;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *greenLight(void *arg){
    while (1){
        pthread_mutex_lock(&mutex);
        if (lightIndex == 2){
            printf("Green Light ON\n");
            sleep(greenTimer);
            printf("Green Light OFF\n");
            lightIndex = 0;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);   
    }
}

int main(){
    printf("Starting Traffic Light Control System\n");
    pthread_create(&threads[0], NULL, redLight, NULL);
    pthread_create(&threads[1], NULL, yellowLight, NULL);
    pthread_create(&threads[2], NULL, greenLight, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_mutex_destroy(&mutex);
    printf("Exiting Traffic Light Control System\n");
    return 0;
}