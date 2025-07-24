//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int glob_var = 0;

void* myThreadFunc(void* arg) {
    int loop;
    for(loop=0;loop<5;loop++) {
        glob_var++;
        printf("Thread %ld - Glob_var value: %d\n",pthread_self(), glob_var);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    if(pthread_create(&tid1, NULL, myThreadFunc, NULL) != 0) {
        printf("Thread 1 creation failed\n");
        exit(1);
    }
    printf("Thread %ld created\n", tid1);
    
    if(pthread_create(&tid2, NULL, myThreadFunc, NULL) != 0) {
        printf("Thread 2 creation failed\n");
        exit(1);
    }
    printf("Thread %ld created\n", tid2);
    
    if(pthread_join(tid1, NULL) != 0) {
        printf("Thread 1 join failed\n");
        exit(1);
    }
    if(pthread_join(tid2, NULL) != 0) {
        printf("Thread 2 join failed\n");
        exit(1);
    }
    
    printf("Final Glob_var value: %d\n",glob_var);
    return 0; 
}