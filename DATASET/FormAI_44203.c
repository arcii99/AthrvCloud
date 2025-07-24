//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

#define NUM_TRAVELERS 3
#define NUM_YEARS 100

pthread_barrier_t barrier;

void *time_traveler(void *args){
    int curr_year,rand_year,i;
    long tid;
    tid = (long) args;
    srand(time(NULL) * tid);

    for(i=0;i<NUM_YEARS;i++){
        sleep(1);
        curr_year = 2021 + i;
        rand_year = rand() % NUM_YEARS + 1900;

        printf("Time traveler %ld in year %d is traveling to year %d\n",tid,curr_year,rand_year);

        pthread_barrier_wait(&barrier);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t travelers[NUM_TRAVELERS];
    int i;
    pthread_barrier_init(&barrier,NULL,NUM_TRAVELERS);

    for(i=0;i<NUM_TRAVELERS;i++){
        pthread_create(&travelers[i],NULL,time_traveler,(void *) i);
    }

    for(i=0;i<NUM_TRAVELERS;i++){
        pthread_join(travelers[i],NULL);
    }

    pthread_barrier_destroy(&barrier);

    return 0;
}