//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_PLAYERS 100
#define MAX_NAME_LENGTH 20

// Define a struct for storing banking records
typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    double balance;
} banking_record_t;

// Declare a global array to store banking records
banking_record_t banking_records[MAX_NUM_PLAYERS];

// Declare a function to add a new banking record to the array
void add_banking_record(int account_number, char* name, double balance) {
    int i = 0;
    while (banking_records[i].account_number != 0 && i < MAX_NUM_PLAYERS) {
        i++;
    }
    if (i >= MAX_NUM_PLAYERS) {
        printf("Error: maximum number of players reached");
        return;
    }
    banking_records[i].account_number = account_number;
    strcpy(banking_records[i].name, name);
    banking_records[i].balance = balance;
    printf("New banking record added\n");
}

// Declare a function to print the banking records of a specific player
void print_banking_record(int account_number) {
    int i = 0;
    while (banking_records[i].account_number != account_number && i < MAX_NUM_PLAYERS) {
        i++;
    }
    if (i >= MAX_NUM_PLAYERS) {
        printf("Error: player not found");
        return;
    }
    printf("Account number: %d\n", banking_records[i].account_number);
    printf("Name: %s\n", banking_records[i].name);
    printf("Balance: %.2f\n", banking_records[i].balance);
}

int main() {
    // Initialize the banking_records array
    memset(banking_records, 0, sizeof(banking_record_t) * MAX_NUM_PLAYERS);

    // Test the add_banking_record function
    add_banking_record(1, "Alice", 100.00);
    add_banking_record(2, "Bob", 200.00);
    add_banking_record(3, "Charlie", 300.00);

    // Test the print_banking_record function
    print_banking_record(1);
    print_banking_record(2);
    print_banking_record(3);

    return 0;
}