//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double balance;
} account;

void create_account(account *a, int id, char *name, double balance) {
    a->id = id;
    strncpy(a->name, name, MAX_NAME_LEN-1);
    a->balance = balance;
}

void deposit(account *a, double amount) {
    a->balance += amount;
}

void withdraw(account *a, double amount) {
    a->balance -= amount;
}

void display_account(account *a) {
    printf("ID: %d\n", a->id);
    printf("Name: %s\n", a->name);
    printf("Balance: %.2lf\n", a->balance);
}

int main() {
    int choice, id;
    double balance, amount;
    char name[MAX_NAME_LEN];
    account *accounts[10]; // array of pointers to account structs

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display account details\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account ID: ");
                scanf("%d", &id);

                printf("Enter account name: ");
                scanf("%s", name);

                printf("Enter initial balance: ");
                scanf("%lf", &balance);

                account *a = malloc(sizeof(account));
                create_account(a, id, name, balance);

                // find the first available slot in the array of pointers
                int i;
                for (i = 0; i < 10; i++) {
                    if (accounts[i] == NULL) {
                        accounts[i] = a;
                        break;
                    }
                }

                if (i == 10) {
                    printf("Error: maximum number of accounts reached\n");
                    free(a); // free memory allocated for account struct
                } else {
                    printf("Account created successfully\n");
                }

                break;

            case 2:
                printf("Enter account ID: ");
                scanf("%d", &id);

                // find the account with the given ID
                for (i = 0; i < 10; i++) {
                    if (accounts[i] != NULL && accounts[i]->id == id) {
                        break;
                    }
                }

                if (i == 10) {
                    printf("Error: account not found\n");
                } else {
                    printf("Enter deposit amount: ");
                    scanf("%lf", &amount);

                    deposit(accounts[i], amount);

                    printf("Deposit completed successfully\n");
                }

                break;

            case 3:
                printf("Enter account ID: ");
                scanf("%d", &id);

                // find the account with the given ID
                for (i = 0; i < 10; i++) {
                    if (accounts[i] != NULL && accounts[i]->id == id) {
                        break;
                    }
                }

                if (i == 10) {
                    printf("Error: account not found\n");
                } else {
                    printf("Enter withdraw amount: ");
                    scanf("%lf", &amount);

                    if (amount > accounts[i]->balance) {
                        printf("Error: insufficient funds\n");
                    } else {
                        withdraw(accounts[i], amount);
                        printf("Withdrawal completed successfully\n");
                    }
                }

                break;

            case 4:
                printf("Enter account ID: ");
                scanf("%d", &id);

                // find the account with the given ID
                for (i = 0; i < 10; i++) {
                    if (accounts[i] != NULL && accounts[i]->id == id) {
                        break;
                    }
                }

                if (i == 10) {
                    printf("Error: account not found\n");
                } else {
                    display_account(accounts[i]);
                }

                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Error: invalid choice\n");
                break;
        }

        printf("\n");
    }
}