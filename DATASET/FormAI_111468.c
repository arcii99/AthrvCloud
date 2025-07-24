//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_WORK 25

void *do_work(void *arg);

/* The mutex lock */
pthread_mutex_t work_mutex;

/* Global variables */
int work_count = 0;
int left_to_do = MAX_WORK;
int data[MAX_WORK];


int main(int argc, char *argv[])
{
    int i;
    int num_threads;
    int rc;
    pthread_t threads[MAX_THREADS];
    pthread_attr_t attr;

    /* Initialize mutex and condition variable objects */
    pthread_mutex_init(&work_mutex, NULL);

    /* For portability, explicitly create threads in a joinable state */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* Create threads to do the work */
    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], &attr, do_work, (void *)i);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Wait for all threads to complete */
    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("All threads completed the work!\n");

    /* Clean up and exit */
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&work_mutex);
    pthread_exit(NULL);
}

void *do_work(void *arg)
{
    int my_id = (int)arg;
    int my_work = 0;
    int i;
    int my_result = 0;

    printf("Thread %d starting...\n", my_id);

    /* Each thread picks up work to do until there is none left */
    do {
        pthread_mutex_lock(&work_mutex);
        if (left_to_do > 0) {
            /* Take one unit of work */
            left_to_do--;
            my_work = data[work_count];
            work_count++;
            pthread_mutex_unlock(&work_mutex);

            /* Do the work */
            printf("Thread %d doing work with data: %d\n", my_id, my_work);
            for (i = 0; i < my_work; i++) {
                my_result += i;
            }

        } else {
            pthread_mutex_unlock(&work_mutex);
            break;
        }

    } while(1);

    /* Print result */
    printf("Thread %d result: %d\n", my_id, my_result);

    pthread_exit(NULL);
}