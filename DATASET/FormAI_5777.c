//FormAI DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define NUM_ITEMS 10
#define MAX_STRING_SIZE 30

typedef struct Item_t
{
    char name[MAX_STRING_SIZE];
    int price;
} Item;

// Async function to fetch the name of an item
void* get_item_name(void* item)
{
    Item* i = (Item*) item;
    // Simulate some delay
    usleep(1000000);
    char* name = malloc(sizeof(char) * MAX_STRING_SIZE);
    strncpy(name, i->name, MAX_STRING_SIZE);
    return name;
}

// Async function to fetch the price of an item
void* get_item_price(void* item)
{
    Item* i = (Item*) item;
    // Simulate some delay
    usleep(500000);
    int* price = malloc(sizeof(int));
    *price = i->price;
    return price;
}

int main()
{
    Item items[NUM_ITEMS];
    strcpy(items[0].name, "Apples");
    items[0].price = 2;
    strcpy(items[1].name, "Oranges");
    items[1].price = 3;
    strcpy(items[2].name, "Bananas");
    items[2].price = 1;
    strcpy(items[3].name, "Grapes");
    items[3].price = 4;
    strcpy(items[4].name, "Pears");
    items[4].price = 2;
    strcpy(items[5].name, "Strawberries");
    items[5].price = 5;
    strcpy(items[6].name, "Mangoes");
    items[6].price = 6;
    strcpy(items[7].name, "Pineapples");
    items[7].price = 4;
    strcpy(items[8].name, "Watermelon");
    items[8].price = 7;
    strcpy(items[9].name, "Honeydew");
    items[9].price = 5;

    // Create threads to fetch names and prices of items
    pthread_t name_threads[NUM_ITEMS];
    pthread_t price_threads[NUM_ITEMS];
    for(int i = 0; i < NUM_ITEMS; i++)
    {
        pthread_create(&name_threads[i], NULL, get_item_name, &items[i]);
        pthread_create(&price_threads[i], NULL, get_item_price, &items[i]);
    }

    // Wait for threads to complete and fetch results
    char* names[NUM_ITEMS];
    int prices[NUM_ITEMS];
    for(int i = 0; i < NUM_ITEMS; i++)
    {
        pthread_join(name_threads[i], (void**) &names[i]);
        pthread_join(price_threads[i], (void**) &prices[i]);
    }

    // Display results
    for(int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s - %d\n", names[i], prices[i]);
    }

    // Free memory allocated for names
    for(int i = 0; i < NUM_ITEMS; i++)
    {
        free(names[i]);
    }

    return 0;
}