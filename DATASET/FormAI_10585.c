//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stock{
    char name[20];
    float price;
    float previous_price;
};

typedef struct stock Stock;

void print_stock_info(Stock* stock){
    printf("%s\t$%.2f\t", stock->name, stock->price);
    if(stock->price > stock->previous_price){
        printf("+%.2f%%\n", ((stock->price - stock->previous_price)/stock->previous_price)*100);
    } else if(stock->price < stock->previous_price){
        printf("%.2f%%\n", ((stock->price - stock->previous_price)/stock->previous_price)*100);
    } else {
        printf("0.00%%\n");
    }
}

int main(){
    srand(time(NULL));
    Stock stocks[5];
    strcpy(stocks[0].name, "AAPL");
    strcpy(stocks[1].name, "GOOG");
    strcpy(stocks[2].name, "FB");
    strcpy(stocks[3].name, "TSLA");
    strcpy(stocks[4].name, "AMZN");

    for(int i=0; i<5; i++){
        stocks[i].price = ((float)rand()/(float)(RAND_MAX)) * 1000;
        stocks[i].previous_price = stocks[i].price - ((float)rand()/(float)(RAND_MAX)) * 100;
    }

    printf("Stock Name\tPrice\t\tChange\n");
    printf("----------------------------------------\n");
    for(int i=0; i<5; i++){
        print_stock_info(&stocks[i]);
    }

    return 0;
}