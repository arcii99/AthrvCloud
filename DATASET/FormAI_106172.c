//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define NUM_OF_BAGS 50
#define MAX_WEIGHT 50

// define structs
typedef struct {
    int id;
    int weight;
} Bag;

typedef struct {
    int id;
    Bag* bags;
    int numOfBags;
    int totalWeight;
} LuggageCart;

// function prototypes
void initializeBags(Bag bags[]);
void printLuggageCart(LuggageCart cart);
void loadLuggageCart(LuggageCart* cart, Bag bags[], int bagIndex);
void unloadLuggageCart(LuggageCart* cart);
void simulateLuggageHandling();

int main() {
    srand(time(NULL)); // seed the random number generator
    simulateLuggageHandling();
    return 0;
}

void initializeBags(Bag bags[]) {
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        bags[i].id = i;
        bags[i].weight = rand() % MAX_WEIGHT;
    }
}

void printLuggageCart(LuggageCart cart) {
    printf("Luggage cart #%d: [", cart.id);
    for (int i = 0; i < cart.numOfBags; i++) {
        printf("(%d,%d)", cart.bags[i].id, cart.bags[i].weight);
        if (i != cart.numOfBags-1) {
            printf(", ");
        }
    }
    printf("] Total weight: %d\n", cart.totalWeight);
}

void loadLuggageCart(LuggageCart* cart, Bag bags[], int bagIndex) {
    cart->numOfBags = rand() % 10 + 1; // load 1-10 bags
    cart->bags = (Bag*) malloc(cart->numOfBags * sizeof(Bag));
    cart->totalWeight = 0;
    for (int i = 0; i < cart->numOfBags; i++) {
        cart->bags[i] = bags[bagIndex+i];
        cart->totalWeight += cart->bags[i].weight;
    }
}

void unloadLuggageCart(LuggageCart* cart) {
    free(cart->bags);
    cart->numOfBags = 0;
    cart->totalWeight = 0;
}

void simulateLuggageHandling() {
    Bag bags[NUM_OF_BAGS];
    initializeBags(bags);
    LuggageCart carts[3];
    carts[0].id = 1;
    carts[1].id = 2;
    carts[2].id = 3;
    int bagIndex = 0;
    int currCart = 1;
    for (int i = 0; i < NUM_OF_BAGS; i++) {
        loadLuggageCart(&carts[currCart-1], bags, bagIndex);
        printf("*** Loading cart #%d with bags %d-%d ***\n", currCart, bagIndex+1, bagIndex+carts[currCart-1].numOfBags);
        printLuggageCart(carts[currCart-1]);
        unloadLuggageCart(&carts[currCart-1]);
        printf("*** Cart #%d unloaded ***\n", currCart);
        if (currCart == 3) {
            currCart = 1;
        } else {
            currCart++;
        }
        bagIndex += carts[currCart-1].numOfBags;
    }
}