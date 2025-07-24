//FormAI DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STOCKS 5

struct stock{
    char name[20];
    double price;
    int quantity;
};

int main(){
    struct stock stocks[MAX_STOCKS];

    // initializing stock data
    strcpy(stocks[0].name, "Apple Inc.");
    stocks[0].price = 124.81;
    stocks[0].quantity = 1000;

    strcpy(stocks[1].name, "Microsoft Corporation");
    stocks[1].price = 232.04;
    stocks[1].quantity = 500;

    strcpy(stocks[2].name, "Amazon.com Inc.");
    stocks[2].price = 3514.88;
    stocks[2].quantity = 250;

    strcpy(stocks[3].name, "Tesla Inc.");
    stocks[3].price = 818.00;
    stocks[3].quantity = 200;

    strcpy(stocks[4].name, "Nvidia Corporation");
    stocks[4].price = 210.96;
    stocks[4].quantity = 350;

    int choice;
    do{
        //display menu
        printf("\nStock Market Tracker Program\n");
        printf("1. View Stock Prices\n");
        printf("2. Buy Stocks\n");
        printf("3. Sell Stocks\n");
        printf("4. Exit Program\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //display stock prices
                printf("\n\nName\tPrice\tQuantity\n");
                for(int i=0; i<MAX_STOCKS; i++){
                    printf("%s\t%.2lf\t%d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
                }
                break;

            case 2:
                //buy stocks
                printf("\n\nEnter the number of the stock you want to buy: ");
                int stock_number;
                scanf("%d", &stock_number);

                if(stock_number<1 || stock_number>MAX_STOCKS){
                    printf("\n\n Invalid stock number. Please enter a number between 1 and %d", MAX_STOCKS);
                    break;
                }

                stock_number--;
                printf("Enter the quantity of stocks you want to buy: ");
                int quantity_to_buy;
                scanf("%d", &quantity_to_buy);

                if(stocks[stock_number].quantity < quantity_to_buy){
                    printf("\n\nSorry, the stock does not have enough quantity to fulfill your order.");
                    break;
                }

                double total_price = quantity_to_buy * stocks[stock_number].price;
                printf("\n\nTotal price for %d stocks of %s is %.2lf", quantity_to_buy, stocks[stock_number].name, total_price);
                printf("\nDo you want to proceed with the purchase? (y/n): ");
                char buy_or_not[5];
                scanf("%s", buy_or_not);

                if (!strcmp(buy_or_not, "y") || !strcmp(buy_or_not, "Y")) {
                    stocks[stock_number].quantity -= quantity_to_buy;
                    printf("\n\nPurchase complete! Thank you for buying with us.");
                }

                break;

            case 3:
                // sell stocks
                printf("\n\nEnter the number of the stock you want to sell: ");
                int stock_number_sell;
                scanf("%d", &stock_number_sell);

                if(stock_number_sell<1 || stock_number_sell>MAX_STOCKS){
                    printf("\n\n Invalid stock number. Please enter a number between 1 and %d", MAX_STOCKS);
                    break;
                }

                stock_number_sell--;
                printf("Enter the quantity of stocks you want to sell: ");
                int quantity_to_sell;
                scanf("%d", &quantity_to_sell);

                if(quantity_to_sell>stocks[stock_number_sell].quantity){
                    printf("\n\nSorry, you do not have enough stocks to sell.");
                    break;
                }

                double total_sell_price = quantity_to_sell * stocks[stock_number_sell].price;
                printf("\n\nTotal selling price for %d stocks of %s is %.2lf", quantity_to_sell, stocks[stock_number_sell].name, total_sell_price);
                printf("\nDo you want to proceed with the sell? (y/n): ");
                char sell_or_not[5];
                scanf("%s", sell_or_not);

                if(!strcmp(sell_or_not, "y") || !strcmp(sell_or_not, "Y")){
                    stocks[stock_number_sell].quantity -= quantity_to_sell;
                    printf("\n\nSold successfully! Thank you for selling with us.");
                }

                break;

            case 4:
                // exit the program
                printf("\n\nThank you for using our Stock Market Tracker Program!");
                exit(0);
                break;

            default:
                // invalid option
                printf("\n\nInvalid option selected. Please select a valid option.");
                break;
        }
    }while(choice != 4);

    return 0;
}