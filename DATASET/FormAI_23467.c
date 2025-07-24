//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define NUM_TRANSACTIONS 100
#define NUM_ITEMS 10
#define SUPPORT_THRESHOLD 0.5

int main() {
    int transactions[NUM_TRANSACTIONS][NUM_ITEMS] = {0};
    float item_support[NUM_ITEMS] = {0};
    int item_counts[NUM_ITEMS] = {0};
    
    // Generate random transactions
    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        int num_items = rand() % NUM_ITEMS + 1; // Choose a random number of items between 1 and NUM_ITEMS
        for (int j = 0; j < num_items; j++) {
            int item = rand() % NUM_ITEMS;
            transactions[i][item] = 1; // Mark item as present in transaction
            item_counts[item]++; // Increment count for item
        }
    }
    
    // Calculate support for each item
    for (int i = 0; i < NUM_ITEMS; i++) {
        item_support[i] = (float)item_counts[i] / NUM_TRANSACTIONS;
        printf("Item %d support: %f\n", i, item_support[i]);
    }
    
    // Check for frequent itemsets
    for (int i = 0; i < NUM_ITEMS; i++) {
        for (int j = i+1; j < NUM_ITEMS; j++) {
            float support = 0;
            for (int k = 0; k < NUM_TRANSACTIONS; k++) {
                if (transactions[k][i] && transactions[k][j]) {
                    support++;
                }
            }
            support /= NUM_TRANSACTIONS;
            if (support > SUPPORT_THRESHOLD) {
                printf("{%d, %d} is a frequent itemset with support %f\n", i, j, support);
            }
        }
    }
    
    return 0;
}