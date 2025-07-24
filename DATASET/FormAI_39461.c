//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock {
    char symbol[25];
    float current_price;
    int volume;
};

int main() {
    struct Stock *stocks;
    int num_stocks;
    float total_value = 0;

    printf("How many stocks would you like to track? ");
    scanf("%d", &num_stocks);

    stocks = (struct Stock*) malloc(num_stocks * sizeof(struct Stock));

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the symbol for stock %d: ", i+1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the current price for stock %d: ", i+1);
        scanf("%f", &stocks[i].current_price);

        printf("Enter the volume for stock %d: ", i+1);
        scanf("%d", &stocks[i].volume);

        total_value += stocks[i].current_price * stocks[i].volume;
    }

    printf("\nStock Portfolio Summary:\n");
    printf("Symbol\tPrice\tVolume\tValue\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%s\t%.2f\t%d\t%.2f\n", stocks[i].symbol, stocks[i].current_price, stocks[i].volume, stocks[i].current_price * stocks[i].volume);
    }

    printf("Total Portfolio Value: $%.2f\n", total_value);

    free(stocks);

    return 0;
}