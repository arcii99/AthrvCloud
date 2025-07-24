//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

struct Stock {
    char symbol[10];
    double price;
    double change;
};

void print_stock(struct Stock s);

int main() {
    struct Stock AAPL = {"AAPL", 134.32, -1.23};
    struct Stock TSLA = {"TSLA", 678.90, 2.34};
    struct Stock GOOG = {"GOOG", 2345.67, 0.00};
    
    print_stock(AAPL);
    print_stock(TSLA);
    print_stock(GOOG);
    
    printf("\nEnter new price for AAPL: ");
    scanf("%lf", &AAPL.price);
    
    printf("\nEnter new change for TSLA: ");
    scanf("%lf", &TSLA.change);
    
    printf("\nEnter new price and change for GOOG (separated by space): ");
    scanf("%lf %lf", &GOOG.price, &GOOG.change);
    
    print_stock(AAPL);
    print_stock(TSLA);
    print_stock(GOOG);
    
    return 0;
}

void print_stock(struct Stock s) {
    printf("%s:\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
    
    if (s.change > 0) {
        printf("Change: +$%.2f\n", s.change);
    } else if (s.change < 0) {
        printf("Change: -$%.2f\n", s.change * -1);
    } else {
        printf("Change: $%.2f\n", s.change);
    }
    printf("\n");
}