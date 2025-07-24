//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10 // maximum number of bags that can be processed at a time
#define MAX_WEIGHT 50 // maximum weight of a bag allowed
#define CAPACITY 100 // maximum weight capacity of cart

typedef struct {
    int weight;
} Bag;

typedef struct {
    int id;
    int current_weight;
    Bag bags[MAX_SIZE];
} Cart;

int main() {
    srand(time(NULL));

    Cart cart = {1, 0, {0}}; // initialize cart values

    for (int i = 0; i < MAX_SIZE; i++) {
        int weight = rand() % MAX_WEIGHT + 1;
        Bag new_bag = {weight};

        if (cart.current_weight + new_bag.weight > CAPACITY) {
            printf("Cart %d is full, moving to next cart...\n", cart.id);
            cart.id++;
            cart.current_weight = 0;
        }

        cart.bags[i] = new_bag;
        cart.current_weight += new_bag.weight;

        printf("Bag %d with weight %d has been added to cart %d with current weight %d / %d\n", i + 1, new_bag.weight, cart.id, cart.current_weight, CAPACITY);
    }

    return 0;
}