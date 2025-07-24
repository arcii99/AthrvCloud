//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
/* 
 * 'twas the night of the masking ball
 * And all across the code,
 * Threads were starting to spawn,
 * Not a deadlock in the node.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
int count = 0;

void *fair_maiden(void *arg){
    pthread_mutex_lock(&lock);
    printf("Oh fair maiden, what brings you here?\n");
    count++;
    printf("You are visitor number %d\n", count);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *silly_man(void *arg){
    pthread_mutex_lock(&lock);
    printf("Greetings silly man, what brings you here?\n");
    count++;
    printf("You are visitor number %d\n", count);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    pthread_t threads[10];

    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("Mutex init failed\n");
        return 1;
    }

    printf("Welcome to the fair!\n");

    for(int i = 0; i < 5; i++){
        pthread_create(&threads[i], NULL, fair_maiden, NULL);
    }

    for(int i = 5; i < 10; i++){
        pthread_create(&threads[i], NULL, silly_man, NULL);
    }

    for(int i = 0; i < 10; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Thank thee for coming to the fair!\n");
    return 0;
}