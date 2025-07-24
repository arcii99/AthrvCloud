//FormAI DATASET v1.0 Category: Weather simulation ; Style: distributed
#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_TEMP 100
#define MIN_TEMP -100
#define NUM_STATION 10
#define MAX_NAME_LEN 100
#define SIMULATION_TIME 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct Station {
    char name[MAX_NAME_LEN];
    float temperature;
};

struct ThreadData {
    struct Station *stations;
    int start_index;
    int end_index;
};

void initializeStations(struct Station *stations);
void* updateTemperature(void* t_data);

int main() 
{
    struct Station stations[NUM_STATION];
    initializeStations(stations);

    pthread_t threads[NUM_THREADS];
    int chunk_size = NUM_STATION / NUM_THREADS;
    struct ThreadData thread_data[NUM_THREADS];

    // split stations between threads
    for(int i=0; i<NUM_THREADS; i++) {
        thread_data[i].stations = stations;
        thread_data[i].start_index = i * chunk_size;
        thread_data[i].end_index = (i+1) * chunk_size;
        if(i == NUM_THREADS-1)
            thread_data[i].end_index = NUM_STATION;
        pthread_create(&threads[i], NULL, updateTemperature, &thread_data[i]);
    }

    // wait for all threads to finish
    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print final temperature of each station
    for(int i=0; i<NUM_STATION; i++) {
        printf("Station %d - %s: %f\n", i+1, stations[i].name, stations[i].temperature);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}

void initializeStations(struct Station *stations) {
    char name[MAX_NAME_LEN];
    for(int i=0; i<NUM_STATION; i++) {
        sprintf(name, "Station %d", i+1);
        strcpy(stations[i].name, name);
        stations[i].temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    }
}

void* updateTemperature(void* t_data) {
    struct ThreadData* data = (struct ThreadData*) t_data;
    struct Station *stations = data->stations;
    int start_index = data->start_index;
    int end_index = data->end_index;

    while(1) {
        // sleep for random seconds
        int sleep_seconds = rand() % 5;
        sleep(sleep_seconds);

        // calculate new temperature based on average temperature of nearby stations
        for(int i=start_index; i<end_index; i++) {
            int count = 0;
            float sum = 0;
            for(int j=0; j<NUM_STATION; j++) {
                if(i==j)
                    continue;
                float distance = abs(j-i);
                if(distance <= 2) {
                    sum += stations[j].temperature;
                    count++;
                }
            }
            float avg_temp = sum / count;

            // add random noise to temperature
            float noise = (rand() % 10) - 5;  // noise ranges from -5 to 5
            float new_temp = avg_temp + noise;

            // lock mutex to update station temperature
            pthread_mutex_lock(&mutex);
            stations[i].temperature = new_temp;
            pthread_mutex_unlock(&mutex);
        }

        // check if time limit has exceeded
        time_t current_time = time(NULL);
        if(current_time >= SIMULATION_TIME)
            break;
    }

    pthread_exit(NULL);
}