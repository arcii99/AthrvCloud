//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char stock_name[20];
    float current_price;
    float opening_price;
    float closing_price;
} stock;

void display_stock_info(stock * ptr_stock) {
    printf("\nStock: %s", ptr_stock->stock_name);
    printf("\nCurrent Price: %f", ptr_stock->current_price);
    printf("\nOpening Price: %f", ptr_stock->opening_price);
    printf("\nClosing Price: %f\n", ptr_stock->closing_price);
}

int main() {
    stock stock_market[5];

    // Setting stock data
    strcpy(stock_market[0].stock_name,"Google");
    stock_market[0].current_price=100.75;
    stock_market[0].opening_price=98.50;
    stock_market[0].closing_price=101.20;

    strcpy(stock_market[1].stock_name,"Facebook");
    stock_market[1].current_price=70.80;
    stock_market[1].opening_price=72.30;
    stock_market[1].closing_price=71.40;

    strcpy(stock_market[2].stock_name,"Microsoft");
    stock_market[2].current_price=120.60;
    stock_market[2].opening_price=117.90;
    stock_market[2].closing_price=122.10;

    strcpy(stock_market[3].stock_name,"Apple");
    stock_market[3].current_price=200.50;
    stock_market[3].opening_price=203.40;
    stock_market[3].closing_price=198.80;

    strcpy(stock_market[4].stock_name,"Amazon");
    stock_market[4].current_price=1600.25;
    stock_market[4].opening_price=1598.10;
    stock_market[4].closing_price=1615.70;

    // Displaying stock info using function
    for(int i=0;i<5;i++) display_stock_info(&stock_market[i]);

    return 0;
}