//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int global_sum = 0;

void *incrementSum(void *num){
    int i;
    int value = *((int *)num);
    int local_sum = 0;
    
    for(i = 0; i < value; i++){
        local_sum += i;
    }

    pthread_mutex_lock(&mutex);
    global_sum += local_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(){
    pthread_t thread1, thread2;
    int firstNum = 1000, secondNum = 2000;

    pthread_create(&thread1, NULL, incrementSum, &firstNum);
    pthread_create(&thread2, NULL, incrementSum, &secondNum);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Result: %d\n", global_sum);

    return 0;
}