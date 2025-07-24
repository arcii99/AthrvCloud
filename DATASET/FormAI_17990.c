//FormAI DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

struct Account {
    char name[50];
    int account_number;
    float balance;
};

int main() {
    /* Declare an array of Accounts with space for 10 accounts */
    struct Account accounts[10];

    /* Request user input for each account's information */
    for (int i = 0; i < 10; i++) {
        printf("Enter name for Account %d: ", i+1);
        fgets(accounts[i].name, 50, stdin);
        printf("Enter account number for Account %d: ", i+1);
        scanf("%d", &accounts[i].account_number);
        printf("Enter balance for Account %d: ", i+1);
        scanf("%f", &accounts[i].balance);

        /* Ignore the newline left by scanf when reading in strings */
        getchar();
    }

    /* Display all accounts */
    printf("\nAll Accounts:\n\n");
    for (int i = 0; i < 10; i++) {
        printf("Account %d:\n", i+1);
        printf("\tName: %s", accounts[i].name);
        printf("\tAccount Number: %d\n", accounts[i].account_number);
        printf("\tBalance: %.2f\n\n", accounts[i].balance);
    }

    return 0;
}