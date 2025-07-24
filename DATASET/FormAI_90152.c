//FormAI DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct Record {
    int account_num;
    double balance;
};

struct Bank {
    struct Record records[MAX_RECORDS];
    int num_records;
};

void add_record(struct Bank *bank, struct Record record) {
    if (bank->num_records == MAX_RECORDS) {
        printf("Error: Bank is full. Cannot add more records.\n");
        return;
    }
    
    bank->records[bank->num_records] = record;
    bank->num_records++;
}

struct Record find_record(struct Bank bank, int account_num) {
    for (int i = 0; i < bank.num_records; i++) {
        if (bank.records[i].account_num == account_num) {
            return bank.records[i];
        }
    }
    
    printf("Error: Record not found.\n");
    struct Record empty_record = {0, 0};
    return empty_record;
}

void display_records(struct Bank bank) {
    for (int i = 0; i < bank.num_records; i++) {
        printf("Account Number: %d\n", bank.records[i].account_num);
        printf("Balance: %.2f\n\n", bank.records[i].balance);
    }
}

double get_balance(struct Bank bank, int account_num) {
    struct Record record = find_record(bank, account_num);
    return record.balance;
}

void deposit(struct Bank *bank, int account_num, double amount) {
    struct Record record = find_record(*bank, account_num);
    record.balance += amount;
}

void withdraw(struct Bank *bank, int account_num, double amount) {
    struct Record record = find_record(*bank, account_num);
    if (record.balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }
    
    record.balance -= amount;
}

int main() {
    struct Bank bank = {0};
    
    add_record(&bank, (struct Record) {1001, 1000});
    add_record(&bank, (struct Record) {1002, 500});
    add_record(&bank, (struct Record) {1003, 2000});
    
    display_records(bank);
    
    printf("Balance of account 1001: %.2f\n", get_balance(bank, 1001));
    
    deposit(&bank, 1002, 250);
    withdraw(&bank, 1003, 1000);
    
    display_records(bank);
    
    return 0;
}