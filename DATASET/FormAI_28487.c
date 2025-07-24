//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>

// This function calculates the maximum number of toys that can be purchased within a budget
int maxToys(int budget, int toyPrices[], int n) {
    int i, maxToys = 0;
    for(i = 0; i < n; i++) {
        if(toyPrices[i] <= budget) { // if the toy is within the budget
            budget -= toyPrices[i]; // reduce budget by the toy price
            maxToys++; // increment the number of toys purchased
        }
    }
    printf("Woohoo! You can buy %d toys with a budget of $%d\n", maxToys, budget);
    return maxToys;
}

int main() {
    int budget = 50; // toy budget
    int toyPrices[] = {10, 20, 5, 30, 15}; // prices of toys in the store
    int n = sizeof(toyPrices)/sizeof(toyPrices[0]); // total number of toys in the store

    printf("Welcome to the toy store!\n\n");

    // Display the toy prices in the store
    printf("We have the following toys in our store:\n\n");
    for(int i = 0; i < n; i++) {
        printf("Toy %d costs $%d\n", i+1, toyPrices[i]);
    }
    printf("\n");

    // Calculate maximum number of toys purchasable within the budget
    maxToys(budget, toyPrices, n);
    return 0;
}