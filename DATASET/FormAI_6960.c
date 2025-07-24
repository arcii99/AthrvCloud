//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Stock {
    char name[50];
    float price;
};

int main() {
    srand(time(NULL)); // set seed for random number generator
    
    // create an array of Stock objects
    struct Stock stocks[10];
    
    // generate random stock prices and names
    for(int i=0; i<10; i++) {
        float price = ((float)rand()) / RAND_MAX * 100; // generate a random float between 0 and 100
        sprintf(stocks[i].name, "Stock%d", i+1); // set stock name as StockX, where X is the index of the array + 1
        stocks[i].price = price;
    }
    
    // display the initial stock prices
    printf("Initial stock prices:\n");
    for(int i=0; i<10; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
    
    // simulate changes in the stock prices
    for(int i=0; i<10; i++) {
        float change = ((float)rand() / RAND_MAX) * 10 - 5; // generate a random float between -5 and 5
        stocks[i].price += change;
    }
    
    // display the updated stock prices
    printf("\nUpdated stock prices:\n");
    for(int i=0; i<10; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
    
    return 0;
}