//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4
#define MAX_LIGHTS 10

int light_state[MAX_LIGHTS] = {0}; // 0 is off, 1 is on

void* update_light_state(void* args)
{
    int light_id = *(int*) args;
    
    while(1)
    {
        printf("Light %d is currently %s\n", light_id, light_state[light_id] == 0 ? "off" : "on");
        
        int new_state = rand() % 2;
        light_state[light_id] = new_state;

        printf("Light %d has been turned %s\n", light_id, new_state == 0 ? "off" : "on");

        sleep(1);
    }
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    srand(time(NULL));

    for(int i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i % MAX_LIGHTS;

        if(pthread_create(&threads[i], NULL, update_light_state, &thread_args[i]))
        {
            perror("Error creating thread");
            return 1;
        }
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}