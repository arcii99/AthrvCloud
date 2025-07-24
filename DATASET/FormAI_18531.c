//FormAI DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>

#define MAX_STOCKS 20
#define MAX_NAME_LENGTH 20

typedef struct stock {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

int main() {
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];
    float total = 0;

    //get user input for stocks
    printf("Enter the number of stocks: ");
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("\nEnter stock %d name: ", i+1);
        scanf("%s", stocks[i].name);
        printf("Enter stock %d price: ", i+1);
        scanf("%f", &stocks[i].price);
        printf("Enter stock %d quantity: ", i+1);
        scanf("%d", &stocks[i].quantity);
    }

    //calculate and print individual and total stock values
    printf("\n------------\n");
    for (int i = 0; i < numStocks; i++) {
        float value = stocks[i].price * stocks[i].quantity;
        printf("%s: %d shares x $%.2f = $%.2f\n", stocks[i].name, stocks[i].quantity, stocks[i].price, value);
        total += value;
    }
    printf("------------\nTotal stock value: $%.2f\n", total);

    return 0;
}