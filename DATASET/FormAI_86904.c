//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

enum SemaphoreType {
    RED,
    YELLOW,
    GREEN
};

enum SemaphoreType semaphore = RED;

void delay(int seconds)
{
    int milliseconds = seconds * 1000;
    usleep(milliseconds * 1000);
}

void* traffic_light_control(void* arg)
{
    int* thread_id = (int*) arg;

    while(1)
    {
        if(semaphore == RED)
        {
            printf("\nTraffic Light Thread %d: RED signal is Active.", *thread_id);
            delay(5);

            pthread_mutex_lock(&mutex);
            semaphore = GREEN;
            pthread_mutex_unlock(&mutex);
        }

        if(semaphore == YELLOW)
        {
            printf("\nTraffic Light Thread %d: YELLOW signal is Active.", *thread_id);
            delay(2);

            pthread_mutex_lock(&mutex);
            semaphore = RED;
            pthread_mutex_unlock(&mutex);
        }

        if(semaphore == GREEN)
        {
            printf("\nTraffic Light Thread %d: GREEN signal is Active.", *thread_id);
            delay(7);

            pthread_mutex_lock(&mutex);
            semaphore = YELLOW;
            pthread_mutex_unlock(&mutex);
        }
    }

    pthread_exit(NULL);
}

int main()
{
    int thread1_id = 1, thread2_id = 2;

    pthread_t thread1, thread2;

    if(pthread_create(&thread1, NULL, traffic_light_control, &thread1_id) != 0)
    {
        printf("\nError: Failed to create Traffic Light Thread 1.");
        return 1;
    }

    if(pthread_create(&thread2, NULL, traffic_light_control, &thread2_id) != 0)
    {
        printf("\nError: Failed to create Traffic Light Thread 2.");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}