//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* id;
    int weight;
} Baggage;

typedef struct {
    int arrivalTime;
    Baggage baggage;
} Passenger;

typedef struct {
    Baggage* bags[4];
    int numBags;
} Cart;

int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void loadCart(Cart* cart, Baggage* bag) {
    if (cart->numBags < 4) {
        cart->bags[cart->numBags] = bag;
        cart->numBags++;
        printf("[Cart] Baggage loaded into cart. Cart now has %d bags.\n", cart->numBags);
    } else {
        printf("[Cart] Cart is full. Cannot load more baggage.\n");
    }
}

void unloadCart(Cart* cart) {
    printf("[Cart] Unloading cart...\n");
    for (int i = 0; i < cart->numBags; i++) {
        Baggage* bag = cart->bags[i];
        printf("[Cart] Baggage %s with weight %d kg has been unloaded.\n", bag->id, bag->weight);
        free(bag->id);
        free(bag);
    }
    cart->numBags = 0;
}

void handleBaggage(Passenger* passenger, Cart* carts, int numCarts) {
    printf("[Baggage Handler] Handling baggage for passenger with arrival time of %d...\n", passenger->arrivalTime);
    for (int i = 0; i < passenger->baggage.weight; i++) {
        int cartIndex = generateRandomNumber(0, numCarts - 1);
        loadCart(&carts[cartIndex], &passenger->baggage);
    }
}

void simulateAirport(int numCarts, int numPassengers, int maxWeight) {
    Cart carts[numCarts];
    memset(carts, 0, sizeof(carts));
    Passenger passengers[numPassengers];
    srand(time(NULL));
    for (int i = 0; i < numPassengers; i++) {
        Baggage* bag = (Baggage*) malloc(sizeof(Baggage));
        bag->id = (char*) malloc(sizeof(char) * 7);
        sprintf(bag->id, "%06d", i + 1);
        bag->weight = generateRandomNumber(1, maxWeight);
        Passenger passenger = { generateRandomNumber(1, 60), *bag };
        passengers[i] = passenger;
    }
    for (int i = 1; i <= 60; i++) {
        printf("[Time: %d]\n", i);
        for (int j = 0; j < numPassengers; j++) {
            Passenger passenger = passengers[j];
            if (passenger.arrivalTime == i) {
                handleBaggage(&passenger, carts, numCarts);
            }
        }
        for (int j = 0; j < numCarts; j++) {
            Cart cart = carts[j];
            if (cart.numBags > 0) {
                unloadCart(&cart);
            }
        }
    }
}

int main() {
    simulateAirport(3, 20, 10);
    return 0;
}