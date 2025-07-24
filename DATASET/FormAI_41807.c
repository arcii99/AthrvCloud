//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE_WEIGHT 50 // Maximum weight of a single baggage
#define MAX_BAGGAGE_SIZE 100 // Maximum size of a single baggage
#define MAX_BAGGAGE_COUNT 1000 // Maximum count of the baggage in the airport
#define MAX_LUGGAGE_CAPACITY 500 // Maximum capacity of the baggage cart
#define MAX_LUGGAGE_CART_COUNT 50 // Maximum number of baggage carts

int baggage[MAX_BAGGAGE_COUNT]; // Array to keep track of luggage bags

int main() {
    srand(time(NULL)); // Initialize random seed

    // Generate random baggage and add them to the array
    for(int i = 0; i < MAX_BAGGAGE_COUNT; i++) {
        baggage[i] = rand() % MAX_BAGGAGE_WEIGHT + 1; // Randomly assign weight to the baggage
    }

    int luggageCart[MAX_LUGGAGE_CART_COUNT][MAX_LUGGAGE_CAPACITY]; // Array of luggage carts
    int cartWeight[MAX_LUGGAGE_CART_COUNT] = {0}; // Array to keep track of weight of each cart

    // Loading the bags onto the carts
    for(int i = 0; i < MAX_BAGGAGE_COUNT; i++) {
        int cartIndex = 0;

        for(int j = 0; j < MAX_LUGGAGE_CART_COUNT; j++) {
            if(cartWeight[j] + baggage[i] <= MAX_LUGGAGE_CAPACITY) {
                cartIndex = j;
                break;
            }
        }

        // Add the baggage to the selected cart
        luggageCart[cartIndex][cartWeight[cartIndex]] = baggage[i];
        cartWeight[cartIndex] += baggage[i];
    }

    // Printing the contents of the luggage carts
    printf("Baggage carts in the airport:\n");

    for(int i = 0; i < MAX_LUGGAGE_CART_COUNT; i++) {
        printf("Cart %d:", i);

        for(int j = 0; j < MAX_LUGGAGE_CAPACITY; j++) {
            if(luggageCart[i][j] == 0) {
                break;
            }

            printf(" %d", luggageCart[i][j]);
        }

        printf("\n");
    }

    printf("\nTotal number of baggage carts required: %d\n", (MAX_BAGGAGE_COUNT + MAX_LUGGAGE_CAPACITY - 1) / MAX_LUGGAGE_CAPACITY);

    return 0; // Program execution successful!
}