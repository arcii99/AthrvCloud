//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

static int count = 0;
pthread_mutex_t mtx;

void *parse_c_syntax(void *arg)
{
    pthread_mutex_lock(&mtx);
    int thread_num = *(int*)arg;
    printf("Parsing C syntax in thread %d\n", thread_num);
    count++;
    printf("Number of threads currently parsing C syntax: %d\n", count);
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main()
{
    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&mtx, NULL);

    int thread_args[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++)
    {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, parse_c_syntax, &thread_args[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mtx);
    printf("Parsing complete!\n");
    return 0;
}