//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STOCK_COUNT 10 // Number of stocks to be tracked
#define MAX_PLAYERS 5 // Maximum players in the game
#define MAX_NAME_LENGTH 15 // Maximum length of the player name
#define MAX_STOCK_NAME_LENGTH 10 // Maximum length of the stock name
#define MIN_PRICE_CHANGE -5 // Minimum price change for a stock
#define MAX_PRICE_CHANGE 5 // Maximum price change for a stock

// Function to generate random price change for a given stock
float generate_price_change() {
    return (float)(rand() % (MAX_PRICE_CHANGE - MIN_PRICE_CHANGE + 1) + MIN_PRICE_CHANGE);
}

int main() {
    char stock_names[STOCK_COUNT][MAX_STOCK_NAME_LENGTH] = {"AAPL", "TSLA", "NFLX", "AMZN", "MSFT", "GOOGL", "FB", "NVDA", "INTC", "AMD"}; // Array of stock names
    float stock_prices[STOCK_COUNT] = {100.0, 200.0, 300.0, 400.0, 500.0, 600.0, 700.0, 800.0, 900.0, 1000.0}; // Initial prices of stocks
    int player_count = 0;
    char player_names[MAX_PLAYERS][MAX_NAME_LENGTH]; // Array to store player names
    float player_balance[MAX_PLAYERS] = {10000.0, 10000.0, 10000.0, 10000.0, 10000.0}; // Initial balance of players
    srand(time(NULL));

    printf("STOCK MARKET TRACKER\n");
    printf("--------------------\n");

    // Get names of players
    while (player_count < MAX_PLAYERS) {
        printf("Enter name of Player %d (max %d characters): ", player_count + 1, MAX_NAME_LENGTH);
        fgets(player_names[player_count], MAX_NAME_LENGTH, stdin);
        strtok(player_names[player_count], "\n"); // Remove newline character from the end
        if (strlen(player_names[player_count]) == 0) {
            break;
        }
        player_count++;
    }

    // Game Loop
    while (1) {
        system("clear||cls"); // Clear Screen
        printf("STOCK PRICES\n");
        printf("------------\n");
        for (int i = 0; i < STOCK_COUNT; i++) {
            printf("%s: %.2f\n", stock_names[i], stock_prices[i]);
        }
        printf("\n");

        // Update stock prices
        for (int i = 0; i < STOCK_COUNT; i++) {
            stock_prices[i] += generate_price_change();
        }

        // Display player balances
        printf("PLAYER BALANCES\n");
        printf("---------------\n");
        for (int i = 0; i < player_count; i++) {
            printf("%s: %.2f\n", player_names[i], player_balance[i]);
        }
        printf("\n");

        // Player turn
        for (int i = 0; i < player_count; i++) {
            printf("It's %s's turn. Enter your choice:\n", player_names[i]);
            printf("1. Buy Stocks\n");
            printf("2. Sell Stocks\n");
            printf("3. Skip Turn\n");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                printf("Buy Stocks - Enter stock name and quantity: ");
                char stock_name[MAX_STOCK_NAME_LENGTH];
                int quantity;
                scanf("%s %d", stock_name, &quantity);
                for (int j = 0; j < STOCK_COUNT; j++) {
                    if (strcmp(stock_names[j], stock_name) == 0) {
                        float transaction_cost = stock_prices[j] * quantity;
                        if (transaction_cost > player_balance[i]) {
                            printf("Transaction failed. Not enough balance to buy stocks.\n");
                            break;
                        }
                        player_balance[i] -= transaction_cost;
                        printf("Transaction success. %.2f stocks bought.\n", quantity);
                        break;
                    }
                }
                break;
            case 2:
                printf("Sell Stocks - Enter stock name and quantity: ");
                char stock_name2[MAX_STOCK_NAME_LENGTH];
                int quantity2;
                scanf("%s %d", stock_name2, &quantity2);
                for (int j = 0; j < STOCK_COUNT; j++) {
                    if (strcmp(stock_names[j], stock_name2) == 0) {
                        float transaction_cost = stock_prices[j] * quantity2;
                        if (quantity2 > 0 && quantity2 <= (int)(player_balance[i]/stock_prices[j])) {
                            printf("Transaction success. %.2f stocks sold.\n", quantity2);
                            player_balance[i] += transaction_cost;
                            break;
                        }
                        printf("Transaction failed. Not enough stocks to sell.\n");
                        break;
                    }
                }
                break;
            case 3:
                printf("Turn skipped.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
            }
        }

        // Check if all players have zero balance
        int game_over = 1;
        for (int i = 0; i < player_count; i++) {
            if (player_balance[i] > 0) {
                game_over = 0;
                break;
            }
        }
        if (game_over) {
            printf("GAME OVER!\n");
            break;
        }

        // Wait for player input to continue to the next turn
        printf("\nPress enter to continue to the next turn...\n");
        getchar(); // Consume newline character
        getchar();
    }
    return 0;
}