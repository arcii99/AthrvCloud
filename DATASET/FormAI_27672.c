//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to store stock market information
typedef struct {
    int id;
    char* name;
    float price;
    float change;
} Stock;

int main(void) {
    // Seed random number generator for simulated stock market changes 
    srand(time(NULL));
    
    // Create an array of three stock market objects
    Stock stocks[3] = {
        {1, "Apple Inc.", 128.46, 0.55},
        {2, "Microsoft Corporation", 242.35, -0.22},
        {3, "Amazon.com, Inc.", 3337.47, 0.12}
    };
    
    // Print initial stock market values
    printf("Initial Stock Market Values\n");
    printf("----------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - $%.2f (%+.2f%%)\n", 
               stocks[i].id, stocks[i].name, stocks[i].price, stocks[i].change);
    }
    
    // Simulate daily changes in stock market values
    printf("\nDaily Change in Stock Market Values\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < 3; i++) {
        // Generate a random change percentage between -5% and +5%
        float changePercent = ((float)rand() / RAND_MAX) * 10 - 5;
        
        // Update stock market values with random change percent
        stocks[i].change = changePercent;
        stocks[i].price *= (1 + changePercent / 100);
        
        // Print daily change results for each stock
        printf("%d. %s - $%.2f (%+.2f%%)\n", 
               stocks[i].id, stocks[i].name, stocks[i].price, stocks[i].change);
    }
    
    // Print updated stock market values after daily changes
    printf("\nUpdated Stock Market Values\n");
    printf("---------------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - $%.2f (%+.2f%%)\n", 
               stocks[i].id, stocks[i].name, stocks[i].price, stocks[i].change);
    }
    
    return 0;
}