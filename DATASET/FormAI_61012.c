//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int total_weight = 0;
int num_bags = 0;

void *scanner(void *arg){
    int *bag_weight = (int*)arg;
    pthread_mutex_lock(&mutex);
    while(total_weight + *bag_weight > 100){
        printf("Scanner: Baggage weight exceeds limit. Waiting...\n");
        pthread_cond_wait(&condition, &mutex);
    }
    num_bags++;
    total_weight += *bag_weight;
    printf("Scanner: Accepted Baggage. Total weight now: %d\n", total_weight);
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

void *conveyor_belt(void *arg){
    int *bag_weight = (int*)arg;
    sleep(1);
    printf("Conveyor Belt: Received Baggage. Weight: %d\n", *bag_weight);
    pthread_cond_signal(&condition);
    pthread_exit(0);
}

int main(){
    int bag_weights[] = {50, 20, 15, 30, 10};
    int num_bags = sizeof(bag_weights)/sizeof(bag_weights[0]);
    pthread_t scanner_threads[num_bags], conveyor_thread[num_bags];
    int i;
    for(i=0; i<num_bags; i++){
        pthread_create(&conveyor_thread[i], NULL, conveyor_belt, &bag_weights[i]);
        pthread_create(&scanner_threads[i], NULL, scanner, &bag_weights[i]);
    }
    for(i=0; i<num_bags; i++){
        pthread_join(conveyor_thread[i], NULL);
        pthread_join(scanner_threads[i], NULL);
    }
    printf("All bags have been processed. Total bags: %d, Total weight: %d\n", num_bags, total_weight);
    return 0;
}