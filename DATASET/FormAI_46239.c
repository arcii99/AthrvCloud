//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// defining global variables
int inventory[5] = {10, 20, 30, 40, 50};
int orders[5];
int total_sales = 0;

pthread_mutex_t mutex;

// function to calculate total sales
void calculateTotalSales() 
{
    int i;
    for (i = 0; i < 5; i++) 
    {
        total_sales += orders[i] * i;
    }
}

// function to execute the pharmacist thread
void* pharmacistFunc(void* arg) 
{
    int i;
    for (i = 0; i < 5; i++) 
    {
        pthread_mutex_lock(&mutex);

        if (inventory[i] < 10) 
        {
            inventory[i] += 50;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// function to execute the customer thread
void* customerFunc(void* arg) 
{
    int i;
    for (i = 0; i < 5; i++) 
    {
        pthread_mutex_lock(&mutex);

        if (inventory[i] >= 10) 
        {
            inventory[i] -= 10;
            orders[i] += 1;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() 
{
    pthread_t pharmacist;
    pthread_t customers[5];

    // initializing mutex
    pthread_mutex_init(&mutex, NULL);

    // creating pharmacist thread
    pthread_create(&pharmacist, NULL, pharmacistFunc, NULL);

    // creating customer threads
    int i;
    for (i = 0; i < 5; i++) 
    {
        pthread_create(&customers[i], NULL, customerFunc, NULL);
    }

    // joining threads
    pthread_join(pharmacist, NULL);
    for (i = 0; i < 5; i++) 
    {
        pthread_join(customers[i], NULL);
    }

    // calculating total sales
    calculateTotalSales();

    // printing inventory after orders
    printf("Inventory After Orders: %d %d %d %d %d\n", inventory[0], inventory[1], inventory[2], inventory[3], inventory[4]);

    // printing orders and total sales
    printf("Orders: %d %d %d %d %d\n", orders[0], orders[1], orders[2], orders[3], orders[4]);
    printf("Total Sales: %d\n", total_sales);

    // destroying mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}