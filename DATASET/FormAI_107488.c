//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct stock {
    char name[50];
    float current_price;
    float daily_change;
};

int main() {
    struct stock stock_list[5];
    strcpy(stock_list[0].name, "Apple Inc.");
    stock_list[0].current_price = 157.00;
    stock_list[0].daily_change = 0.72;

    strcpy(stock_list[1].name, "Microsoft Corp.");
    stock_list[1].current_price = 110.75;
    stock_list[1].daily_change = -1.03;

    strcpy(stock_list[2].name, "Amazon.com Inc.");
    stock_list[2].current_price = 1712.36;
    stock_list[2].daily_change = 2.54;

    strcpy(stock_list[3].name, "Google LLC");
    stock_list[3].current_price = 1179.79;
    stock_list[3].daily_change = 1.91;

    strcpy(stock_list[4].name, "Facebook Inc.");
    stock_list[4].current_price = 133.39;
    stock_list[4].daily_change = 3.21;

    srand(time(NULL));
    int random_index = rand() % 5;

    printf("Today's featured stock: %s\n", stock_list[random_index].name);
    printf("Current price: %.2f\n", stock_list[random_index].current_price);
    printf("Daily change: %.2f%%\n", stock_list[random_index].daily_change);

    float average_price = 0.0;
    float highest_price = 0.0;
    float lowest_price = stock_list[0].current_price;
    int highest_index = 0;
    int lowest_index = 0;

    printf("\n\nStock list:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, stock_list[i].name);
        printf("Current price: %.2f\n", stock_list[i].current_price);
        printf("Daily change: %.2f%%\n", stock_list[i].daily_change);

        average_price += stock_list[i].current_price;

        if(stock_list[i].current_price > highest_price){
            highest_price = stock_list[i].current_price;
            highest_index = i;
        }

        if(stock_list[i].current_price < lowest_price){
            lowest_price = stock_list[i].current_price;
            lowest_index = i;
        }
    }

    average_price /= 5;

    printf("\n\nAverage stock price: %.2f\n", average_price);
    printf("Highest price: %.2f for %s\n", highest_price, stock_list[highest_index].name);
    printf("Lowest price: %.2f for %s\n", lowest_price, stock_list[lowest_index].name);

    return 0;
}