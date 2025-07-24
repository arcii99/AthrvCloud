//FormAI DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#define MAX_CUSTOMERS 100 // maximum number of customers supported
#define MAX_ACCOUNTS 100 // maximum number of accounts per customer supported

// define a structure to represent a bank account
typedef struct {
    int accountNumber;
    float balance;
} Account;

// define a structure to represent a bank customer
typedef struct {
    char name[50];
    int customerID;
    Account accounts[MAX_ACCOUNTS];
    int numAccounts;
} Customer;

// define a structure to represent a bank
typedef struct {
    char bankName[50];
    Customer customers[MAX_CUSTOMERS];
    int numCustomers;
} Bank;

// function prototypes
int getCustomerIndex(Bank *bank, int customerID);
void createCustomer(Bank *bank);
void createAccount(Bank *bank, int customerID);
void deposit(Bank *bank, int customerID, int accountNumber, float amount);
void withdraw(Bank *bank, int customerID, int accountNumber, float amount);
float getBalance(Bank *bank, int customerID, int accountNumber);
void displayCustomers(Bank *bank);
void displayAccounts(Bank *bank, int customerID);

int main() {
    Bank bank;
    bank.numCustomers = 0;
    printf("Welcome to %s Bank\n", bank.bankName);
    int option, customerID, accountNumber;
    float amount;
    do {
        printf("\nMenu\n");
        printf("1. Create Customer\n");
        printf("2. Create Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Display Customers\n");
        printf("6. Display Accounts\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                createCustomer(&bank);
                break;
            case 2:
                printf("Enter customer ID: ");
                scanf("%d", &customerID);
                createAccount(&bank, customerID);
                break;
            case 3:
                printf("Enter customer ID: ");
                scanf("%d", &customerID);
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&bank, customerID, accountNumber, amount);
                break;
            case 4:
                printf("Enter customer ID: ");
                scanf("%d", &customerID);
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&bank, customerID, accountNumber, amount);
                break;
            case 5:
                displayCustomers(&bank);
                break;
            case 6:
                printf("Enter customer ID: ");
                scanf("%d", &customerID);
                displayAccounts(&bank, customerID);
                break;
            case 7:
                printf("Thank you for banking with us!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 7);
    return 0;
}

// function to get index of a customer in the bank's customer array
int getCustomerIndex(Bank *bank, int customerID) {
    for (int i = 0; i < bank->numCustomers; i++) {
        if (bank->customers[i].customerID == customerID) {
            return i;
        }
    }
    return -1; // customer not found
}

// function to create a new customer and add them to the bank's customer array
void createCustomer(Bank *bank) {
    Customer customer;
    printf("Enter name: ");
    scanf("%s", customer.name);
    printf("Enter customer ID: ");
    scanf("%d", &customer.customerID);
    customer.numAccounts = 0;
    bank->customers[bank->numCustomers] = customer;
    bank->numCustomers++;
    printf("Customer created successfully!\n");
}

// function to create a new account for a customer
void createAccount(Bank *bank, int customerID) {
    int index = getCustomerIndex(bank, customerID);
    if (index < 0) {
        printf("Customer not found!\n");
        return;
    }
    Customer *customer = &bank->customers[index];
    if (customer->numAccounts >= MAX_ACCOUNTS) {
        printf("Customer has reached the maximum number of accounts allowed!\n");
        return;
    }
    Account account;
    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);
    account.balance = 0;
    customer->accounts[customer->numAccounts] = account;
    customer->numAccounts++;
    printf("Account created successfully!\n");
}

// function to deposit money into an account
void deposit(Bank *bank, int customerID, int accountNumber, float amount) {
    int index = getCustomerIndex(bank, customerID);
    if (index < 0) {
        printf("Customer not found!\n");
        return;
    }
    Customer *customer = &bank->customers[index];
    for (int i = 0; i < customer->numAccounts; i++) {
        if (customer->accounts[i].accountNumber == accountNumber) {
            customer->accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

// function to withdraw money from an account
void withdraw(Bank *bank, int customerID, int accountNumber, float amount) {
    int index = getCustomerIndex(bank, customerID);
    if (index < 0) {
        printf("Customer not found!\n");
        return;
    }
    Customer *customer = &bank->customers[index];
    for (int i = 0; i < customer->numAccounts; i++) {
        if (customer->accounts[i].accountNumber == accountNumber) {
            if (customer->accounts[i].balance >= amount) {
                customer->accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient balance!\n");
                return;
            }
        }
    }
    printf("Account not found!\n");
}

// function to get the balance of an account
float getBalance(Bank *bank, int customerID, int accountNumber) {
    int index = getCustomerIndex(bank, customerID);
    if (index < 0) {
        printf("Customer not found!\n");
        return -1;
    }
    Customer *customer = &bank->customers[index];
    for (int i = 0; i < customer->numAccounts; i++) {
        if (customer->accounts[i].accountNumber == accountNumber) {
            return customer->accounts[i].balance;
        }
    }
    printf("Account not found!\n");
    return -1;
}

// function to display all customers and their account balances
void displayCustomers(Bank *bank) {
    for (int i = 0; i < bank->numCustomers; i++) {
        Customer customer = bank->customers[i];
        printf("Name: %s\n", customer.name);
        printf("Customer ID: %d\n", customer.customerID);
        printf("Accounts:\n");
        for (int j = 0; j < customer.numAccounts; j++) {
            Account account = customer.accounts[j];
            printf("Account number: %d\tBalance: %.2f\n", account.accountNumber, account.balance);
        }
    }
}

// function to display all accounts of a specific customer
void displayAccounts(Bank *bank, int customerID) {
    int index = getCustomerIndex(bank, customerID);
    if (index < 0) {
        printf("Customer not found!\n");
        return;
    }
    Customer *customer = &bank->customers[index];
    printf("Name: %s\n", customer->name);
    printf("Customer ID: %d\n", customer->customerID);
    printf("Accounts:\n");
    for (int i = 0; i < customer->numAccounts; i++) {
        Account account = customer->accounts[i];
        printf("Account number: %d\tBalance: %.2f\n", account.accountNumber, account.balance);
    }
}