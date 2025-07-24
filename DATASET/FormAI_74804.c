//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_SPEED 10
#define MIN_SPEED 1

int speed;
int distance;
int control_signal;

void *speed_control(void *arg){
    while(1){
        if(control_signal == 1){
            if(speed < MAX_SPEED){
                speed++;
            }
        }
        else if(control_signal == -1){
            if(speed > MIN_SPEED){
                speed--;
            }
        }
        printf("Current Speed: %d\n", speed);
        sleep(1);
    }
}

void *distance_control(void *arg){
    while(1){
        distance += speed;
        printf("Current Distance: %d\n", distance);
        sleep(2);
    }
}

int main(){
    pthread_t speed_thread, distance_thread;

    //initialize speed and distance to 0
    speed = 0;
    distance = 0;

    //create threads
    pthread_create(&speed_thread, NULL, speed_control, NULL);
    pthread_create(&distance_thread, NULL, distance_control, NULL);

    //start simulation loop
    printf("Simulation Started.\n");
    while(1){
        printf("Press 1 to speed up, -1 to slow down, or any other key to exit.\n");
        char input = getchar();
        if(input == '1'){
            control_signal = 1;
        }
        else if(input == '-'){
            control_signal = -1;
        }
        else{
            break;
        }
        //clear input buffer
        while(getchar() != '\n');
    }

    //stop threads and cleanup resources
    pthread_cancel(speed_thread);
    pthread_cancel(distance_thread);
    pthread_join(speed_thread, NULL);
    pthread_join(distance_thread, NULL);
    printf("Simulation Stopped.\n");

    return 0;
}