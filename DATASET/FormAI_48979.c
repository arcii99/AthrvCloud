//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5

struct stock {
    char* name;
    double price;
};

void print_stock(struct stock s) {
    printf("%s: %.2f\n", s.name, s.price);
}

void print_portfolio(struct stock portfolio[NUM_STOCKS]) {
    printf("Portfolio:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        print_stock(portfolio[i]);
    }
}

void update_price(struct stock* s) {
    double change = ((double)rand()/(double)(RAND_MAX)) * 10 - 5; // random price change between -5 and 5
    s->price += change;
}

int main() {
    srand(time(NULL)); // seed random number generator
    
    struct stock stocks[NUM_STOCKS] = {
        {"Apple", 133.50},
        {"Google", 2234.50},
        {"Tesla", 686.44},
        {"Amazon", 3122.44},
        {"Microsoft", 244.42}
    };
    
    print_portfolio(stocks);
    
    for (int i = 0; i < 5; i++) {
        printf("\nDay %d:\n", i+1);
        for (int j = 0; j < NUM_STOCKS; j++) {
            update_price(&stocks[j]);
        }
        print_portfolio(stocks);
    }

    return 0;
}