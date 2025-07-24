//FormAI DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator
    int stocks[10];
    int gold = 1000;
    int day = 1;
    int sellPrice, buyPrice;
    
    // randomly generate starting prices for stocks between 50 and 200 gold coins
    for (int i = 0; i < 10; i++) {
        stocks[i] = rand() % 151 + 50;
    }
    
    while (gold > 0) {
        printf("*** Day %d ***\n\n", day);
        printf("Available gold: %d\n", gold);
        printf("Current stock prices:\n");
        
        // print out current stock prices
        for (int i = 1; i <= 10; i++) {
            printf("%d. Stock %d: %d gold coins\n", i, i, stocks[i-1]);
        }
        
        // randomly generate new prices for each stock
        for (int i = 0; i < 10; i++) {
            stocks[i] += rand() % 31 - 15;
            if (stocks[i] < 50) { // minimum stock price is 50 gold coins
                stocks[i] = 50;
            }
        }
        
        printf("\nEnter a stock number to buy or sell (0 to end day): ");
        int stockNumber;
        scanf("%d", &stockNumber);
        
        if (stockNumber == 0) { // end day
            day++;
            continue;
        } else if (stockNumber < 1 || stockNumber > 10) { // invalid stock number
            printf("Invalid input.\n");
            continue;
        }
        
        printf("\nEnter 1 to buy or 2 to sell: ");
        int buyOrSell;
        scanf("%d", &buyOrSell);
        
        printf("\nEnter the amount of shares to buy/sell: ");
        int shares;
        scanf("%d", &shares);
        
        if (buyOrSell == 1 && gold < stocks[stockNumber-1] * shares) { // user does not have sufficient gold to buy
            printf("Insufficient gold.\n");
            continue;
        } else if (buyOrSell == 2 && shares > stocks[stockNumber-1]) { // user does not have sufficient shares to sell
            printf("Insufficient shares.\n");
            continue;
        }
        
        if (buyOrSell == 1) { // buy
            buyPrice = stocks[stockNumber-1] * shares;
            gold -= buyPrice;
            printf("You have bought %d shares of Stock %d for %d gold coins.\n", shares, stockNumber, buyPrice);
        } else { // sell
            sellPrice = stocks[stockNumber-1] * shares;
            gold += sellPrice;
            printf("You have sold %d shares of Stock %d for %d gold coins.\n", shares, stockNumber, sellPrice);
        }
        
        // update stock price
        stocks[stockNumber-1] += (buyOrSell == 1) ? stocks[stockNumber-1] / 2 : -(stocks[stockNumber-1] / 2);
        
        printf("\nEnter any key to continue.\n");
        getchar(); // clear input buffer
        getchar(); // wait for user to press enter
        day++;
    }
    
    printf("\nYou have run out of gold. Game Over.\n");
    
    return 0;
}