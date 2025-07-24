//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_WAREHOUSES 10
#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 50
#define MAX_THREADS 10

// Item struct
typedef struct item
{
    int id;
    char name[MAX_NAME_LENGTH];
    bool available;
} Item;

// Warehouse struct
typedef struct warehouse
{
    int id;
    char name[MAX_NAME_LENGTH];
    Item items[MAX_ITEMS];
    int num_items;
    pthread_mutex_t lock;
} Warehouse;

// Global variables
Warehouse warehouses[MAX_WAREHOUSES];
int num_warehouses = 0;
pthread_mutex_t num_warehouses_lock;
int total_items = 0;
pthread_mutex_t total_items_lock;

// Function prototypes
void* add_item_thread(void* warehouse_ptr);
void* remove_item_thread(void* warehouse_ptr);
void print_warehouse(Warehouse* warehouse_ptr);
void print_all_warehouses();

int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Initialize mutexes
    pthread_mutex_init(&num_warehouses_lock, NULL);
    pthread_mutex_init(&total_items_lock, NULL);

    // Create warehouses
    Warehouse warehouse1 = {1, "Warehouse 1"};
    Warehouse warehouse2 = {2, "Warehouse 2"};

    // Initialize warehouses with random items
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        Item item = {i, "Item Name", true};
        if (rand() % 2 == 0)
        {
            item.available = false;
        }
        warehouse1.items[i] = item;
        warehouse1.num_items++;
    }

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        Item item = {i + MAX_ITEMS, "Item Name", true};
        if (rand() % 2 == 0)
        {
            item.available = false;
        }
        warehouse2.items[i] = item;
        warehouse2.num_items++;
    }

    // Add warehouses to global array
    pthread_mutex_lock(&num_warehouses_lock);
    warehouses[num_warehouses++] = warehouse1;
    warehouses[num_warehouses++] = warehouse2;
    pthread_mutex_unlock(&num_warehouses_lock);

    // Print initial state of warehouses
    printf("Initial state of warehouses:\n");
    print_all_warehouses();
    printf("\n");

    // Create threads to add and remove items
    pthread_t add_threads[MAX_THREADS];
    pthread_t remove_threads[MAX_THREADS];
    int num_threads = 4;

    for (int i = 0; i < num_threads; i++)
    {
        pthread_create(&add_threads[i], NULL, add_item_thread, &warehouse1);
        pthread_create(&remove_threads[i], NULL, remove_item_thread, &warehouse2);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(add_threads[i], NULL);
        pthread_join(remove_threads[i], NULL);
    }

    // Print final state of warehouses
    printf("\nFinal state of warehouses:\n");
    print_all_warehouses();

    // Destroy mutexes
    pthread_mutex_destroy(&num_warehouses_lock);
    pthread_mutex_destroy(&total_items_lock);

    return 0;
}

// Thread function to add item to warehouse
void* add_item_thread(void* warehouse_ptr)
{
    Warehouse* warehouse = (Warehouse*) warehouse_ptr;

    while (true)
    {
        // Choose random item to add to warehouse
        int index = rand() % MAX_ITEMS;
        Item* item = &warehouse->items[index];

        // Lock item before checking availability and modifying
        pthread_mutex_lock(&warehouse->lock);
        if (!item->available)
        {
            pthread_mutex_unlock(&warehouse->lock);
            continue;
        }
        item->available = false;
        warehouse->num_items++;
        pthread_mutex_unlock(&warehouse->lock);

        // Update total items
        pthread_mutex_lock(&total_items_lock);
        total_items++;
        pthread_mutex_unlock(&total_items_lock);

        printf("Added item %d to warehouse %d\n", item->id, warehouse->id);
        usleep(50);
    }
}

// Thread function to remove item from warehouse
void* remove_item_thread(void* warehouse_ptr)
{
    Warehouse* warehouse = (Warehouse*) warehouse_ptr;

    while (true)
    {
        // Choose random item to remove from warehouse
        int index = rand() % MAX_ITEMS;
        Item* item = &warehouse->items[index];

        // Lock item before checking availability and modifying
        pthread_mutex_lock(&warehouse->lock);
        if (item->available)
        {
            pthread_mutex_unlock(&warehouse->lock);
            continue;
        }
        item->available = true;
        warehouse->num_items--;
        pthread_mutex_unlock(&warehouse->lock);

        // Update total items
        pthread_mutex_lock(&total_items_lock);
        total_items--;
        pthread_mutex_unlock(&total_items_lock);

        printf("Removed item %d from warehouse %d\n", item->id, warehouse->id);
        usleep(50);
    }
}

// Print information about a warehouse
void print_warehouse(Warehouse* warehouse_ptr)
{
    printf("Warehouse %d: %s\n", warehouse_ptr->id, warehouse_ptr->name);
    printf("Number of items: %d\n", warehouse_ptr->num_items);

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        Item* item = &warehouse_ptr->items[i];

        if (item->available)
        {
            printf("Item %d: %s (available)\n", item->id, item->name);
        }
        else
        {
            printf("Item %d: %s (not available)\n", item->id, item->name);
        }
    }
}

// Print information about all warehouses
void print_all_warehouses()
{
    for (int i = 0; i < num_warehouses; i++)
    {
        print_warehouse(&warehouses[i]);
        printf("\n");
    }

    printf("Total items: %d\n", total_items);
}