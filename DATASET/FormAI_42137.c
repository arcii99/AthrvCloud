//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for number of passengers, baggage limit, and number of carts
#define NUM_PASSENGERS 100
#define BAGGAGE_LIMIT 50
#define NUM_CARTS 5

int main() {
    srand(time(NULL)); // seed random number generator
    
    // Initialize variables
    int passengers[NUM_PASSENGERS], baggage[NUM_PASSENGERS], carts[NUM_CARTS][BAGGAGE_LIMIT];
    int i, j, k, cart_capacity, num_bags, total_bags = 0;
    
    // Generate random number of bags and assign to each passenger
    for (i = 0; i < NUM_PASSENGERS; i++) {
        num_bags = rand() % 5; // random number of bags per passenger (0-4)
        baggage[i] = num_bags; // add number of bags to baggage array
        total_bags += num_bags; // add to total number of bags
    }
    
    // Print summary of baggage count
    printf("Total number of passengers: %d\n", NUM_PASSENGERS);
    printf("Total number of bags: %d\n\n", total_bags);
    
    // Calculate number of carts needed and print summary
    int num_carts_needed = total_bags / BAGGAGE_LIMIT + 1;
    printf("Number of carts needed: %d\n\n", num_carts_needed);
    
    // Initialize carts with passenger bags
    int current_cart = 0; // index of current cart
    cart_capacity = 0; // current cart's baggage count
    for (i = 0; i < NUM_PASSENGERS; i++) {
        if (baggage[i] > BAGGAGE_LIMIT) { // check for oversized luggage
            printf("Passenger %d has oversized luggage and needs special handling.\n", i+1);
        } else {
            if (cart_capacity + baggage[i] > BAGGAGE_LIMIT) { // check if current cart is full
                current_cart++;
                cart_capacity = 0;
            }
            carts[current_cart][cart_capacity] = baggage[i]; // add bag to current cart
            cart_capacity++;
            passengers[i] = current_cart; // assign passenger to current cart
        }
    }
    
    // Print summary of cart contents and passengers assigned to each cart
    printf("\nSummary of cart contents:\n");
    for (i = 0; i < num_carts_needed; i++) {
        printf("Cart %d contents: ", i+1);
        for (j = 0; j < BAGGAGE_LIMIT; j++) {
            if (carts[i][j] != 0) {
                printf("%d ", carts[i][j]);
            }
        }
        printf("\n");
        printf("Passengers assigned to cart %d: ", i+1);
        for (k = 0; k < NUM_PASSENGERS; k++) {
            if (passengers[k] == i) {
                printf("%d ", k+1);
            }
        }
        printf("\n\n");
    }
    
    return 0;
}