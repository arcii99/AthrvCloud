//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s1, s2; //semaphores to control the light switch and light bulb respectively
int switch_state = 0; //0 means light switch off, 1 means light switch on
int bulb_state = 0; //0 means bulb off, 1 means bulb on

void* switch_thread(void* arg) {
    while(1) {
        sem_wait(&s1); //wait for light switch semaphore to be available
        if(switch_state == 0) { //if light switch is off
            printf("Light switch turned on.\n");
            switch_state = 1; //turn on light switch
            sem_post(&s2); //signal light bulb semaphore to turn on bulb
        } else { //if light switch is on
            printf("Light switch turned off.\n");
            switch_state = 0; //turn off light switch
            sem_post(&s2); //signal light bulb semaphore to turn off bulb
        }
    }
    return NULL;
}

void* bulb_thread(void* arg) {
    while(1) {
        sem_wait(&s2); //wait for light bulb semaphore to be available
        if(bulb_state == 0 && switch_state == 1) { //if bulb is off and switch is on
            printf("Light bulb turned on.\n");
            bulb_state = 1; //turn on bulb
        } else if(bulb_state == 1 && switch_state == 0) { //if bulb is on and switch is off
            printf("Light bulb turned off.\n");
            bulb_state = 0; //turn off bulb
        }
        sem_post(&s1); //signal light switch semaphore to allow next switch change
    }
    return NULL;
}

int main() {
    pthread_t switch_tid, bulb_tid;

    sem_init(&s1, 0, 1); //initialize light switch semaphore to available
    sem_init(&s2, 0, 0); //initialize light bulb semaphore to unavailable

    pthread_create(&switch_tid, NULL, switch_thread, NULL);
    pthread_create(&bulb_tid, NULL, bulb_thread, NULL);

    pthread_join(switch_tid, NULL); //wait for threads to finish (will never happen)
    pthread_join(bulb_tid, NULL);

    sem_destroy(&s1); //destroy semaphores
    sem_destroy(&s2);

    return 0;
}