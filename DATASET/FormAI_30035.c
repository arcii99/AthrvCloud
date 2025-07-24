//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct stock {
    char symbol[10];
    double price;
};

int main(int argc, char **argv) {
    struct stock stocks[5] = {{"AAPL", 135.73}, {"GOOGL", 2351.87}, {"FB", 309.88},
                              {"TSLA", 719.69}, {"AMZN", 3523.76}};
    int option;
    do {
        printf("Enter 1 to view stock prices, 2 to search for a stock symbol, or 3 to quit: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Stock prices:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%s: $%.2lf\n", stocks[i].symbol, stocks[i].price);
                }
                break;
            case 2:
                char symbol[10];
                printf("Enter a stock symbol: ");
                scanf("%s", symbol);
                for (int i = 0; i < 5; i++) {
                    if (strcmp(symbol, stocks[i].symbol) == 0) {
                        printf("%s: $%.2lf\n", stocks[i].symbol, stocks[i].price);
                        break;
                    }
                    if (i == 4) {
                        printf("Error: Symbol not found.\n");
                    }
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid option.\n");
                break;
        }
    } while (option != 3);
    return 0;
}