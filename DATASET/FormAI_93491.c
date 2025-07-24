//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_BAGS 100
#define NUM_CHECK_IN_DESKS 3
#define NUM_BELTS 2
#define BELT_CAPACITY 5

int bags_to_check_in = NUM_BAGS;
int bags_checked_in = 0;
int bags_to_load[NUM_BELTS] = {0, 0};
int bags_loaded = 0;

pthread_mutex_t check_in_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t check_in_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t load_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t load_cond = PTHREAD_COND_INITIALIZER;

void* check_in_desk(void *arg) {
    int id = *(int*)arg;
    while(bags_to_check_in > 0) {
        pthread_mutex_lock(&check_in_mutex);
        while(bags_checked_in >= BELT_CAPACITY * NUM_BELTS || bags_to_check_in == 0) {
            pthread_cond_wait(&check_in_cond, &check_in_mutex);
        }
        int bags = rand() % 4 + 1;
        if(bags > bags_to_check_in) {
            bags = bags_to_check_in;
        }
        bags_checked_in += bags;
        bags_to_check_in -= bags;
        printf("Check-in desk %d has checked in %d bags, %d bags left to check in.\n", id, bags, bags_to_check_in);
        pthread_cond_signal(&check_in_cond);
        pthread_mutex_unlock(&check_in_mutex);
        usleep(1000000);
    }
    pthread_exit(NULL);
}

void* belt(void *arg) {
    int id = *(int*)arg;
    while(bags_checked_in > 0) {
        pthread_mutex_lock(&load_mutex);
        while(bags_to_load[id] >= BELT_CAPACITY || bags_checked_in == 0) {
            pthread_cond_wait(&load_cond, &load_mutex);
        }
        int bags = rand() % 2 + 1;
        if(bags > bags_checked_in) {
            bags = bags_checked_in;
        }
        bags_to_load[id] += bags;
        bags_checked_in -= bags;
        printf("Belt %d has loaded %d bags, %d bags left to load.\n", id, bags, bags_checked_in);
        pthread_cond_signal(&load_cond);
        pthread_mutex_unlock(&load_mutex);
        usleep(1000000);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_CHECK_IN_DESKS + 2 * NUM_BELTS];
    int check_in_ids[NUM_CHECK_IN_DESKS];
    int belt_ids[NUM_BELTS];
    int load_ids[NUM_BELTS];
    for(int i = 0; i < NUM_CHECK_IN_DESKS; i++) {
        check_in_ids[i] = i;
        pthread_create(&threads[i], NULL, check_in_desk, &check_in_ids[i]);
    }
    for(int i = 0; i < NUM_BELTS; i++) {
        belt_ids[i] = i;
        load_ids[i] = i;
        pthread_create(&threads[NUM_CHECK_IN_DESKS + 2 * i], NULL, belt, &belt_ids[i]);
        pthread_create(&threads[NUM_CHECK_IN_DESKS + 2 * i + 1], NULL, belt, &load_ids[i]);
    }
    for(int i = 0; i < NUM_CHECK_IN_DESKS; i++) {
        pthread_join(threads[i], NULL);
    }
    for(int i = NUM_CHECK_IN_DESKS; i < NUM_CHECK_IN_DESKS + 2 * NUM_BELTS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All bags have been loaded onto the airplane.\n");
    return 0;
}