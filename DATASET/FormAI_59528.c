//FormAI DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[50];
    int acc_num;
    float balance;
};

void create_account(struct account *acc, char *name, int acc_num, float balance) {
    strcpy(acc->name, name);
    acc->acc_num = acc_num;
    acc->balance = balance;
}

void deposit(struct account *acc, float amount) {
    acc->balance += amount;
}

void withdraw(struct account *acc, float amount) {
    if (acc->balance - amount < 0) {
        printf("Warning: Insufficient balance.\n");
    } else {
        acc->balance -= amount;
    }
}

void display(struct account *acc) {
    printf("Account name: %s\n", acc->name);
    printf("Account number: %d\n", acc->acc_num);
    printf("Balance: %.2f\n", acc->balance);
}

int main() {
    struct account acc;
    create_account(&acc, "John Doe", 1234, 500.00);
    deposit(&acc, 50.00);
    withdraw(&acc, 100.00);
    display(&acc);
    return 0;
}