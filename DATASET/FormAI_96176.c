//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

bool stop = false;
bool slow = false;

void *traffic_controller(void *args){
    while(!stop){
        printf("Green light: Go!\n");
        sleep(10);
        printf("Yellow light: Slow down...\n");
        slow = true;
        sleep(5);
        printf("Red light: Stop!\n");
        sleep(10);
        slow = false;
    }
    printf("Traffic controller is stopping...\n");
    pthread_exit(NULL);
}

void *pedestrian_crossing(void *args){
    while(!stop){
        if(slow){
            printf("Pedestrian crossing: Please cross the road safely.\n");
        }
        sleep(1);
    }
    printf("Pedestrian crossing is stopping...\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t controller;
    pthread_t crossing;
    int rc;

    rc = pthread_create(&controller, NULL, traffic_controller, NULL);
    if(rc){
        printf("Error: Could not create traffic controller thread.\n");
        exit(-1);
    }

    rc = pthread_create(&crossing, NULL, pedestrian_crossing, NULL);
    if(rc){
        printf("Error: Could not create pedestrian crossing thread.\n");
        exit(-1);
    }

    sleep(60);
    stop = true;

    pthread_join(controller, NULL);
    pthread_join(crossing, NULL);

    printf("All threads have stopped. Exiting...\n");
    return 0;
}