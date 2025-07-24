//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_CUSTOMERS 100
#define MAX_TRANSACTIONS 1000

struct Date {
    int day;
    int month;
    int year;
} typedef Date;

struct Transaction {
    Date date;
    double amount;
    char description[100];
} typedef Transaction;

struct Account {
    int number;
    double balance;
    char name[50];
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions;
} typedef Account;

int menu();
void add_customer(Account* customers, int* num_customers);
void display_customers(Account* customers, int num_customers);
void deposit(Account* customers, int num_customers);
void withdraw(Account* customers, int num_customers);
void transfer(Account* customers, int num_customers);
void print_transactions(Account customer);
void search_transactions(Account customer);

int main() {
    // Define variables
    int option, num_customers = 0;
    Account customers[MAX_CUSTOMERS];

    printf("\n\nWelcome to Holmes Bank Record System\n\n");
    printf("------------------------------------\n\n");

    while((option = menu()) != 6) {
        switch(option) {
            case 1:
                add_customer(customers, &num_customers);
                break;
            case 2:
                display_customers(customers, num_customers);
                break;
            case 3:
                deposit(customers, num_customers);
                break;
            case 4:
                withdraw(customers, num_customers);
                break;
            case 5:
                transfer(customers, num_customers);
                break;
            default: printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}

int menu() {
    int option;

    printf("\nPlease choose an option:\n\n");
    printf("1. Add customer\n");
    printf("2. Display all customers\n");
    printf("3. Make a deposit\n");
    printf("4. Make a withdrawal\n");
    printf("5. Transfer funds\n");
    printf("6. Quit\n\n");
    printf("Option: ");
    scanf("%d", &option);

    return option;
}

void add_customer(Account* customers, int* num_customers) {
    if(*num_customers == MAX_CUSTOMERS) {
        printf("\nMaximum number of customers reached. Cannot add any more.\n");
        return;
    }

    Account new_customer;

    printf("\nPlease enter the following information:\n\n");
    printf("Name: ");
    scanf("%s", new_customer.name);
    printf("Account number: ");
    scanf("%d", &new_customer.number);
    printf("Initial deposit: ");
    scanf("%lf", &new_customer.balance);
    new_customer.num_transactions = 0;

    customers[*num_customers] = new_customer;
    (*num_customers)++;

    printf("\nNew customer added successfully!\n");
}

void display_customers(Account* customers, int num_customers) {
    if(num_customers == 0) {
        printf("\nNo customers to display.\n");
        return;
    }

    printf("\nCustomers:\n\n");
    printf("%-20s%-20s%-20s\n", "Name", "Account Number", "Balance");
    printf("----------------------------------------------------------\n");

    for(int i = 0; i < num_customers; i++) {
        printf("%-20s%-20d%-20.2lf\n", customers[i].name, customers[i].number, customers[i].balance);
    }

    printf("\n");
}

void deposit(Account* customers, int num_customers) {
    int account_number, index;
    double amount;

    printf("\nPlease enter the following information:\n\n");
    printf("Account number: ");
    scanf("%d", &account_number);

    // Find customer's index in array
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].number == account_number) {
            index = i;
            break;
        }
        if(i == num_customers - 1) {
            printf("\nCustomer not found.\n");
            return;
        }
    }

    printf("Amount to deposit: ");
    scanf("%lf", &amount);

    printf("Description: ");
    scanf("%s", customers[index].transactions[customers[index].num_transactions].description);

    // Update customer's balance and transactions
    customers[index].balance += amount;
    customers[index].transactions[customers[index].num_transactions].amount = amount;
    customers[index].transactions[customers[index].num_transactions].date = (Date){11, 1, 2022};

    printf("\nDeposit successful!\n");

    customers[index].num_transactions++;
}

void withdraw(Account* customers, int num_customers) {
    int account_number, index;
    double amount;

    printf("\nPlease enter the following information:\n\n");
    printf("Account number: ");
    scanf("%d", &account_number);

    // Find customer's index in array
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].number == account_number) {
            index = i;
            break;
        }
        if(i == num_customers - 1) {
            printf("\nCustomer not found.\n");
            return;
        }
    }

    printf("Amount to withdraw: ");
    scanf("%lf", &amount);

    if(customers[index].balance < amount) {
        printf("\nInsufficient funds.\n");
        return;
    }

    printf("Description: ");
    scanf("%s", customers[index].transactions[customers[index].num_transactions].description);

    // Update customer's balance and transactions
    customers[index].balance -= amount;
    customers[index].transactions[customers[index].num_transactions].amount = -amount;
    customers[index].transactions[customers[index].num_transactions].date = (Date){11, 1, 2022};

    printf("\nWithdrawal successful!\n");

    customers[index].num_transactions++;
}

void transfer(Account* customers, int num_customers) {
    int sender_number, recipient_number, sender_index, recipient_index;
    double amount;

    printf("\nPlease enter the following information:\n\n");
    printf("Sender's account number: ");
    scanf("%d", &sender_number);

    // Find sender's index in array
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].number == sender_number) {
            sender_index = i;
            break;
        }
        if(i == num_customers - 1) {
            printf("\nSender not found.\n");
            return;
        }
    }

    printf("Recipient's account number: ");
    scanf("%d", &recipient_number);

    // Find recipient's index in array
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].number == recipient_number) {
            recipient_index = i;
            break;
        }
        if(i == num_customers - 1) {
            printf("\nRecipient not found.\n");
            return;
        }
    }

    printf("Amount to transfer: ");
    scanf("%lf", &amount);

    if(customers[sender_index].balance < amount) {
        printf("\nInsufficient funds.\n");
        return;
    }

    printf("Description: ");
    scanf("%s", customers[sender_index].transactions[customers[sender_index].num_transactions].description);

    // Update customers' balances and transactions
    customers[sender_index].balance -= amount;
    customers[recipient_index].balance += amount;
    customers[sender_index].transactions[customers[sender_index].num_transactions].amount = -amount;
    customers[recipient_index].transactions[customers[recipient_index].num_transactions].amount = amount;
    customers[sender_index].transactions[customers[sender_index].num_transactions].date = (Date){11, 1, 2022};
    customers[recipient_index].transactions[customers[recipient_index].num_transactions].date = (Date){11, 1, 2022};

    printf("\nTransfer successful!\n");

    customers[sender_index].num_transactions++;
    customers[recipient_index].num_transactions++;
}

void print_transactions(Account customer) {
    if(customer.num_transactions == 0) {
        printf("\nNo transactions to display.\n");
        return;
    }

    printf("\nTransactions for account number %d:\n\n", customer.number);
    printf("%-20s%-20s%-20s\n", "Date", "Description", "Amount");
    printf("----------------------------------------------------------\n");

    for(int i = 0; i < customer.num_transactions; i++) {
        printf("%02d/%02d/%d%20s%20.2lf\n", customer.transactions[i].date.day, customer.transactions[i].date.month, customer.transactions[i].date.year, customer.transactions[i].description, customer.transactions[i].amount);
    }

    printf("\n");
}

void search_transactions(Account customer) {
    char search_string[100];

    printf("\nPlease enter a search string: ");
    scanf("%s", search_string);

    printf("\nTransactions for account number %d containing '%s':\n\n", customer.number, search_string);
    printf("%-20s%-20s%-20s\n", "Date", "Description", "Amount");
    printf("----------------------------------------------------------\n");

    for(int i = 0; i < customer.num_transactions; i++) {
        if(strstr(customer.transactions[i].description, search_string) != NULL) {
            printf("%02d/%02d/%d%20s%20.2lf\n", customer.transactions[i].date.day, customer.transactions[i].date.month, customer.transactions[i].date.year, customer.transactions[i].description, customer.transactions[i].amount);
        }
    }

    printf("\n");
}