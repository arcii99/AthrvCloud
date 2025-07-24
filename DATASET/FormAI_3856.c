//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile int global_sum = 0; // global variable to hold the bitwise OR result
pthread_mutex_t mutex_sum = PTHREAD_MUTEX_INITIALIZER; // mutex for the global_sum variable

void *bitwise_lr(void *ptr)
{
    int num = *(int *)ptr;
    
    for(int i = 1; i <= num; i++)
    {
        pthread_mutex_lock(&mutex_sum);
        global_sum |= i;
        pthread_mutex_unlock(&mutex_sum);
    }

    pthread_exit(NULL);
}

void *bitwise_rl(void *ptr)
{
    int num = *(int *)ptr;
    
    for(int i = num; i > 0; i--)
    {
        pthread_mutex_lock(&mutex_sum);
        global_sum |= i;
        pthread_mutex_unlock(&mutex_sum);
    }

    pthread_exit(NULL);
}

int main()
{
    int num1 = 20;
    int num2 = 30;
    
    pthread_t lr_thread, rl_thread;

    // create threads for bitwise LR and bitwise RL operations
    pthread_create(&lr_thread, NULL, bitwise_lr, &num1);
    pthread_create(&rl_thread, NULL, bitwise_rl, &num2);

    // wait for thread termination
    pthread_join(lr_thread, NULL);
    pthread_join(rl_thread, NULL);

    printf("Bitwise OR result: %d\n", global_sum);

    return 0;
}