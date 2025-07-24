//FormAI DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int balance;
} customer;

customer customers[10];

int num_customers = 0;

void add_customer(int id, char *name, int balance) {
    customer c;
    c.id = id;
    strcpy(c.name, name);
    c.balance = balance;
    customers[num_customers] = c;
    num_customers++;
}

void deposit(int id, int amount) {
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].id == id) {
            customers[i].balance += amount;
            printf("Deposit successful. New balance is %d\n", customers[i].balance);
            return;
        }
    }
    printf("Invalid customer ID\n");
}

void withdraw(int id, int amount) {
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].id == id) {
            if(customers[i].balance < amount) {
                printf("Insufficient funds\n");
                return;
            }
            customers[i].balance -= amount;
            printf("Withdrawal successful. New balance is %d\n", customers[i].balance);
            return;
        }
    }
    printf("Invalid customer ID\n");
}

void view_balance(int id) {
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].id == id) {
            printf("Current balance is %d\n", customers[i].balance);
            return;
        }
    }
    printf("Invalid customer ID\n");
}

int main() {
    add_customer(1, "Alice", 1000);
    add_customer(2, "Bob", 500);
    add_customer(3, "Charlie", 1500);
    
    deposit(1, 500);
    deposit(2, 1000);
    withdraw(1, 2000);
    view_balance(1);
    view_balance(2);
    view_balance(3);
    
    return 0;
}