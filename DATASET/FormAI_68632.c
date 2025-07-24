//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

struct account {
    int acc_num;
    char name[MAX_NAME_LENGTH];
    float balance;
};

struct account accounts[MAX_ACCOUNTS];

int num_accounts = 0;

// function to add a new account
void add_account(int acc_num, char* name, float balance) {
    if(num_accounts < MAX_ACCOUNTS) {
        accounts[num_accounts].acc_num = acc_num;
        strcpy(accounts[num_accounts].name, name);
        accounts[num_accounts].balance = balance;
        num_accounts++;
    }
}

// function to print all accounts
void print_accounts() {
    printf("\n");
    printf("Account Number\tName\tBalance\n");
    for(int i=0; i<num_accounts; i++) {
        printf("%d\t\t%s\t%.2f\n", accounts[i].acc_num, accounts[i].name, accounts[i].balance);
    }
    printf("\n");
}

int main() {
    
    add_account(1001, "John Doe", 5000.0);
    add_account(1002, "Jane Doe", 7000.0);
    add_account(1003, "Mark Smith", 3000.0);
    
    print_accounts();
    
    return 0;
}