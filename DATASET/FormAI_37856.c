//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LOADERS 5
#define MAX_BELT_SIZE 10
#define MAX_LUGGAGE_COUNT 50

pthread_mutex_t mutex_conveyor = PTHREAD_MUTEX_INITIALIZER; // Mutex for conveyor belt
pthread_mutex_t mutex_loader_count = PTHREAD_MUTEX_INITIALIZER; // Mutex for number of active loaders
pthread_cond_t cv_conveyor_not_full = PTHREAD_COND_INITIALIZER; // Condition variable for conveyor not being full
pthread_cond_t cv_luggage_on_conveyor = PTHREAD_COND_INITIALIZER; // Condition variable for luggage being on the conveyor belt

int conveyor_belt[MAX_BELT_SIZE];
int conveyor_belt_size = 0;
int luggage_count = 0;
int loaders_count = 0;

void *loader_thread(void *arg);
void add_to_conveyor_belt(int luggage);
int remove_from_conveyor_belt();

int main()
{
    int i;
    pthread_t loaders[MAX_LOADERS];

    // Start the loader threads
    for (i = 0; i < MAX_LOADERS; i++)
    {
        if (pthread_create(&loaders[i], NULL, loader_thread, (void *) i))
        {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all the loaders to finish
    for (i = 0; i < MAX_LOADERS; i++)
    {
        if (pthread_join(loaders[i], NULL))
        {
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

// Thread function for loader
void *loader_thread(void *arg)
{
    int id = (int) arg;
    int luggage;

    while (luggage_count < MAX_LUGGAGE_COUNT)
    {
        // Generate a random number between 1-5 for the time it takes to add luggage
        int load_time = rand() % 5 + 1;

        // Sleep for the load time
        sleep(load_time);

        // Generate a random number between 1-10 for the luggage weight
        luggage = rand() % 10 + 1;

        // Attempt to add luggage to the conveyor belt
        pthread_mutex_lock(&mutex_conveyor);
        while (conveyor_belt_size == MAX_BELT_SIZE)
            pthread_cond_wait(&cv_conveyor_not_full, &mutex_conveyor);
        add_to_conveyor_belt(luggage);
        pthread_mutex_unlock(&mutex_conveyor);

        // Signal that there is luggage on the conveyor belt
        pthread_cond_signal(&cv_luggage_on_conveyor);

        // Increment the luggage count
        pthread_mutex_lock(&mutex_loader_count);
        luggage_count++;
        pthread_mutex_unlock(&mutex_loader_count);

        printf("Loader #%d added luggage of weight %d to conveyor belt.\n", id, luggage);
    }

    return NULL;
}

// Function to add luggage to the conveyor belt
void add_to_conveyor_belt(int luggage)
{
    conveyor_belt[conveyor_belt_size++] = luggage;
}

// Function to remove luggage from the conveyor belt
int remove_from_conveyor_belt()
{
    int luggage = conveyor_belt[--conveyor_belt_size];

    // Signal that the conveyor belt is not full
    pthread_cond_signal(&cv_conveyor_not_full);

    return luggage;
}