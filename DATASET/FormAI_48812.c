//FormAI DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Coin structure
struct Stock {
    char name[50];
    double price;
    double change;
};

int main() {
    // Create an array to store 5 stocks
    struct Stock stocks[5];
    
    // Initialize each stock with a name and a random price
    strcpy(stocks[0].name, "Apple");
    stocks[0].price = 150.0;
    strcpy(stocks[1].name, "Google");
    stocks[1].price = 200.0;
    strcpy(stocks[2].name, "Microsoft");
    stocks[2].price = 130.0;
    strcpy(stocks[3].name, "Tesla");
    stocks[3].price = 700.0;
    strcpy(stocks[4].name, "Amazon");
    stocks[4].price = 3200.0;
    
    // Set the change of each stock to a random percentage
    for (int i=0; i<5; i++) {
        stocks[i].change = ((double)rand()/(double)RAND_MAX)*10.0 - 5.0;
    }
    
    // Print the initial prices and changes of each stock
    printf("Initial Prices:\n");
    for (int i=0; i<5; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    
    // Wait for user input to update the prices and changes
    printf("Press ENTER to update the prices and changes...\n");
    getchar();
    
    // Update the prices and changes of each stock
    for (int i=0; i<5; i++) {
        double new_price = stocks[i].price*(1.0 + (stocks[i].change/100.0));
        stocks[i].price = new_price;
        stocks[i].change = ((double)rand()/(double)RAND_MAX)*10.0 - 5.0;
    }
    
    // Print the updated prices and changes of each stock
    printf("Updated Prices:\n");
    for (int i=0; i<5; i++) {
        printf("%s: $%.2f (%+.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    
    return 0;
}