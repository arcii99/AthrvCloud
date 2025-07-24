//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hello_func(void *arg){
    printf("Hello, world!\n");
    pthread_exit(NULL);
}

void *goodbye_func(void *arg){
    printf("Goodbye, world!\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t hello_thread, goodbye_thread;
    int rc1, rc2;

    rc1 = pthread_create(&hello_thread, NULL, hello_func, NULL);
    if(rc1){
        printf("Error creating hello thread!\n");
        exit(-1);
    }

    rc2 = pthread_create(&goodbye_thread, NULL, goodbye_func, NULL);
    if(rc2){
        printf("Error creating goodbye thread!\n");
        exit(-1);
    }

    pthread_join(hello_thread, NULL);
    pthread_join(goodbye_thread, NULL);

    return 0;
}