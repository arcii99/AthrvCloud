//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define stock struct
typedef struct Stock{
    char name[50];
    float price;
    int volume;
}Stock;

int main(){
    //initialize 3 stocks
    Stock stock1;
    Stock stock2;
    Stock stock3;
    
    //initialize stock information
    strcpy(stock1.name, "AMZN");
    stock1.price = 3270.39;
    stock1.volume = 2458932;

    strcpy(stock2.name, "GOOGL");
    stock2.price = 2507.58;
    stock2.volume = 1148232;

    strcpy(stock3.name, "AAPL");
    stock3.price = 145.52;
    stock3.volume = 3267883;

    //display stock information
    printf("Stock name: %s\nPrice: %.2f\nVolume: %d\n\n", stock1.name, stock1.price, stock1.volume);
    printf("Stock name: %s\nPrice: %.2f\nVolume: %d\n\n", stock2.name, stock2.price, stock2.volume);
    printf("Stock name: %s\nPrice: %.2f\nVolume: %d\n\n", stock3.name, stock3.price, stock3.volume);
    
    //update stock information
    stock1.price = 3297.00;
    stock2.price = 2515.00;
    stock3.price = 149.00;

    //display updated stock information
    printf("Stock name: %s\nPrice: %.2f\nVolume: %d\n\n", stock1.name, stock1.price, stock1.volume);
    printf("Stock name: %s\nPrice: %.2f\nVolume: %d\n\n", stock2.name, stock2.price, stock2.volume);
    printf("Stock name: %s\nPrice: %.2f\nVolume: %d\n\n", stock3.name, stock3.price, stock3.volume);

    return 0;
}