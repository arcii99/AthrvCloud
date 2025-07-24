//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BAGGAGE 100
#define MAX_CONVEYOR_SIZE 10

int conveyor[MAX_CONVEYOR_SIZE];
int num_bags_in_conveyor = 0;
int num_bags_so_far = 0;
int num_bags_handled = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
pthread_t conveyor_thread;
pthread_t scanner_thread;
pthread_t loader_thread;

void *conveyor_func(void *arg);
void *scanner_func(void *arg);
void *loader_func(void *arg);
int add_to_conveyor(int item);
int remove_from_conveyor();

int main(){
    int rc, rc1, rc2;

    // Create conveyor_thread
    rc = pthread_create(&conveyor_thread, NULL, conveyor_func, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    // Create scanner_thread
    rc1 = pthread_create(&scanner_thread, NULL, scanner_func, NULL);
    if (rc1) {
        printf("ERROR; return code from pthread_create() is %d\n", rc1);
        exit(-1);
    }

    // Create loader_thread
    rc2 = pthread_create(&loader_thread, NULL, loader_func, NULL);
    if (rc2) {
        printf("ERROR; return code from pthread_create() is %d\n", rc2);
        exit(-1);
    }

    // Wait for threads to join
    pthread_join(conveyor_thread, NULL);
    pthread_join(scanner_thread, NULL);
    pthread_join(loader_thread, NULL);

    // Destroy mutex and conditional variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cv);

    return 0;
}

void *conveyor_func(void *arg) {
    while(1) {
        // Lock mutex before modifying conveyor
        pthread_mutex_lock(&mutex);

        if(num_bags_so_far == MAX_BAGGAGE) {
            printf("All baggage has been added to the conveyor!\n");
            pthread_cond_signal(&cv);
            pthread_mutex_unlock(&mutex);
            break;
        }

        if(num_bags_in_conveyor == MAX_CONVEYOR_SIZE) {
            printf("Conveyor is full. Waiting for scanner to clear items...\n");
            pthread_cond_wait(&cv, &mutex);
        }

        // Add bag to conveyor
        int bag = rand() % 100;
        add_to_conveyor(bag);
        num_bags_in_conveyor++;
        num_bags_so_far++;

        printf("Bag %d added to conveyor\n", bag);

        // Unlock mutex after modifying conveyor
        pthread_mutex_unlock(&mutex);

        // Random sleep time for conveyor to move
        int sleep_time = rand() % 3;
        sleep(sleep_time);
    }
}

void *scanner_func(void *arg) {
    while(1) {
        // Lock mutex before modifying conveyor
        pthread_mutex_lock(&mutex);

        if(num_bags_in_conveyor == 0) {
            printf("No more bags in the conveyor. Waiting for conveyor to add more...\n");
            pthread_cond_wait(&cv, &mutex);
        }

        // Scan each bag in conveyor
        int bag = remove_from_conveyor();
        num_bags_in_conveyor--;

        printf("Bag %d cleared from scanner\n", bag);

        // Random sleep time for scanner to clear item
        int sleep_time = rand() % 2;
        sleep(sleep_time);

        // Signal conveyor_thread to continue adding items
        pthread_cond_signal(&cv);

        // Unlock mutex after modifying conveyor
        pthread_mutex_unlock(&mutex);

        // If all bags have been handled, break loop
        if(num_bags_handled == MAX_BAGGAGE) {
            break;
        }
    }
}

void *loader_func(void *arg) {
    while(1) {
        // Lock mutex before modifying conveyor
        pthread_mutex_lock(&mutex);

        if(num_bags_handled == MAX_BAGGAGE) {
            printf("All bags have been loaded onto plane!\n");
            pthread_cond_signal(&cv);
            pthread_mutex_unlock(&mutex);
            break;
        }

        if(num_bags_in_conveyor > 0) {
            printf("Waiting for scanner to clear items...\n");
            pthread_cond_wait(&cv, &mutex);
        }

        // Load each bag onto plane
        num_bags_handled++;
        printf("Bag %d loaded onto plane\n", num_bags_handled);

        // Random sleep time for loader to load item
        int sleep_time = rand() % 2;
        sleep(sleep_time);

        // Signal scanner_thread to continue scanning items
        pthread_cond_signal(&cv);

        // Unlock mutex after modifying conveyor
        pthread_mutex_unlock(&mutex);

        // Random sleep time for loader to rest
        sleep_time = rand() % 3;
        sleep(sleep_time);
    }
}

int add_to_conveyor(int item)
{
    int i;
    for (i=0; i<MAX_CONVEYOR_SIZE; i++) {
        if (conveyor[i] == -1) {
            conveyor[i] = item;
            return i;
        }
    }
    return -1;
}

int remove_from_conveyor()
{
    if(conveyor[0] == -1) {
        return -1;
    }

    int item = conveyor[0];
    int i;
    for (i=0; i<MAX_CONVEYOR_SIZE-1; i++) {
        conveyor[i] = conveyor[i+1];
    }
    conveyor[i] = -1;

    return item;
}