//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define structure for account record
struct account {
    int accountNumber;
    char accountName[50];
    float accountBalance;
};

// Function to update an account record
void updateAccount(struct account *acc, float amount) {
    acc->accountBalance += amount;
}

int main() {
    // Set up array of account records
    struct account accounts[5];

    // Initialize accounts with sample data
    accounts[0].accountNumber = 100;
    strcpy(accounts[0].accountName, "John Smith");
    accounts[0].accountBalance = 1000.0;

    accounts[1].accountNumber = 101;
    strcpy(accounts[1].accountName, "Mary Johnson");
    accounts[1].accountBalance = 2000.0;

    accounts[2].accountNumber = 102;
    strcpy(accounts[2].accountName, "Bob Williams");
    accounts[2].accountBalance = 3000.0;

    accounts[3].accountNumber = 103;
    strcpy(accounts[3].accountName, "Karen Davis");
    accounts[3].accountBalance = 4000.0;

    accounts[4].accountNumber = 104;
    strcpy(accounts[4].accountName, "Tom Wilson");
    accounts[4].accountBalance = 5000.0;

    // Update account balances
    updateAccount(&accounts[0], 500.0);
    updateAccount(&accounts[1], -200.0);

    // Print updated account records
    int i;
    for (i = 0; i < 5; i++) {
        printf("Account number: %d\n", accounts[i].accountNumber);
        printf("Account name: %s\n", accounts[i].accountName);
        printf("Account balance: $%0.2f\n\n", accounts[i].accountBalance);
    }

    return 0;
}