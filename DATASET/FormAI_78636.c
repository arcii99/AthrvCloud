//FormAI DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record
{
    int accountNumber;
    char customerName[50];
    float balance;
};

struct Record createRecord(int accountNumber, char customerName[], float balance)
{
    struct Record newRecord;
    newRecord.accountNumber = accountNumber;
    strcpy(newRecord.customerName, customerName);
    newRecord.balance = balance;
    return newRecord;
}

void displayRecord(struct Record record)
{
    printf("Account Number: %d\n", record.accountNumber);
    printf("Customer Name: %s\n", record.customerName);
    printf("Balance: $%.2f\n", record.balance);
}

void deposit(struct Record* record, float amount)
{
    record->balance += amount;
    printf("Deposit successful. New balance: $%.2f\n", record->balance);
}

void withdraw(struct Record* record, float amount)
{
    if (amount > record->balance)
    {
        printf("Withdrawal unsuccessful. Insufficient funds.\n");
    }
    else
    {
        record->balance -= amount;
        printf("Withdrawal successful. New balance: $%.2f\n", record->balance);
    }
}

int main()
{
    // Creating records
    struct Record record1 = createRecord(1001, "John Smith", 5000.00);
    struct Record record2 = createRecord(1002, "Jane Doe", 2500.00);
    
    // Displaying records
    printf("Record 1:\n");
    displayRecord(record1);
    printf("\nRecord 2:\n");
    displayRecord(record2);
    
    // Depositing and Withdrawing
    deposit(&record1, 1500.00);
    withdraw(&record2, 3000.00);
    
    // Displaying updated records
    printf("\nRecord 1 (updated):\n");
    displayRecord(record1);
    printf("\nRecord 2 (updated):\n");
    displayRecord(record2);
    
    return 0;
}