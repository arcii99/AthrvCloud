//FormAI DATASET v1.0 Category: Stock market tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int gold = 1000;
    int current_stock_value = 100;
    int current_demand = 100;
    int current_supply = 100;
    int stock_history[30];
    char choice;
    int i, j;

    for (i = 0; i < 30; i++) {
        stock_history[i] = current_stock_value;
    }

    printf("Welcome to the medieval stock market tracker! Here is your starting gold: %d\n\n", gold);

    while (gold > 0) {
        printf("Current stock value: %d\n", current_stock_value);
        printf("Current supply: %d\n", current_supply);
        printf("Current demand: %d\n\n", current_demand);

        printf("What would you like to do?\n");
        printf("1. Buy stock\n");
        printf("2. Sell stock\n");
        printf("3. Wait for the market to change\n");
        printf("4. Quit\n");

        fflush(stdin);
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("How much stock would you like to buy?\n");
                int purchase_amount;
                scanf("%d", &purchase_amount);

                int total_price = current_stock_value * purchase_amount;
                if (total_price > gold) {
                    printf("You do not have enough gold to make that purchase. Try buying a smaller amount.\n");
                } else {
                    gold -= total_price;
                    current_supply += purchase_amount;
                    printf("You have successfully purchased %d stocks. Your remaining gold is now %d.\n", purchase_amount, gold);
                }
                break;
            case '2':
                printf("How much stock would you like to sell?\n");
                int sell_amount;
                scanf("%d", &sell_amount);

                if (sell_amount > current_supply) {
                    printf("You do not have that much stock to sell. Try entering a smaller amount.\n");
                } else {
                    int profit = current_stock_value * sell_amount;
                    gold += profit;
                    current_supply -= sell_amount;
                    printf("You have successfully sold %d stocks for a profit of %d gold. Your total gold is now %d.\n", sell_amount, profit, gold);
                }
                break;
            case '3':
                // simulate market change
                int demand_change = rand() % 21 - 10;
                int supply_change = rand() % 21 - 10;

                current_demand += demand_change;
                if (current_demand < 0) {
                    current_demand = 0;
                }
                current_supply += supply_change;
                if (current_supply < 0) {
                    current_supply = 0;
                }

                int stock_change = current_demand - current_supply;
                current_stock_value += stock_change;
                if (current_stock_value < 0) {
                    current_stock_value = 0;
                }

                for (j = 0; j < 29; j++) {
                    stock_history[j] = stock_history[j+1];
                }
                stock_history[29] = current_stock_value;

                printf("The market has changed!\n");
                printf("New stock value: %d\n", current_stock_value);
                printf("New supply: %d\n", current_supply);
                printf("New demand: %d\n", current_demand);
                break;
            case '4':
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }

        // display stock history
        printf("\nStock history:\n");
        for (j = 0; j < 30; j++) {
            printf("%d ", stock_history[j]);
        }
        printf("\n\n");
    }

    printf("You have run out of gold! Game over.\n");
    return 0;
}