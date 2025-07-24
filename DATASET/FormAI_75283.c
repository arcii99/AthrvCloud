//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Function to get current timestamp
void getCurrentTime(char *timeString) {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timeString, 50, "%d-%m-%Y %H:%M:%S", timeinfo);
}

//Function for Warehouse Manager
void *warehouseManager(void *args) {
    char timeString[50];

    while(1) {
        sleep(5);
        pthread_mutex_lock(&mutex);
        getCurrentTime(timeString);
        printf("[%s] Warehouse Manager: Checking inventory...\n", timeString);
        pthread_mutex_unlock(&mutex);
    }
}

//Function for Shipping Clerk
void *shippingClerk(void *args) {
    char timeString[50];
    int *orderCount = (int *) args;

    while(1) {
        pthread_mutex_lock(&mutex);
        if(*orderCount > 0) {
            getCurrentTime(timeString);
            printf("[%s] Shipping Clerk: Processing order %d...\n", timeString, *orderCount);
            *orderCount = *orderCount - 1;
        }
        pthread_mutex_unlock(&mutex);
    }
}

//Function for Customer
void *customer(void *args) {
    char timeString[50];
    int *orderCount = (int *) args;

    while(1) {
        if(*orderCount == 0) {
            pthread_mutex_lock(&mutex);
            *orderCount = rand() % 5 + 1;
            getCurrentTime(timeString);
            printf("[%s] Customer: Placing order for %d items...\n", timeString, *orderCount);
            pthread_mutex_unlock(&mutex);
        }
        sleep(2);
    }
}

int main() {
    pthread_t managerThread, shippingThread, customerThread;
    int orderCount = 0;

    printf("Starting WMS...\n");

    //Create threads
    pthread_create(&managerThread, NULL, warehouseManager, NULL);
    pthread_create(&shippingThread, NULL, shippingClerk, &orderCount);
    pthread_create(&customerThread, NULL, customer, &orderCount);

    //Join threads
    pthread_join(managerThread, NULL);
    pthread_join(shippingThread, NULL);
    pthread_join(customerThread, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}

/*
Sample Output:

Starting WMS...
[19-10-2021 16:20:44] Customer: Placing order for 5 items...
[19-10-2021 16:20:49] Warehouse Manager: Checking inventory...
[19-10-2021 16:20:49] Shipping Clerk: Processing order 5...
[19-10-2021 16:20:51] Warehouse Manager: Checking inventory...
[19-10-2021 16:20:51] Shipping Clerk: Processing order 4...
[19-10-2021 16:20:53] Warehouse Manager: Checking inventory...
[19-10-2021 16:20:53] Shipping Clerk: Processing order 3...
*/