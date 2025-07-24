//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int account_number;
    char name[50];
    double balance;
} Record;

int num_records = 0;
Record bank_records[MAX_RECORDS];

void add_record(int account_number, char* name, double balance) {
    if (num_records == MAX_RECORDS) {
        printf("Error: Maximum number of records exceeded.\n");
        return;
    }
    
    Record new_record;
    new_record.account_number = account_number;
    strcpy(new_record.name, name);
    new_record.balance = balance;
    
    bank_records[num_records] = new_record;
    num_records++;
}

void print_record(Record record) {
    printf("Account number: %d\n", record.account_number);
    printf("Name: %s\n", record.name);
    printf("Balance: $%.2f\n", record.balance);
}

void print_records() {
    printf("Printing all records...\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        print_record(bank_records[i]);
        printf("\n");
    }
}

void find_record(int account_number) {
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (bank_records[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Record not found.\n");
        return;
    }
    
    print_record(bank_records[index]);
}

void deposit(int account_number, double amount) {
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (bank_records[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Record not found.\n");
        return;
    }
    
    bank_records[index].balance += amount;
    printf("$%.2f deposited into account %d.\n", amount, account_number);
}

void withdraw(int account_number, double amount) {
    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (bank_records[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Record not found.\n");
        return;
    }
    
    if (bank_records[index].balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }
    
    bank_records[index].balance -= amount;
    printf("$%.2f withdrawn from account %d.\n", amount, account_number);
}

int main() {
    add_record(12345, "John Smith", 5000.00);
    add_record(67890, "Jane Doe", 10000.00);
    
    printf("Welcome to the Bank Record System!\n\n");
    
    int choice;
    do {
        printf("What would you like to do?\n\n");
        printf("1. View all records\n");
        printf("2. Find a record\n");
        printf("3. Deposit money\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                print_records();
                break;
            case 2:
                printf("Enter account number: ");
                int account_number;
                scanf("%d", &account_number);
                printf("\n");
                find_record(account_number);
                break;
            case 3:
                printf("Enter account number: ");
                int deposit_account_number;
                scanf("%d", &deposit_account_number);
                printf("Enter amount to deposit: $");
                double deposit_amount;
                scanf("%lf", &deposit_amount);
                printf("\n");
                deposit(deposit_account_number, deposit_amount);
                break;
            case 4:
                printf("Enter account number: ");
                int withdraw_account_number;
                scanf("%d", &withdraw_account_number);
                printf("Enter amount to withdraw: $");
                double withdraw_amount;
                scanf("%lf", &withdraw_amount);
                printf("\n");
                withdraw(withdraw_account_number, withdraw_amount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 5);
    
    return 0;
}