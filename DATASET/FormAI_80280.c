//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to hold the stock information
typedef struct{
    char symbol[10];
    float price;
    int volume;
} Stock;

//function to print the stock information
void printStock(Stock s){
    printf("Symbol: %s\n", s.symbol);
    printf("Price: %.2f\n", s.price);
    printf("Volume: %d\n\n", s.volume);
}

int main(){
    //initialize array of structures to hold the stock information
    Stock stocks[5] = {
        {"AAPL", 146.92, 5436543},
        {"GOOGL", 2517.37, 210523},
        {"MSFT", 284.91, 1289563},
        {"TSLA", 709.67, 3487213},
        {"NVDA", 197.51, 965432}
    };

    //print initial stock information
    printf("Initial Stock Information:\n");
    for(int i=0; i<5; i++){
        printStock(stocks[i]);
    }

    //simulate stock market changes
    srand(1); //initialize random number generator
    for(int i=0; i<5; i++){
        //randomly generate a percentage change in price
        float change = (float)(rand() % 21 - 10) / 100.0;
        //update stock price and volume
        stocks[i].price = stocks[i].price + stocks[i].price * change;
        stocks[i].volume += rand() % 1000001 - 500000;
    }

    //print updated stock information
    printf("Updated Stock Information:\n");
    for(int i=0; i<5; i++){
        printStock(stocks[i]);
    }

    return 0;
}