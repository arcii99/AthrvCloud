//FormAI DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char stock_name[50];
    float price;
} Stock;

void print_stock(Stock s) {
    printf("Stock Name: %s\nPrice: %.2f\n", s.stock_name, s.price);
}

int main() {
    Stock google = {"Google", 1500.25};
    Stock apple = {"Apple", 250.75};
    Stock microsoft = {"Microsoft", 175.50};

    // random seed for randomizing prices
    srand(time(NULL)); 

    printf("Initial Prices:\n");
    print_stock(google);
    print_stock(apple);
    print_stock(microsoft);
    printf("\n");

    // set up for actual stock market simulation
    int num_days = 30;
    float volatility = 0.05; // 5% volatility per day
    float google_change, apple_change, microsoft_change;

    for (int i = 1; i <= num_days; i++) {
        printf("Day %d:\n", i);

        google_change = google.price * (float)rand()/(float)(RAND_MAX/ volatility); // randomize change in price
        google.price += google_change;

        apple_change = apple.price * (float)rand()/(float)(RAND_MAX/ volatility); // randomize change in price
        apple.price += apple_change;

        microsoft_change = microsoft.price * (float)rand()/(float)(RAND_MAX/ volatility); // randomize change in price
        microsoft.price += microsoft_change;

        printf("Google:\n");
        print_stock(google);
        printf("Change: %.2f (%.2f%%)\n", google_change, (google_change/google.price)*100);

        printf("Apple:\n");
        print_stock(apple);
        printf("Change: %.2f (%.2f%%)\n", apple_change, (apple_change/apple.price)*100);

        printf("Microsoft:\n");
        print_stock(microsoft);
        printf("Change: %.2f (%.2f%%)\n", microsoft_change, (microsoft_change/microsoft.price)*100);

        printf("\n");
    }

    return 0;
}