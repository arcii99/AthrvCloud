//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

struct banking_record {
    int account_number;
    char customer_name[50];
    float current_balance;
};

int num_records = 0;
struct banking_record records[MAX_RECORDS];

void add_record(int account_number, char *customer_name, float current_balance) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached!\n");
        return;
    }
    
    records[num_records].account_number = account_number;
    strncpy(records[num_records].customer_name, customer_name, 50);
    records[num_records].current_balance = current_balance;
    num_records++;
}

void print_records() {
    printf("Account Number\tCustomer Name\tCurrent Balance\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t\t%s\t\t$%.2f\n", records[i].account_number, records[i].customer_name, records[i].current_balance);
    }
}

void deposit(int account_number, float amount) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            records[i].current_balance += amount;
            printf("Success! $%.2f deposited into account #%d.\n", amount, account_number);
            return;
        }
    }

    printf("Error: Account #%d not found!\n", account_number);
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            if (records[i].current_balance < amount) {
                printf("Error: Insufficient funds in account #%d!\n", account_number);
            } else {
                records[i].current_balance -= amount;
                printf("Success! $%.2f withdrawn from account #%d.\n", amount, account_number);
            }
            return;
        }
    }

    printf("Error: Account #%d not found!\n", account_number);
}

int main() {
    add_record(123456, "John Smith", 1000.00);
    add_record(789012, "Jane Doe", 500.00);
    add_record(345678, "Bob Johnson", 1500.00);

    deposit(123456, 250.00);
    withdraw(789012, 100.00);
    deposit(345678, 500.00);

    print_records();

    return 0;
}