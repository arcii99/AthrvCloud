//FormAI DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int value = 0;

void *increment(void *arg){
    int i;
    for(i=0; i<5; i++){
        value++;
        printf("Increment thread: value = %d\n", value);
        sleep(1);
    }
    return NULL;
}

void *decrement(void *arg){
    int i;
    for(i=0; i<5; i++){
        value--;
        printf("Decrement thread: value = %d\n", value);
        sleep(1);
    }
    return NULL;
}

int main(){

    pthread_t increment_thread, decrement_thread;
    printf("Initial value: %d\n", value);

    /* create threads */
    pthread_create(&increment_thread, NULL, increment, NULL);
    pthread_create(&decrement_thread, NULL, decrement, NULL);

    /* wait for threads to finish */
    pthread_join(increment_thread, NULL);
    pthread_join(decrement_thread, NULL);

    printf("Final value: %d\n", value);

    return 0;
}