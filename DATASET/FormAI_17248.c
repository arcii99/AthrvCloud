//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

struct Stock {
    char name[50];
    float price;
};

int main() {
    struct Stock stocks[MAX_STOCKS];

    int n;
    printf("Enter number of stocks (max 10): ");
    scanf("%d", &n);

    if(n > 10) {
        printf("You can enter a maximum of 10 stocks.\n");
        return 0;
    }

    // Accept input for stocks
    for(int i = 0; i < n; i++) {
        printf("Enter the name of the stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the price of the stock %d: ", i+1);
        scanf("%f", &stocks[i].price);
    }

    // Display the stocks
    printf("\nStocks:\n");
    printf("Name\tPrice\n");
    for(int i = 0; i < n; i++)
        printf("%s\t%.2f\n", stocks[i].name, stocks[i].price);

    // Calculate the average price of the stocks
    float avg_price = 0.0;
    for(int i = 0; i < n; i++)
        avg_price += stocks[i].price;
    avg_price /= n;

    printf("\nAverage price of stocks: %.2f\n", avg_price);

    return 0;
}