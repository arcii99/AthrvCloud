//FormAI DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LEN 10

typedef struct {
    char name[STOCK_NAME_LEN+1];
    double price;
    double prev_price;
} stock_t;

typedef struct {
    stock_t stocks[MAX_STOCKS];
    int num_stocks;
} stock_tracker_t;

void add_stock(stock_tracker_t* tracker, char* name, double price) {
    if (tracker->num_stocks >= MAX_STOCKS) {
        printf("Tracker full, cannot add more stocks\n");
        return;
    }

    stock_t new_stock;
    strncpy(new_stock.name, name, STOCK_NAME_LEN);
    new_stock.price = price;
    new_stock.prev_price = price;

    tracker->stocks[tracker->num_stocks++] = new_stock;
}

void remove_stock(stock_tracker_t* tracker, char* name) {
    int i, index = -1;

    for (i = 0; i < tracker->num_stocks; i++) {
        if (strcmp(tracker->stocks[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Stock not found in tracker\n");
        return;
    }

    for (i = index; i < tracker->num_stocks - 1; i++) {
        tracker->stocks[i] = tracker->stocks[i+1];
    }

    tracker->num_stocks--;
}

void print_tracker(stock_tracker_t* tracker) {
    int i;

    printf("------- STOCK TRACKER -------\n");

    for (i = 0; i < tracker->num_stocks; i++) {
        printf("%s: %0.2f\n", tracker->stocks[i].name, tracker->stocks[i].price);
    }

    printf("------------------------------\n");
}

void update_prices(stock_tracker_t* tracker) {
    int i;
    double new_price, delta, percent_change;

    srand(time(NULL));

    for (i = 0; i < tracker->num_stocks; i++) {
        delta = (rand() % 10) - 5;
        percent_change = delta / tracker->stocks[i].price;
        new_price = tracker->stocks[i].price + delta;

        tracker->stocks[i].prev_price = tracker->stocks[i].price;
        tracker->stocks[i].price = new_price;

        printf("%s price updated from %0.2f to %0.2f (change: %0.2f, %0.2f%%)\n", 
            tracker->stocks[i].name, tracker->stocks[i].prev_price, 
            tracker->stocks[i].price, delta, percent_change*100);
    }
}

int main() {
    stock_tracker_t tracker;
    tracker.num_stocks = 0;

    add_stock(&tracker, "AAPL", 125.19);
    add_stock(&tracker, "GOOG", 1723.99);
    add_stock(&tracker, "TSLA", 843.03);
    add_stock(&tracker, "AMZN", 3127.47);

    int i;

    for (i = 0; i < 5; i++) {
        printf("Update %d\n", i+1);
        update_prices(&tracker);
        print_tracker(&tracker);
    }

    remove_stock(&tracker, "GOOG");

    printf("GOOG removed from tracker\n");
    print_tracker(&tracker);

    return 0;
}