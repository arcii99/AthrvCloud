//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct stock {
    char name[20];
    int current_price;
    int previous_price;
    int low_price;
    int high_price;
};

void update_stock(struct stock* s) {
    int change = rand() % 11 - 5;
    s->previous_price = s->current_price;
    s->current_price += change;
    if (s->current_price > s->high_price) {
        s->high_price = s->current_price;
    }
    if (s->current_price < s->low_price) {
        s->low_price = s->current_price;
    }
}

void print_stock(struct stock* s) {
    printf("%-10s %10d %10d %10d %10d\n", s->name, s->current_price, s->previous_price, s->low_price, s->high_price);
}

int main() {
    struct stock stocks[5] = {
        {"AAPL", 300, 300, 290, 310},
        {"GOOG", 1200, 1200, 1190, 1220},
        {"AMZN", 2000, 2000, 1990, 2020},
        {"MSFT", 150, 150, 140, 160},
        {"FB", 190, 190, 180, 200}
    };
    srand(time(NULL));
    printf("%-10s %10s %10s %10s %10s\n", "Name", "Current", "Previous", "Low", "High");
    while (1) {
        for (int i = 0; i < 5; i++) {
            update_stock(&stocks[i]);
            print_stock(&stocks[i]);
        }
        printf("\n");
        sleep(1);
    }
    return 0;
}