//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COMPANY_NAME 50
#define MAX_STOCK_VALUE 1000

typedef struct {
    char company_name[MAX_COMPANY_NAME];
    float stock_value;
    float stock_change;
} company;

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Create array of company structs
    company companies[5] = {
            {"Apple Inc.", 289.07, -1.09},
            {"Microsoft Corporation", 209.83, 0.17},
            {"Amazon.com, Inc.", 3119.00, -3.19},
            {"Tesla, Inc.", 427.64, 5.64},
            {"Facebook, Inc.", 257.64, -0.89}
    };

    // Print initial stock values
    printf("%-30s %-15s %-15s\n", "Company Name", "Stock Value", "Stock Change");
    for(int i = 0; i < 5; i++) {
        printf("%-30s $%-14.2f %+15.2f\n", companies[i].company_name, companies[i].stock_value, companies[i].stock_change);
    }
    printf("\n");

    // Simulate stock market changes
    for(int i = 0; i < 5; i++) {
        float rand_val = ((float) rand() / RAND_MAX) * MAX_STOCK_VALUE;
        companies[i].stock_value += rand_val;
        companies[i].stock_change = (rand_val / MAX_STOCK_VALUE) * 100;
    }

    // Print updated stock values
    printf("%-30s %-15s %-15s\n", "Company Name", "Stock Value", "Stock Change");
    for(int i = 0; i < 5; i++) {
        printf("%-30s $%-14.2f %+15.2f%%\n", companies[i].company_name, companies[i].stock_value, companies[i].stock_change);
    }

    return 0;
}