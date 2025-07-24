//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *hello(void *message){
    char *msg = (char *) message;
    printf("%s\n", msg);
    pthread_exit(NULL);
}

int main(){
    pthread_t thread;
    char *message = "Hello, World!";
    
    if (pthread_create(&thread, NULL, hello, (void *) message)){
        fprintf(stderr, "Error creating thread\n");
        exit(1);
    }

    pthread_join(thread, NULL);
    printf("Thread joined.\n");

    return 0;
}