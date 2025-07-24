//FormAI DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>

// Define a struct to hold stock information
typedef struct Stock {
    char name[20];
    float price;
} Stock;

int main() {
    // Create an array of stocks
    Stock stocks[5];

    // Read in name and price for each stock
    for (int i = 0; i < 5; i++) {
        printf("Enter name and price for stock %d: ", i+1);
        scanf("%s%f", stocks[i].name, &stocks[i].price);
    }

    // Print out the stock information
    printf("\nStock Information\n");
    printf("------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s\n", stocks[i].name);
        printf("Price: %.2f\n", stocks[i].price);
        printf("\n");
    }

    // Calculate the average stock price
    float total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += stocks[i].price;
    }
    float avg_price = total / 5;

    // Print out the average stock price
    printf("Average stock price: %.2f", avg_price);
    
    return 0;
}