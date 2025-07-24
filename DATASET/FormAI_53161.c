//FormAI DATASET v1.0 Category: Banking Record System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CUSTOMERS 1000

struct Account {
    int customerNumber;
    double balance;
};

struct Customer {
    char name[50];
    struct Account accounts[5];
    int numberOfAccounts;
};

struct Bank {
    struct Customer customers[MAX_CUSTOMERS];
    int numberOfCustomers;
};

void initializeBank(struct Bank *bank);

void addCustomer(struct Bank *bank, char *name, double initialBalance);

void addAccount(struct Customer *customer, double initialBalance);

struct Customer *findCustomer(struct Bank *bank, int customerNumber);

struct Account *findAccount(struct Customer *customer, int accountNumber);

void deposit(struct Bank *bank, int customerNumber, int accountNumber, double amount);

void withdraw(struct Bank *bank, int customerNumber, int accountNumber, double amount);

void printCustomerInformation(struct Customer *customer);

void printAccountDetails(struct Account *account);

int main(void) {
    struct Bank bank;
    initializeBank(&bank);
    
    addCustomer(&bank, "John Doe", 5000.00);
    addAccount(&bank.customers[0], 2000.00);
    addCustomer(&bank, "Jane Doe", 10000.00);
    addAccount(&bank.customers[1], 5000.00);
    addAccount(&bank.customers[1], 7500.00);
    
    deposit(&bank, 1, 0, 2500.00);
    withdraw(&bank, 2, 0, 1500.00);
    
    struct Customer *customer = findCustomer(&bank, 1);
    printCustomerInformation(customer);
    
    struct Account *account = findAccount(customer, 0);
    printAccountDetails(account);
    
    return 0;
}

void initializeBank(struct Bank *bank) {
    bank->numberOfCustomers = 0;
}

void addCustomer(struct Bank *bank, char *name, double initialBalance) {
    if (bank->numberOfCustomers == MAX_CUSTOMERS) {
        printf("Error: Maximum number of customers reached.\n");
        return;
    }
    
    struct Customer customer;
    strncpy(customer.name, name, 49);
    customer.name[49] = '\0';
    addAccount(&customer, initialBalance);
    customer.numberOfAccounts = 1;
    customer.accounts[0].customerNumber = bank->numberOfCustomers;
    bank->customers[bank->numberOfCustomers++] = customer;
}

void addAccount(struct Customer *customer, double initialBalance) {
    if (customer->numberOfAccounts == 5) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }
    
    struct Account account;
    account.balance = initialBalance;
    account.customerNumber = customer->numberOfAccounts;
    customer->accounts[customer->numberOfAccounts++] = account;
}

struct Customer *findCustomer(struct Bank *bank, int customerNumber) {
    for (int i = 0; i < bank->numberOfCustomers; i++) {
        if (bank->customers[i].accounts[0].customerNumber == customerNumber) {
            return &(bank->customers[i]);
        }
    }
    printf("Error: Customer not found.\n");
    return NULL;
}

struct Account *findAccount(struct Customer *customer, int accountNumber) {
    for (int i = 0; i < customer->numberOfAccounts; i++) {
        if (customer->accounts[i].customerNumber == accountNumber) {
            return &(customer->accounts[i]);
        }
    }
    printf("Error: Account not found.\n");
    return NULL;
}

void deposit(struct Bank *bank, int customerNumber, int accountNumber, double amount) {
    struct Customer *customer = findCustomer(bank, customerNumber);
    if (customer == NULL) {
        return;
    }
    
    struct Account *account = findAccount(customer, accountNumber);
    if (account == NULL) {
        return;
    }
    
    account->balance += amount;
}

void withdraw(struct Bank *bank, int customerNumber, int accountNumber, double amount) {
    struct Customer *customer = findCustomer(bank, customerNumber);
    if (customer == NULL) {
        return;
    }
    
    struct Account *account = findAccount(customer, accountNumber);
    if (account == NULL) {
        return;
    }
    
    if (account->balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }
    
    account->balance -= amount;
}

void printCustomerInformation(struct Customer *customer) {
    printf("Name: %s\n", customer->name);
    printf("Number of accounts: %d\n", customer->numberOfAccounts);
    for (int i = 0; i < customer->numberOfAccounts; i++) {
        printf("  ");
        printAccountDetails(&(customer->accounts[i]));
    }
}

void printAccountDetails(struct Account *account) {
    printf("Account number: %d\n", account->customerNumber);
    printf("Balance: $%.2f\n", account->balance);
}