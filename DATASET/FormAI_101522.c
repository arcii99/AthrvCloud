//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define DEFAULT_SPEED 50

int current_speed = DEFAULT_SPEED;
int motor_status = 0; // 0 for off, 1 for on
char direction[10]; // direction: FORWARD, BACKWARD, LEFT, RIGHT

void* controller(void* arg){
    while(1){
        printf("Enter command: ");
        char command[20];
        fgets(command, 20, stdin);

        if(strncmp(command, "OFF", 3) == 0){
            motor_status = 0;
            current_speed = 0;
        } else if(strncmp(command, "ON", 2) == 0){
            motor_status = 1;
            current_speed = DEFAULT_SPEED;
        } else if(strncmp(command, "SPEED", 5) == 0){
            int speed = atoi(command+5);
            if(speed <= MAX_SPEED && speed >= MIN_SPEED){
                current_speed = speed;
            } else {
                printf("Invalid speed. Must be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
            }
        } else if(strncmp(command, "FORWARD", 7) == 0){
            strcpy(direction, "FORWARD");
        } else if(strncmp(command, "BACKWARD", 8) == 0){
            strcpy(direction, "BACKWARD");
        } else if(strncmp(command, "LEFT", 4) == 0){
            strcpy(direction, "LEFT");
        } else if(strncmp(command, "RIGHT", 5) == 0){
            strcpy(direction, "RIGHT");
        } else {
            printf("Invalid command.\n");
        }
    }
    return NULL;
}

void* motor(void* arg){
    while(1){
        if(motor_status == 1){
            printf("Motor is ON! Direction: %s, Speed: %d\n", direction, current_speed);
        } else {
            printf("Motor is OFF.\n");
        }
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t controller_thread, motor_thread;

    if(pthread_create(&controller_thread, NULL, controller, NULL)){
        fprintf(stderr, "Error creating controller thread.\n");
        return 1;
    }

    if(pthread_create(&motor_thread, NULL, motor, NULL)){
        fprintf(stderr, "Error creating motor thread.\n");
        return 1;
    }

    if(pthread_join(controller_thread, NULL)){
        fprintf(stderr, "Error joining controller thread.\n");
        return 1;
    }

    if(pthread_join(motor_thread, NULL)){
        fprintf(stderr, "Error joining motor thread.\n");
        return 1;
    }

    return 0;
}