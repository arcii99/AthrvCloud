//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <string.h>

struct bank_record {
    char account_number[20];
    char customer_name[40];
    char bank_name[30];
    double balance;
    char date[20];
};

void print_record(struct bank_record *record) {
    printf("Account Number: %s\n", record->account_number);
    printf("Customer Name: %s\n", record->customer_name);
    printf("Bank Name: %s\n", record->bank_name);
    printf("Balance: $%.2f\n", record->balance);
    printf("Last Updated: %s\n", record->date);
    printf("\n");
}

void update_balance(struct bank_record *record, double amount) {
    record->balance += amount;
    printf("New Balance: $%.2f\n", record->balance);
    printf("\n");
}

int main() {
    struct bank_record record1, record2;
    strcpy(record1.account_number, "123456789");
    strcpy(record1.customer_name, "John Doe");
    strcpy(record1.bank_name, "Chase");
    record1.balance = 1000.00;
    strcpy(record1.date, "2022-04-01");

    strcpy(record2.account_number, "987654321");
    strcpy(record2.customer_name, "Jane Smith");
    strcpy(record2.bank_name, "Wells Fargo");
    record2.balance = 5000.00;
    strcpy(record2.date, "2022-04-01");

    printf("Initial Bank Records\n");
    print_record(&record1);
    print_record(&record2);

    printf("Updating bank record 1\n");
    update_balance(&record1, 250.00);
    printf("Updating bank record 2\n");
    update_balance(&record2, -1000.00);

    printf("Updated Bank Records\n");
    print_record(&record1);
    print_record(&record2);

    return 0;
}