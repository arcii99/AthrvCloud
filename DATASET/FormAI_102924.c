//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int stock_price = 100;
    int stock_quantity = 10;
    float max_profit = 0.0;
    float current_profit = 0.0;
    float max_possible_loss = 0.0;
    float current_possible_loss = 0.0;

    srand(time(NULL));

    for(int i=0; i<50; i++) {
        int random_number = rand() % 21 - 10;
        stock_price += random_number;

        printf("Day: %d\n", i+1);
        printf("Stock Price: $%d\n", stock_price);

        if(random_number > 0) {
            printf("Market is up!\n");
            current_profit = stock_quantity * random_number;
            printf("You made a profit of $%.2f\n", current_profit);
            if(current_profit > max_profit) {
                max_profit = current_profit;
                printf("Congratulations on breaking your max profit record of $%.2f!\n", max_profit);
            }
        } else if (random_number < 0) {
            printf("Market is down!\n");
            current_possible_loss = stock_quantity * -random_number;
            if(current_possible_loss > max_possible_loss) {
                max_possible_loss = current_possible_loss;
                printf("Be careful! Your max possible loss is now $%.2f\n", max_possible_loss);
            }
        } else {
            printf("Market is stable!\n");
        }
        
        printf("\n");
    }

    printf("Final Stock Price: $%d\n", stock_price);

    if(stock_price >= 100) {
        printf("Congratulations! You have made a profit of $%d\n", (stock_price - 100) * stock_quantity);
        printf("Your maximum possible profit was: $%d\n", max_profit);
    } else {
        printf("Sorry! You have incurred a loss of $%d\n", (100 - stock_price) * stock_quantity);
        printf("Your maximum possible loss was: $%d\n", (int)max_possible_loss);
    }

    return 0;
}