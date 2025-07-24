//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

void* printEven(void* arg)
{
    int i;
    for(i=0; i<=10; i+=2)
    {
        pthread_mutex_lock( &mutex1 );
        printf("%d ", i);
        pthread_cond_signal( &cond1 );
        pthread_mutex_unlock( &mutex1 );
    }
}

void* printOdd(void* arg)
{
    int i;
    for(i=1; i<=10; i+=2)
    {
        pthread_mutex_lock( &mutex1 );
        pthread_cond_wait( &cond1, &mutex1 );
        printf("%d ", i);
        pthread_mutex_unlock( &mutex1 );
    }
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create( &thread1, NULL, &printEven, NULL);
    pthread_create( &thread2, NULL, &printOdd, NULL);

    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);

    return 0;
}