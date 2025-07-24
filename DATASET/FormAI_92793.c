//FormAI DATASET v1.0 Category: Data mining ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TRANSACTIONS 100000
#define NUM_ITEMS 10
#define SUPPORT_LEVEL 0.2

int main() {
    // Define the transactions database
    int transactions[NUM_TRANSACTIONS][NUM_ITEMS];
    
    // Initialize the random number generator for transaction generation
    srand(time(NULL));
    
    // Generate the transactions database
    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        for (int j = 0; j < NUM_ITEMS; j++) {
            transactions[i][j] = rand() % 2; // 0 or 1
        }
    }
    
    // Define the itemsets found in the transactions database
    int itemsets[NUM_ITEMS] = {0};
    
    // Count the support of each itemset
    for (int i = 0; i < NUM_ITEMS; i++) {
        for (int j = 0; j < NUM_TRANSACTIONS; j++) {
            if (transactions[j][i] == 1) {
                itemsets[i] += 1;
            }
        }
    }
    
    // Print the support of each itemset
    printf("Itemsets support:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        float support = (float)itemsets[i] / (float)NUM_TRANSACTIONS;
        printf("Itemset %d: %.2f\n", i, support);
    }
    
    // Find frequent itemsets
    printf("\nFrequent itemsets:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        float support = (float)itemsets[i] / (float)NUM_TRANSACTIONS;
        if (support >= SUPPORT_LEVEL) {
            printf("Itemset %d: %.2f\n", i, support);
        }
    }
    
    return 0;
}