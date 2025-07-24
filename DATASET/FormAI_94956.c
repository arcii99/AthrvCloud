//FormAI DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stock {
    char name[10];
    int currentPrice;
    int dayHigh;
    int dayLow;
};

void displayStats(struct stock s) {
    printf("\nName: %s\nCurrent Price: %d\nDay High: %d\nDay Low: %d\n", s.name, s.currentPrice, s.dayHigh, s.dayLow);
}

void updatePrice(struct stock *s) {
    int range = s->dayHigh - s->dayLow;
    int fluctuation = rand() % range;
    int increment = rand() % 2 == 0 ? fluctuation : -1 * fluctuation;
    s->currentPrice += increment;
}

int main() {
    srand(time(NULL));
    struct stock stocks[5] = {
        {"Apple", 100, 110, 90},
        {"Microsoft", 150, 170, 130},
        {"Amazon", 2000, 2100, 1800},
        {"Google", 1200, 1250, 1100},
        {"Facebook", 500, 550, 450},
    };
    int i;
    for(i = 0; i < 5; i++) {
        displayStats(stocks[i]);
    }
    for(i = 0; i < 10; i++) {
        printf("\n------------ Day %d ------------\n", i+1);
        int j;
        for(j = 0; j < 5; j++) {
            updatePrice(&stocks[j]);
            displayStats(stocks[j]);
        }
    }
    return 0;
}