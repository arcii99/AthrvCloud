//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int stocks[10] = {50, 100, 150, 200, 250, 300, 350, 400, 450, 500};
    int stock_prices[10];
    int i, j;

    srand(time(NULL)); //initialize random seed

    //generate initial stock prices
    for(i = 0; i < 10; i++) {
        stock_prices[i] = 1000 + rand() % 4000; //generate random price between 1000 and 5000
    }

    printf("Welcome to the Stock Market Tracker\n");

    //main loop
    while(1) {
        printf("\nCurrent stock prices:\n"); 
        for(i = 0; i < 10; i++) {
            printf("Stock %d: $%d %c", i+1, stock_prices[i], (i == 9 ? '\n' : '|'));
        }

        printf("Which stock would you like to buy or sell? Enter the number (1-10): ");
        scanf("%d", &j);
        if(j >= 1 && j <= 10) {
            printf("Enter 'b' to buy or 's' to sell: ");
            char transaction_type;
            scanf(" %c", &transaction_type);

            if(transaction_type == 'b') { //buy
                int quantity;
                printf("Enter quantity to buy: ");
                scanf("%d", &quantity);

                if(quantity * stocks[j-1] <= 5000 && stock_prices[j-1]*quantity <= 10000) { //check if affordable
                    stock_prices[j-1] += (int)(stock_prices[j-1] * (0.05 * quantity)); //increase stock price
                    printf("Successfully bought %d shares of Stock %d\n", quantity, j);
                } else {
                    printf("Transaction failed: Insufficient funds or limit reached.\n");
                }

            } else if(transaction_type == 's') { //sell
                int quantity;
                printf("Enter quantity to sell: ");
                scanf("%d", &quantity);
                if(quantity <= stocks[j-1]) {
                    stock_prices[j-1] -= (int)(stock_prices[j-1] * (0.05 * quantity)); //decrease stock price
                    printf("Successfully sold %d shares of Stock %d\n", quantity, j);
                } else {
                    printf("Transaction failed: You do not own enough shares.\n");
                }
            } else {
                printf("Invalid transaction type.\n");
            }
        } else {
            printf("Invalid stock number.\n");
        }
    }
    return 0;
}