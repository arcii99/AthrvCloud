//FormAI DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ACCOUNTS 10

// Define a struct for a customer
typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float balance;
} Customer;

// Define a struct for a bank
typedef struct {
    Customer customers[MAX_RECORDS];
    int customerCount;
} Bank;

// Initialize a bank
void initializeBank(Bank *bank) {
    bank->customerCount = 0;
}

// Add a new customer to the bank
void addCustomer(Bank *bank, int accountNumber, char *name, char *address, float balance) {
    Customer newCustomer;
    newCustomer.accountNumber = accountNumber;
    strcpy(newCustomer.name, name);
    strcpy(newCustomer.address, address);
    newCustomer.balance = balance;
    
    bank->customers[bank->customerCount++] = newCustomer;
}

// Print all customers in the bank
void printCustomers(Bank bank) {
    printf("Account Number\tName\tAddress\tBalance\n");
    for (int i = 0; i < bank.customerCount; i++) {
        printf("%d\t%s\t%s\t$%.2f\n", bank.customers[i].accountNumber, bank.customers[i].name, bank.customers[i].address, bank.customers[i].balance);
    }
}

// Find a customer by account number
Customer *findCustomer(Bank *bank, int accountNumber) {
    for (int i = 0; i < bank->customerCount; i++) {
        if (bank->customers[i].accountNumber == accountNumber) {
            return &bank->customers[i];
        }
    }
    return NULL;
}

// Deposit money into a customer's account
void deposit(Bank *bank, int accountNumber, float amount) {
    Customer *customer = findCustomer(bank, accountNumber);
    if (customer == NULL) {
        printf("Customer not found.\n");
        return;
    }
    customer->balance += amount;
    printf("$%.2f deposited into account %d.\n", amount, accountNumber);
}

// Withdraw money from a customer's account
void withdraw(Bank *bank, int accountNumber, float amount) {
    Customer *customer = findCustomer(bank, accountNumber);
    if (customer == NULL) {
        printf("Customer not found.\n");
        return;
    }
    if (customer->balance - amount < 0) {
        printf("Not enough funds.\n");
        return;
    }
    customer->balance -= amount;
    printf("$%.2f withdrawn from account %d.\n", amount, accountNumber);
}

int main() {
    Bank bank;
    initializeBank(&bank);
    
    addCustomer(&bank, 123, "John Smith", "123 Main St", 1000.00);
    addCustomer(&bank, 456, "Jane Doe", "456 Oak Ave", 500.00);
    
    printCustomers(bank);
    
    deposit(&bank, 123, 100.00);
    withdraw(&bank, 456, 200.00);
    
    printCustomers(bank);
    
    return 0;
}