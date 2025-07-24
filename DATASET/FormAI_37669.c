//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t lock;
pthread_cond_t cond;
int is_green = 0;
void* pedestrian(void* args){
    printf("Pedestrian is waiting for the green signal...\n");
    pthread_mutex_lock(&lock);
    while(!is_green){
        pthread_cond_wait(&cond, &lock);
    }
    printf("Pedestrian is crossing the road...\n");
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}
int main(){
    pthread_t tid;
    int i = 0;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
    while(i<10){
        printf("Cars are moving...\n");
        if(i==5){
            printf("Red light is on, Cars have to stop...\n");
            sleep(5);
            pthread_mutex_lock(&lock);
            is_green = 1;
            pthread_mutex_unlock(&lock);
            pthread_cond_signal(&cond);
            printf("Green light is on, Cars can move again...\n");
        }
        i++;
        sleep(1);
    }
    pthread_create(&tid, NULL, pedestrian, NULL);
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}