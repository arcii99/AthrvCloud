//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StockMarket{
    char name[20];
    float currentPrice;
    float openingPrice;
    float closingPrice;
    float high;
    float low;
};

typedef struct StockMarket Stock;

int main(){

    Stock stocks[5];
    strcpy(stocks[0].name, "Apple Inc.");
    stocks[0].currentPrice = 124.97;
    stocks[0].openingPrice = 126.00;
    stocks[0].closingPrice = 124.77;
    stocks[0].high = 127.65;
    stocks[0].low = 123.83;

    strcpy(stocks[1].name, "Microsoft Corporation");
    stocks[1].currentPrice = 245.71;
    stocks[1].openingPrice = 246.11;
    stocks[1].closingPrice = 244.99;
    stocks[1].high = 247.83;
    stocks[1].low = 243.67;

    strcpy(stocks[2].name, "Amazon.com, Inc.");
    stocks[2].currentPrice = 3446.74;
    stocks[2].openingPrice = 3472.90;
    stocks[2].closingPrice = 3426.47;
    stocks[2].high = 3485.25;
    stocks[2].low = 3418.57;

    strcpy(stocks[3].name, "Alphabet Inc.");
    stocks[3].currentPrice = 2317.18;
    stocks[3].openingPrice = 2314.56;
    stocks[3].closingPrice = 2322.12;
    stocks[3].high = 2333.37;
    stocks[3].low = 2305.01;

    strcpy(stocks[4].name, "Facebook, Inc.");
    stocks[4].currentPrice = 317.72;
    stocks[4].openingPrice = 318.13;
    stocks[4].closingPrice = 316.23;
    stocks[4].high = 320.35;
    stocks[4].low = 314.06;

    printf("%-25s  %-10s  %-10s  %-10s  %-10s  %-10s\n", "Company Name", "Current", "Opening", "Closing", "High", "Low");
    for(int i=0; i<5; i++){
        printf("%-25s  $%-9.2f  $%-9.2f  $%-9.2f  $%-9.2f  $%-9.2f\n", stocks[i].name, stocks[i].currentPrice, stocks[i].openingPrice, stocks[i].closingPrice, stocks[i].high, stocks[i].low);
    }
    return 0;
}