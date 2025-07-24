//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
  
int total_cost = 0;  
pthread_mutex_t lock;

void *place_order(void *arg) {
    int *cost = (int *)arg;
    pthread_mutex_lock(&lock);
    total_cost += *cost;
    pthread_mutex_unlock(&lock);  
}

int main() {  
    pthread_t thread_1, thread_2, thread_3;  
    int cost_1 = 30, cost_2 = 20, cost_3 = 35;  
  
    pthread_mutex_init(&lock, NULL);
    
    pthread_create(&thread_1, NULL, place_order, &cost_1);  
    pthread_create(&thread_2, NULL, place_order, &cost_2);  
    pthread_create(&thread_3, NULL, place_order, &cost_3);  
  
    pthread_join(thread_1, NULL);  
    pthread_join(thread_2, NULL);  
    pthread_join(thread_3, NULL);  
  
    printf("Total cost is %d\n", total_cost);  
    
    pthread_mutex_destroy(&lock);

    return 0;  
}