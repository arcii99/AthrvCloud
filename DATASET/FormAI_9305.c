//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// define constants
#define NUM_TRANSACTIONS 5
#define NUM_ITEMS 4

int main(void) {
    // define transaction data
    int transactions[NUM_TRANSACTIONS][NUM_ITEMS] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 0, 0, 1}
    };
    
    // define frequency counts for each item
    int item_counts[NUM_ITEMS] = {0};
    
    // iterate through each transaction and update item counts
    for (int i = 0; i < NUM_TRANSACTIONS; i++) {
        for (int j = 0; j < NUM_ITEMS; j++) {
            if (transactions[i][j] == 1) {
                item_counts[j]++;
            }
        }
    }
    
    // print item counts
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Item %d appears in %d transactions\n", i, item_counts[i]);
    }
    
    // find items that appear in at least 3 transactions
    printf("Frequent items:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (item_counts[i] >= 3) {
            printf("Item %d\n", i);
        }
    }
    
    return 0;
}