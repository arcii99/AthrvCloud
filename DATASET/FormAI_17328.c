//FormAI DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>

// Define maximum size of stock names and prices array
#define MAX_SIZE 20

// Define struct to hold stock information
typedef struct {
    char name[MAX_SIZE];
    double price;
} Stock;

int main() {
    // Define and initialize stocks array
    Stock stocks[] = {
        {"Apple", 125.19},
        {"Microsoft", 234.51},
        {"Amazon", 3233.99},
        {"Tesla", 701.98},
        {"Facebook", 315.94}
    };

    // Calculate total value of all stocks
    double totalValue = 0;
    for (int i = 0; i < 5; i++) {
        totalValue += stocks[i].price;
    }

    // Display stock information and total value
    printf("Stock Name\t\tPrice\n");
    for (int i = 0; i < 5; i++) {
        printf("%-15s\t\t%.2f\n", stocks[i].name, stocks[i].price);
    }
    printf("Total Value of Stocks:\t%.2f\n", totalValue);

    return 0;
}