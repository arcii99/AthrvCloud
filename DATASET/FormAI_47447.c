//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_msg(void*);

int main(){
    pthread_t threads[5];
    char *msg[5] = {"Hello", "from", "the", "threading", "library!"};
    int i;
    for(i=0;i<5;i++){
        pthread_create(&threads[i], NULL, print_msg, (void*)msg[i]);
    }
    for(i=4;i>=0;i--){
        pthread_join(threads[i], NULL);
    }
    printf("\n");
    return 0;
}

void *print_msg(void *arg){
    char *msg = (char*)arg;
    printf("%s ", msg);
    pthread_exit(NULL);
}