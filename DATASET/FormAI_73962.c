//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Baggage {
    int id;
    int weight;
};

struct LuggageCart {
    int maxCapacity;
    int currentWeight;
    struct Baggage baggages[50];
    int numBaggages;
};

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void loadBaggage(struct LuggageCart* cart, struct Baggage baggage) {
    if (cart->currentWeight + baggage.weight <= cart->maxCapacity) {
        cart->currentWeight += baggage.weight;
        cart->baggages[cart->numBaggages] = baggage;
        cart->numBaggages++;
    } else {
        printf("Luggage cart is full!\n");
    }
}

void unloadBaggage(struct LuggageCart* cart) {
    if (cart->numBaggages > 0) {
        struct Baggage baggage = cart->baggages[cart->numBaggages-1];
        printf("Unloading baggage with ID %d and weight %d\n", baggage.id, baggage.weight);
        cart->numBaggages--;
        cart->currentWeight -= baggage.weight;
    } else {
        printf("Luggage cart is empty!\n");
    }
}

int main() {
    srand(time(0));
    struct LuggageCart cart1 = { 1000, 0, {}, 0 };
    struct LuggageCart cart2 = { 1000, 0, {}, 0 };
    struct LuggageCart cart3 = { 1000, 0, {}, 0 };

    for (int i = 0; i < 10; i++) {
        struct Baggage baggage = { i+1, randInt(20, 100) };
        printf("Loading baggage with ID %d and weight %d\n", baggage.id, baggage.weight);
        if (i % 3 == 0) {
            loadBaggage(&cart1, baggage);
        } else if (i % 3 == 1) {
            loadBaggage(&cart2, baggage);
        } else {
            loadBaggage(&cart3, baggage);
        }
    }

    printf("\nUnloading cart 1\n");
    while (cart1.numBaggages > 0) {
        unloadBaggage(&cart1);
    }

    printf("\nUnloading cart 2\n");
    while (cart2.numBaggages > 0) {
        unloadBaggage(&cart2);
    }

    printf("\nUnloading cart 3\n");
    while (cart3.numBaggages > 0) {
        unloadBaggage(&cart3);
    }

    return 0;
}