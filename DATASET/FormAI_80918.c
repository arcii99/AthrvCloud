//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

double total_amount = 0.0; // global variable to keep track of total amount earned
pthread_mutex_t lock; // mutex lock to protect the critical section of code

struct item {
    char name[50];
    double price;
};

void* process_order(void* arg) {
    struct item* ordered_item = (struct item*) arg;

    printf("Processing order for %s\n", ordered_item->name);

    // simulate some processing time
    usleep(1000);

    // add the price of the ordered item to the total amount earned
    pthread_mutex_lock(&lock);
    total_amount += ordered_item->price;
    pthread_mutex_unlock(&lock);

    printf("%s processed successfully!\n", ordered_item->name);

    return NULL;
}

int main() {
    pthread_t tid[5]; // 5 possible concurrent orders
    struct item menu[5]; // cafe menu
    
    // populate menu items
    strcpy(menu[0].name, "Latte");
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Cappuccino");
    menu[1].price = 2.75;
    strcpy(menu[2].name, "Espresso");
    menu[2].price = 1.50;
    strcpy(menu[3].name, "Mocha");
    menu[3].price = 3.00;
    strcpy(menu[4].name, "Chai Tea Latte");
    menu[4].price = 2.25;

    // take 5 random orders from the menu
    for(int i=0; i<5; i++) {
        int item_num = rand() % 5; // generate random item number between 0-4
        struct item ordered_item = menu[item_num]; // get the corresponding menu item
        pthread_create(&tid[i], NULL, process_order, &ordered_item); // create thread to process the order
    }

    // wait for all threads to complete
    for(int i=0; i<5; i++) {
        pthread_join(tid[i], NULL);
    }

    // print total amount earned
    printf("Total amount earned: $%.2f\n", total_amount);

    return 0;
}