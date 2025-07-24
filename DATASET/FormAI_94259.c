//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_CAPACITY 20
#define NUM_TERMINALS 3
#define NUM_GATES 3

typedef struct {
    int id;
    int weight;
    int terminal;
} Baggage;

typedef struct {
    int terminal;
    int gate;
    int bags[MAX_CAPACITY];
    int size;
} LuggageCart;

LuggageCart carts[NUM_TERMINALS][NUM_GATES];

int next_bag_id = 1;
Baggage bags[MAX_BAGS];
int num_bags = 0;

bool is_cart_full(LuggageCart cart) {
    return cart.size == MAX_CAPACITY;
}

void add_bag_to_cart(LuggageCart* cart, Baggage bag) {
    cart->bags[cart->size] = bag.id;
    cart->size++;
}

void* conveyor_belt(void* arg) {
    while (true) {
        if (num_bags < MAX_BAGS) {
            int terminal = rand() % NUM_TERMINALS;
            int weight = rand() % 30 + 1;

            Baggage bag;
            bag.id = next_bag_id;
            bag.terminal = terminal;
            bag.weight = weight;

            bags[num_bags++] = bag;

            printf("New Baggage [ID: %d | Terminal: %d | Weight: %d]\n", bag.id, bag.terminal, bag.weight);
        }

        sleep(2);
    }
}

void* conveyor_loader(void* arg) {
    while (true) {
        for (int i = 0; i < num_bags; i++) {
            Baggage bag = bags[i];

            if (is_cart_full(carts[bag.terminal][0])) {
                printf("Terminal %d's first cart is full! Moving to next cart.\n", bag.terminal);
            } else {
                printf("Loading luggage cart at Terminal %d, Gate %d with Baggage [ID: %d | Weight: %d]\n", bag.terminal, 0, bag.id, bag.weight);
                add_bag_to_cart(&carts[bag.terminal][0], bag);
                memmove(&bags[i], &bags[i+1], (num_bags-i-1) * sizeof(Baggage));
                num_bags--;
            }
        }

        sleep(1);
    }
}

void* luggage_unloader(void* arg) {
    while (true) {
        for (int i = 0; i < NUM_TERMINALS; i++) {
            for (int j = 0; j < NUM_GATES; j++) {
                LuggageCart cart = carts[i][j];

                if (cart.size == 0) {
                    continue;
                }

                printf("Unloading luggage cart at Terminal %d, Gate %d with %d bags:\n", cart.terminal, cart.gate, cart.size);

                for (int k = 0; k < cart.size; k++) {
                    int bag_id = cart.bags[k];
                    Baggage* bag = NULL;

                    for (int l = 0; l < num_bags; l++) {
                        if (bags[l].id == bag_id) {
                            bag = &bags[l];
                            break;
                        }
                    }

                    printf("\t- [ID: %d | Weight: %d]\n", bag->id, bag->weight);

                    bag->id = 0;
                    bag->weight = 0;
                    bag->terminal = -1;
                }

                carts[i][j].size = 0;
                printf("Finished unloading luggage cart at Terminal %d, Gate %d.\n\n", cart.terminal, cart.gate);
            }
        }

        sleep(3);
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));

    pthread_t conveyor_belt_t, conveyor_loader_t, luggage_unloader_t;

    pthread_create(&conveyor_belt_t, NULL, conveyor_belt, NULL);
    pthread_create(&conveyor_loader_t, NULL, conveyor_loader, NULL);
    pthread_create(&luggage_unloader_t, NULL, luggage_unloader, NULL);

    pthread_join(conveyor_belt_t, NULL);
    pthread_join(conveyor_loader_t, NULL);
    pthread_join(luggage_unloader_t, NULL);

    return 0;
}