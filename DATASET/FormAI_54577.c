//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_NAME_LEN 20

typedef struct Record {
    char name[MAX_NAME_LEN];
    double amount;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char *name, double amount) {
    // Check if we've reached the maximum number of records
    if (num_records >= MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }
    
    // Create the new record
    Record new_record;
    strncpy(new_record.name, name, MAX_NAME_LEN - 1);
    new_record.amount = amount;
    
    // Add the new record to the list
    records[num_records++] = new_record;
    
    printf("Record added: %s $%.2f\n", new_record.name, new_record.amount);
}

double calculate_total() {
    double total = 0.0;
    
    // Loop through all the records and add up the amounts
    for (int i = 0; i < num_records; i++) {
        total += records[i].amount;
    }
    
    return total;
}

void print_records() {
    printf("Records:\n");
    
    // Loop through all the records and print them out
    for (int i = 0; i < num_records; i++) {
        printf("  %s $%.2f\n", records[i].name, records[i].amount);
    }
}

int main() {
    // Add some test records
    add_record("Groceries", 55.25);
    add_record("Gas", 23.50);
    add_record("Movie tickets", 21.75);
    
    // Print out the total
    double total = calculate_total();
    printf("Total: $%.2f\n", total);
    
    // Print out all the records
    print_records();
    
    return 0;
}