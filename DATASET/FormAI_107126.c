//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_id;
    char account_name[50];
    float balance;
} account_t; // Define the account struct

account_t accounts[100]; // Define an array of accounts

int num_accounts = 0; // Track the number of accounts

void add_account(int account_id, char *account_name) {
    accounts[num_accounts].account_id = account_id;
    strcpy(accounts[num_accounts].account_name, account_name);
    accounts[num_accounts].balance = 0.0;
    num_accounts++;
}

int find_account(int account_id) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_id == account_id) {
            return i;
        }
    }
    return -1;
}

void deposit(int account_id, float amount) {
    int account_index = find_account(account_id);
    if (account_index != -1) {
        accounts[account_index].balance += amount;
        printf("You now have %.2f Nuyen in your account.\n", accounts[account_index].balance);
    } else {
        printf("Error: Account not found.\n");
    }
}

void withdraw(int account_id, float amount) {
    int account_index = find_account(account_id);
    if (account_index != -1) {
        if (amount <= accounts[account_index].balance) {
            accounts[account_index].balance -= amount;
            printf("You now have %.2f Nuyen in your account.\n", accounts[account_index].balance);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Error: Account not found.\n");
    }
}

void transfer(int from_account_id, int to_account_id, float amount) {
    int from_account_index = find_account(from_account_id);
    int to_account_index = find_account(to_account_id);
    if (from_account_index != -1 && to_account_index != -1) {
        if (amount <= accounts[from_account_index].balance) {
            accounts[from_account_index].balance -= amount;
            accounts[to_account_index].balance += amount;
            printf("You now have %.2f Nuyen in your account.\n", accounts[from_account_index].balance);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Error: Account not found.\n");
    }
}

int main() {
    add_account(1234, "Neo");
    add_account(5678, "Trinity");

    int choice, account_id, to_account_id;
    char account_name[50];
    float amount;

    printf("Welcome to the CyberBank.\n");

    do {
        printf("Choose an option:\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account ID: ");
                scanf("%d", &account_id);
                printf("Enter account name: ");
                scanf("%s", account_name);
                add_account(account_id, account_name);
                printf("Account created successfully.\n");
                break;

            case 2:
                printf("Enter account ID: ");
                scanf("%d", &account_id);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_id, amount);
                break;

            case 3:
                printf("Enter account ID: ");
                scanf("%d", &account_id);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_id, amount);
                break;

            case 4:
                printf("Enter account ID to transfer from: ");
                scanf("%d", &account_id);
                printf("Enter account ID to transfer to: ");
                scanf("%d", &to_account_id);
                printf("Enter amount to transfer: ");
                scanf("%f", &amount);
                transfer(account_id, to_account_id, amount);
                break;

            case 5:
                printf("Thank you for using the CyberBank.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}