//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LUGGAGE 10
#define MAX_CUSTOMERS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t vacant = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;

int luggage_queue[MAX_LUGGAGE];
int queue_length = 0;

int current_customer = 0;
int customers_left = MAX_CUSTOMERS;

void *customer(void *arg){
    pthread_mutex_lock(&mutex);
    while(current_customer != (int) arg){
        pthread_cond_wait(&vacant, &mutex);
    }

    int num_luggage = (*(int*) arg) % 4 + 1;
    int i;
    printf("Customer %d has %d pieces of luggage:\n", current_customer + 1, num_luggage);
    for(i = 0; i < num_luggage; i++){
        while(queue_length == MAX_LUGGAGE){
            pthread_cond_wait(&full, &mutex);
        }

        luggage_queue[queue_length] = (*(int*) arg) * num_luggage + i + 1;
        queue_length++;
        printf("Luggage %d added to queue.\n", luggage_queue[queue_length-1]);

        pthread_cond_signal(&vacant);
    }

    current_customer++;
    customers_left--;
    printf("Customer %d has completed the baggage handling process.\n", current_customer);
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void *handler(void *arg){
    pthread_mutex_lock(&mutex);
    while(customers_left > 0 || queue_length > 0){
        while(queue_length == 0){
            pthread_cond_wait(&vacant, &mutex);
        }

        int item = luggage_queue[0];
        int i;
        printf("Handler is processing Luggage %d\n", item);
        for(i = 0; i < queue_length - 1; i++){
            luggage_queue[i] = luggage_queue[i+1];
        }
        queue_length--;

        pthread_cond_signal(&full);
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(){
    pthread_t customers[MAX_CUSTOMERS], handler_thread;
    int customer_ids[MAX_CUSTOMERS], i;

    for(i = 0; i < MAX_CUSTOMERS; i++){
        customer_ids[i] = i;
        pthread_create(&customers[i], NULL, customer, (void*) &customer_ids[i]);
    }
    pthread_create(&handler_thread, NULL, handler, NULL);

    for(i = 0; i < MAX_CUSTOMERS; i++){
        pthread_join(customers[i], NULL);
    }
    pthread_join(handler_thread, NULL);

    return 0;
}