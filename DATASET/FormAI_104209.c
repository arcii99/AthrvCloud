//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t north_south_sem, east_west_sem;
int north_south_light, east_west_light;

void *north_south_traffic(void *arg){
    while(1){
        sem_wait(&north_south_sem);
        north_south_light = 1;
        east_west_light = 0;
        printf("\nNorth-South Traffic Light is now Green...\n");
        sleep(5);
        north_south_light = 0;
        printf("\nNorth-South Traffic Light is now Red...\n\n");
        sem_post(&east_west_sem);
    }
}

void *east_west_traffic(void *arg){
    while(1){
        sem_wait(&east_west_sem);
        east_west_light = 1;
        north_south_light = 0;
        printf("\nEast-West Traffic Light is now Green...\n");
        sleep(5);
        east_west_light = 0;
        printf("\nEast-West Traffic Light is now Red...\n\n");
        sem_post(&north_south_sem);
    }
}

int main(){
    pthread_t north_south_thread, east_west_thread;

    if(sem_init(&north_south_sem, 0, 1)==-1 || sem_init(&east_west_sem, 0, 0)==-1){
        printf("\nSemaphore initialization failed...\n");
        exit(1);
    }
    printf("\nTraffic Light Controller Program Started...\n");

    if(pthread_create(&north_south_thread, NULL, &north_south_traffic, NULL)!=0 ||pthread_create(&east_west_thread, NULL, &east_west_traffic, NULL)!=0){
        printf("\nThread Creation Failed...\n");
        exit(1);
    }

    while(1){
        printf("--------------------------------------------------\n");
        if(north_south_light)
            printf("North-South Traffic Light is Green\n");
        else
            printf("North-South Traffic Light is Red\n");
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");
        if(east_west_light)
            printf("East-West Traffic Light is Green\n");
        else
            printf("East-West Traffic Light is Red\n");
        printf("--------------------------------------------------\n");
        sleep(2);
        system("clear");
    }
    pthread_join(north_south_thread, NULL);
    pthread_join(east_west_thread, NULL);
    sem_destroy(&north_south_sem);
    sem_destroy(&east_west_sem);
    return 0;
}