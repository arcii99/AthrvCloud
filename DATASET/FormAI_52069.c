//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int global_variable = 10; //global variable
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //initialize mutex

void* bitwise_operation(void *argument) {
    int num = *(int*)argument;
    pthread_mutex_lock(&mutex); //lock mutex
    global_variable ^= num; //bitwise XOR operation with global variable
    printf("Thread ID %ld: Bitwise XOR operation with %d. Global variable value: %d\n", pthread_self(), num, global_variable);
    pthread_mutex_unlock(&mutex); //unlock mutex
    pthread_exit(NULL);
}

int main() {
    pthread_t tid[5];
    int array[5] = {2, 7, 13, 25, 31};
    for(int i=0; i<5; i++) {
        pthread_create(&tid[i], NULL, &bitwise_operation, (void*)&array[i]);
    }
    for(int i=0; i<5; i++) {
        pthread_join(tid[i], NULL); //wait for all threads to finish
    }
    printf("Final Global Variable Value: %d", global_variable);
    pthread_mutex_destroy(&mutex); //destroy mutex
    return 0;
}