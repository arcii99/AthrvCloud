//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int light_status = 0; //0 for off, 1 for on

pthread_mutex_t mutex_light_status; //Mutex for accessing shared resources

void *light_switch(void *thread_id) {

    long id = (long)thread_id;

    if (id == 0) { //Thread 1 handles turning the light on or off

        while (1) {
            pthread_mutex_lock(&mutex_light_status); //Lock mutex

            if (light_status == 0) {
                printf("Turning light on.\n");
                light_status = 1;
            } else {
                printf("Turning light off.\n");
                light_status = 0;
            }

            pthread_mutex_unlock(&mutex_light_status); //Unlock mutex
            sleep(2); //Delay between light switches
        }

    } else if (id == 1) { //Thread 2 handles displaying the light status

        while (1) {
            pthread_mutex_lock(&mutex_light_status); //Lock mutex

            if (light_status == 0) {
                printf("Light is currently off.\n");
            } else {
                printf("Light is currently on.\n");
            }

            pthread_mutex_unlock(&mutex_light_status); //Unlock mutex
            sleep(1); //Delay between status updates
        }

    }

    pthread_exit(NULL);
}

int main() {

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    //Initialize mutex
    pthread_mutex_init(&mutex_light_status, NULL);

    //Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, light_switch, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    //Join threads
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    //Destroy mutex
    pthread_mutex_destroy(&mutex_light_status);

    return 0;
}