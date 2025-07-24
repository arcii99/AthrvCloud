//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define TOTAL_SIMULATION_TIME 10   // total time for simulation in seconds
#define TOTAL_BAGGAGE_ITEMS 5      // number of baggage items to be handled
#define TOTAL_THREADS 3            // number of threads to be used (1 conveyor + 2 scanners)

pthread_mutex_t conveyor_mutex;        // mutex for conveyor
pthread_mutex_t scanner1_mutex;        // mutex for scanner 1
pthread_mutex_t scanner2_mutex;        // mutex for scanner 2

int baggage_count = 0;            // count of baggage items successfully scanned
int conveyor_position = 1;        // position of first baggage item on conveyor
int scanner1_position = 1;        // position of first baggage item in scanner 1 queue
int scanner2_position = 1;        // position of first baggage item in scanner 2 queue

// function to sleep for a random amount of time
void wait_random_time(int max_time){
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = (rand() % max_time) * 1000000;   // max_time in milliseconds
    nanosleep(&t, NULL);
}

// function to move conveyor
void move_conveyor(){
    printf("Conveyor is moving...\n");
    wait_random_time(500);
    conveyor_position++;
}

// function for scanner 1
void* scanner1_thread(void* arg){
    while(conveyor_position <= TOTAL_BAGGAGE_ITEMS){  // keep running until all bags are scanned
        if(scanner1_position == conveyor_position){   // check if there is a bag in scanner 1 queue
            printf("Scanner 1 is scanning baggage %d...\n", conveyor_position);
            wait_random_time(1000);
            printf("Baggage %d successfully scanned by Scanner 1!\n", conveyor_position);
            scanner1_position++;
            pthread_mutex_unlock(&scanner1_mutex);     // unlock scanner mutex
            baggage_count++;
        }
    }
    pthread_exit(NULL);
}

// function for scanner 2
void* scanner2_thread(void* arg){
    while(conveyor_position <= TOTAL_BAGGAGE_ITEMS){  // keep running until all bags are scanned
        if(scanner2_position == conveyor_position){   // check if there is a bag in scanner 2 queue
            printf("Scanner 2 is scanning baggage %d...\n", conveyor_position);
            wait_random_time(1000);
            printf("Baggage %d successfully scanned by Scanner 2!\n", conveyor_position);
            scanner2_position++;
            pthread_mutex_unlock(&scanner2_mutex);     // unlock scanner mutex
            baggage_count++;
        }
    }
    pthread_exit(NULL);
}

// function for conveyor manager
void* conveyor_thread(void* arg){
    while(conveyor_position <= TOTAL_BAGGAGE_ITEMS){  // keep running until all bags are on conveyor
        pthread_mutex_lock(&conveyor_mutex);           // lock conveyor mutex
        move_conveyor();                               // move conveyor
        pthread_mutex_unlock(&conveyor_mutex);         // unlock conveyor mutex
        if(conveyor_position <= TOTAL_BAGGAGE_ITEMS){   // check if there is still baggage left to put on conveyor
            if(pthread_mutex_trylock(&scanner1_mutex) == 0){   // try to lock scanner 1 mutex
                printf("Baggage %d put on Scanner 1 queue.\n", conveyor_position);
                scanner1_position = conveyor_position;
            }
            else if(pthread_mutex_trylock(&scanner2_mutex) == 0){   // try to lock scanner 2 mutex
                printf("Baggage %d put on Scanner 2 queue.\n", conveyor_position);
                scanner2_position = conveyor_position;
            }
        }
    }
    pthread_exit(NULL);
}

int main(){
    srand(time(NULL));         // seed random number generator

    pthread_t threads[TOTAL_THREADS];   // array of threads
    int ret;

    pthread_mutex_init(&conveyor_mutex, NULL);   // initialize mutexes
    pthread_mutex_init(&scanner1_mutex, NULL);
    pthread_mutex_init(&scanner2_mutex, NULL);

    // create threads
    ret = pthread_create(&threads[0], NULL, conveyor_thread, NULL);
    if(ret){
        printf("Error creating conveyor thread. Exiting program.\n");
        exit(-1);
    }
    ret = pthread_create(&threads[1], NULL, scanner1_thread, NULL);
    if(ret){
        printf("Error creating scanner 1 thread. Exiting program.\n");
        exit(-1);
    }
    ret = pthread_create(&threads[2], NULL, scanner2_thread, NULL);
    if(ret){
        printf("Error creating scanner 2 thread. Exiting program.\n");
        exit(-1);
    }

    // join threads
    for(int i = 0; i < TOTAL_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    // print results
    printf("\nTotal baggage items scanned: %d\n", baggage_count);

    // destroy mutexes
    pthread_mutex_destroy(&conveyor_mutex);
    pthread_mutex_destroy(&scanner1_mutex);
    pthread_mutex_destroy(&scanner2_mutex);

    pthread_exit(NULL);
}