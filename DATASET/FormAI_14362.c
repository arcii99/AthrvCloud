//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *green_blink(void *arg);
void *yellow_blink(void *arg);
void *red_blink(void *arg);
void *traffic_controller(void *arg);

pthread_mutex_t lock;
int green_time = 5,yellow_time = 2,red_time = 10;

int main(){

    pthread_t green_thread,yellow_thread,red_thread,controller_thread;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&green_thread,NULL,green_blink,NULL);

    pthread_create(&yellow_thread,NULL,yellow_blink,NULL);

    pthread_create(&red_thread,NULL,red_blink,NULL);

    pthread_create(&controller_thread,NULL,traffic_controller,NULL);

    pthread_join(green_thread,NULL);

    pthread_join(yellow_thread,NULL);

    pthread_join(red_thread,NULL);

    pthread_join(controller_thread,NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}

void *green_blink(void *arg){

    while(1){
        printf("\nGreen Light On\n");
        sleep(green_time);
        printf("\nGreen Light Off\n");
        sleep(green_time);
    }
}

void *yellow_blink(void *arg){

    while(1){
        printf("\nYellow Light On\n");
        sleep(yellow_time);
        printf("\nYellow Light Off\n");
        sleep(yellow_time);
    }
}

void *red_blink(void *arg){

    while(1){
        printf("\nRed Light On\n");
        sleep(red_time);
        printf("\nRed Light Off\n");
        sleep(red_time);
    }
}

void *traffic_controller(void *arg){

    while(1){
        pthread_mutex_lock(&lock);

        printf("\nTraffic Controller:\n");

        printf("\nGreen Light On for 5 seconds\n");

        sleep(green_time);

        printf("\nYellow Light On for 2 seconds\n");

        sleep(yellow_time);

        printf("\nRed Light On for 10 seconds\n");

        sleep(red_time);

        pthread_mutex_unlock(&lock);
    }
}