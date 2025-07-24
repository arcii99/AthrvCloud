//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    float balance;
} Account;

int count = 0;

// Initialize database with some records
void init(Account accounts[]) {
    accounts[0] = (Account) {1, "Alice", 1000.0};
    accounts[1] = (Account) {2, "Bob", 500.0};
    count = 2;
}

// Add a new account to the database
void add(Account accounts[], int id, char name[], float balance) {
    if (count >= MAX_RECORDS) {
        printf("Database full!\n");
        return;
    }
    accounts[count++] = (Account) {id, name, balance};
}

// Find an account by ID
Account *find(Account accounts[], int id) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].id == id) {
            return &accounts[i];
        }
    }
    return NULL;
}

// Deposit to an account
void deposit(Account *account, float amount) {
    account->balance += amount;
}

// Output all accounts
void output(Account accounts[]) {
    printf("ID\tName\tBalance\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    Account accounts[MAX_RECORDS];
    init(accounts);
    output(accounts);
    
    // Add a new account and deposit some money
    add(accounts, 3, "Charlie", 100.0);
    Account *account = find(accounts, 3);
    deposit(account, 50.0);
    
    // Output all accounts again
    output(accounts);
    
    return 0;
}