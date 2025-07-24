//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_STOCKS 10

struct stock {
    char name[20];
    float current_price;
    float prev_closing_price;
    float percentage_change;
};

int main() {
    struct stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char choice;

    // get the stock details from the user
    do {
        printf("\nEnter the details of stock %d: \n", num_stocks+1);
        printf("Name: ");
        scanf("%s", stocks[num_stocks].name);
        printf("Current Price: ");
        scanf("%f", &stocks[num_stocks].current_price);
        printf("Previous Closing Price: ");
        scanf("%f", &stocks[num_stocks].prev_closing_price);

        // calculate percentage change and store it in the struct
        stocks[num_stocks].percentage_change = ((stocks[num_stocks].current_price - stocks[num_stocks].prev_closing_price) / stocks[num_stocks].prev_closing_price) * 100;

        num_stocks++;

        printf("\nDo you want to enter details of another stock? (y/n): ");
        scanf(" %c", &choice);
    } while (num_stocks < MAX_STOCKS && (choice == 'y' || choice == 'Y'));

    // display the stock details
    printf("\n%-20s %-20s %-20s %-20s\n", "Stock Name", "Current Price", "Prev. Closing Price", "Percentage Change");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-20.2f %-20.2f %-20.2f%%\n", stocks[i].name, stocks[i].current_price, stocks[i].prev_closing_price, stocks[i].percentage_change);
    }

    return 0;
}