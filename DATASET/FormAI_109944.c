//FormAI DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4   // define the number of threads to be used
#define SIM_TIME 60     // define the simulation time in seconds
#define MAX_TEMP 100    // define the maximum temperature
#define MIN_TEMP 0      // define the minimum temperature

// global variables
int current_temp = 0;
pthread_mutex_t temp_mutex;

/**
 * Function to simulate the temperature change
 * @param void* arg: thread argument
 */
void *simulate_temperature(void *arg) {
    int id = *((int*)(&arg));    // thread id
    int change;                  // temperature change value

    // loop for the simulation time
    for(int i=0; i<SIM_TIME; i++) {
        change = (rand()%21) - 10;  // generate a temperature change between -10 and 10 degrees
        pthread_mutex_lock(&temp_mutex);    // lock the temperature mutex
        current_temp += change;             // update the current temperature
        pthread_mutex_unlock(&temp_mutex);  // unlock the temperature mutex
        printf("Thread %d: Temperature changed by %d degrees\n", id, change);
        sleep(1);   // sleep for 1 second
    }

    // exit the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];     // thread array
    int thread_id[NUM_THREADS];         // thread id array

    // initialize the temperature mutex
    pthread_mutex_init(&temp_mutex, NULL);

    // create the threads
    for(int i=0; i<NUM_THREADS; i++) {
        thread_id[i] = i+1;
        pthread_create(&threads[i], NULL, simulate_temperature, (void*)thread_id[i]);
    }

    // join the threads
    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // destroy the temperature mutex
    pthread_mutex_destroy(&temp_mutex);

    // print the final temperature
    printf("The final temperature is: %d\n", current_temp);

    // exit the program
    return 0;
}