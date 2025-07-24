//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of players and transactions
#define MAX_PLAYERS 10
#define MAX_TRANSACTIONS 100

// Define transaction structure
typedef struct {
    int player_index;
    float amount;
} Transaction;

// Define player structure
typedef struct {
    char name[20];
    float balance;
} Player;

// Define global player and transaction arrays
Player players[MAX_PLAYERS];
Transaction transactions[MAX_TRANSACTIONS];

// Define number of players and transactions
int num_players = 0;
int num_transactions = 0;

// Function to add a player to the players array
void add_player(char* name, float balance) {
    strcpy(players[num_players].name, name);
    players[num_players].balance = balance;
    num_players++;
}

// Function to add a transaction to the transactions array
void add_transaction(int player_index, float amount) {
    transactions[num_transactions].player_index = player_index;
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

// Function to print all players and their balances
void print_players() {
    printf("Player\tBalance\n");
    for(int i = 0; i < num_players; i++) {
        printf("%s\t%.2f\n", players[i].name, players[i].balance);
    }
}

// Function to print all transactions
void print_transactions() {
    printf("Player\tAmount\n");
    for(int i = 0; i < num_transactions; i++) {
        printf("%s\t%.2f\n", players[transactions[i].player_index].name, transactions[i].amount);
    }
}

// Main function
int main() {

    // Add some initial players
    add_player("John", 100.00);
    add_player("Jane", 50.00);
    add_player("Bob", 75.00);

    // Print all players
    printf("Initial Players:\n");
    print_players();

    // Add some transactions
    add_transaction(0, -20.00);
    add_transaction(1, 10.00);
    add_transaction(2, -5.00);

    // Print all transactions
    printf("\nTransactions:\n");
    print_transactions();

    // Print updated player balances
    printf("\nUpdated Players:\n");
    print_players();

    return 0;
}