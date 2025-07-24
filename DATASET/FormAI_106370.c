//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t lock;  //thread mutex

double current_price = 100.00;  //initial stock price

void *update_stock_price(void *arg) {
    double change_factor;
    while(1) {
        pthread_mutex_lock(&lock);  //lock mutex
        change_factor = (double)rand()/(double)RAND_MAX; //generate a random number between 0 and 1
        if(change_factor >= 0.5) {
            current_price += change_factor*10.0; //increase stock price
        }
        else {
            current_price -= change_factor*10.0;  //decrease stock price
        }
        printf("Current stock price: %.2lf\n", current_price);
        pthread_mutex_unlock(&lock);  //unlock mutex
        sleep(1);  //wait for 1 second
    }
    return NULL;
}

int main() {
    pthread_t thread;
    
    int result = pthread_mutex_init(&lock, NULL); //initialize mutex
    if(result != 0) {
        printf("Mutex initialization failed.\n");
        return EXIT_FAILURE;
    }
    
    result = pthread_create(&thread, NULL, update_stock_price, NULL); //create a thread
    if(result != 0) {
        printf("Thread creation failed.\n");
        return EXIT_FAILURE;
    }
    
    printf("Stock market tracker started.\n");
    
    while(1) {
        pthread_mutex_lock(&lock); //lock mutex
        printf("Current stock price: %.2lf\n", current_price); //print current stock price
        pthread_mutex_unlock(&lock); //unlock mutex
        sleep(1); //wait for 1 second
    }
    
    pthread_join(thread, NULL); //wait for thread to finish
    pthread_mutex_destroy(&lock); //destroy mutex
    
    printf("Stock market tracker stopped.\n");
    
    return EXIT_SUCCESS;
}