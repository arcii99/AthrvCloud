//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 1000 // maximum number of items that can be processed by the system
#define MAX_WEIGHT 50 // maximum weight of an item
#define MAX_FLOORS 5 // maximum number of floors in the airport
#define MAX_BAGGAGE_CART 10 // maximum number of bags a single cart can carry

// struct to store the information of an item
typedef struct {
    int id;
    int weight;
    int floor;
} Item;

// struct to store the information of a baggage cart
typedef struct {
    int id;
    int current_floor;
    int num_of_items;
    Item items[MAX_BAGGAGE_CART];
} BaggageCart;

// initialize the baggage cart with given id and current floor
void init_cart(BaggageCart *cart, int id, int floor) {
    cart->id = id;
    cart->current_floor = floor;
    cart->num_of_items = 0;
}

// add an item to the given baggage cart
void add_item(BaggageCart *cart, Item item) {
    if (cart->num_of_items < MAX_BAGGAGE_CART) {
        cart->items[cart->num_of_items++] = item;
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // generate some random items
    Item items[MAX_ITEMS];
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].id = i + 1;
        items[i].weight = rand() % MAX_WEIGHT + 1;
        items[i].floor = rand() % MAX_FLOORS + 1;
    }

    // initialize the baggage carts
    BaggageCart carts[MAX_FLOORS];
    for (int i = 0; i < MAX_FLOORS; i++) {
        init_cart(&carts[i], i + 1, 1);
    }

    // process the items
    int num_of_items_processed = 0;
    while (num_of_items_processed < MAX_ITEMS) {
        // randomly select an item
        Item item = items[rand() % MAX_ITEMS];

        // find the nearest baggage cart
        BaggageCart *nearest_cart = &carts[0];
        int min_distance = abs(item.floor - nearest_cart->current_floor);
        for (int i = 1; i < MAX_FLOORS; i++) {
            int distance = abs(item.floor - carts[i].current_floor);
            if (distance < min_distance && carts[i].num_of_items < MAX_BAGGAGE_CART) {
                nearest_cart = &carts[i];
                min_distance = distance;
            }
        }

        // add the item to the nearest baggage cart
        add_item(nearest_cart, item);
        num_of_items_processed++;

        // move the carts
        for (int i = 0; i < MAX_FLOORS; i++) {
            int direction = (rand() % 2 == 0) ? -1 : 1;
            carts[i].current_floor += direction;
            if (carts[i].current_floor < 1) {
                carts[i].current_floor = 1;
            }
            if (carts[i].current_floor > MAX_FLOORS) {
                carts[i].current_floor = MAX_FLOORS;
            }
        }
    }

    printf("All items processed successfully!\n");

    return 0;
}