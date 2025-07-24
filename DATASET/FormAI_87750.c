//FormAI DATASET v1.0 Category: Smart home light control ; Style: distributed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ROOMS 5

// Room light state
bool roomLightState[NUM_ROOMS] = {false, false, false, false, false};

// Mutex for accessing roomLightState array
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to switch light on and off in a room
void* switchLight(void* roomNumber)
{
    int room = *(int*) roomNumber;

    while(true)
    {
        // Sleep for random time between 1 to 5 seconds
        int sleepTime = rand() % 5 + 1;
        sleep(sleepTime);

        // Lock mutex before accessing roomLightState array
        pthread_mutex_lock(&mutex);

        // Toggle light state
        roomLightState[room] = !roomLightState[room];

        // Print state of room light
        printf("Light in room %d is %s\n", room+1, roomLightState[room] ? "on" : "off");

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }
}

// Main function
int main()
{
    pthread_t threadIDs[NUM_ROOMS];

    // Create threads for each room
    for(int i = 0; i < NUM_ROOMS; i++)
        pthread_create(&threadIDs[i], NULL, switchLight, &i);

    // Wait for all threads to complete
    for(int i = 0; i < NUM_ROOMS; i++)
        pthread_join(threadIDs[i], NULL);

    return 0;
}