//FormAI DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct bank_record {
    int account_number;
    char name[50];
    float balance;
};

void print_record(struct bank_record record);
void print_records(struct bank_record records[], int num_records);
void deposit(struct bank_record *record, float amount);
void withdraw(struct bank_record *record, float amount);

int main() {
    struct bank_record records[10]; // Maximum of 10 records
    
    // Add first record
    records[0].account_number = 1001;
    strcpy(records[0].name, "John Smith");
    records[0].balance = 500.0;

    // Add second record
    records[1].account_number = 1002;
    strcpy(records[1].name, "Jane Doe");
    records[1].balance = 1000.0;

    // Print all records
    printf("All records:\n");
    print_records(records, 2);

    // Deposit $100 into John Smith's account
    deposit(&records[0], 100.0);
    printf("John Smith's record after deposit:\n");
    print_record(records[0]);

    // Withdraw $200 from Jane Doe's account
    withdraw(&records[1], 200.0);
    printf("Jane Doe's record after withdrawal:\n");
    print_record(records[1]);

    return 0;
}

void print_record(struct bank_record record) {
    printf("Account number: %d\n", record.account_number);
    printf("Name: %s\n", record.name);
    printf("Balance: $%.2f\n", record.balance);
}

void print_records(struct bank_record records[], int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i+1);
        print_record(records[i]);
    }
}

void deposit(struct bank_record *record, float amount) {
    record->balance += amount;
}

void withdraw(struct bank_record *record, float amount) {
    if (amount > record->balance) {
        printf("Error: Insufficient funds.\n");
    } else {
        record->balance -= amount;
    }
}