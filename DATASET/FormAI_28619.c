//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float balance;
} account;

int main() {
    int num_accounts;
    printf("Enter the number of accounts: ");
    scanf("%d", &num_accounts);
    account *accounts = malloc(num_accounts * sizeof(account));
    if(accounts == NULL) {
        printf("Error: Failed to allocate memory for %d accounts.\n", num_accounts);
        return 1;
    }
    for(int i = 0; i < num_accounts; i++) {
        printf("Enter account id, name, and balance (separated by commas): ");
        scanf("%d, %49[^,], %f", &accounts[i].id, accounts[i].name, &accounts[i].balance);
        getchar();
    }
    FILE *file;
    file = fopen("accounts.txt", "w");
    if(file == NULL) {
        printf("Error: Failed to open file.\n");
        free(accounts);
        return 1;
    }
    for(int i = 0; i < num_accounts; i++) {
        fprintf(file, "%d,%s,%.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
    fclose(file);
    printf("Accounts saved to file.\n");
    free(accounts);
    return 0;
}