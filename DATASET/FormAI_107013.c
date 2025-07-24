//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 20 //maximum length of password
#define NUM_ACCOUNTS 3 //number of accounts to manage

struct Account { //structure for each account
    char account_name[MAX_LENGTH];
    char password[MAX_LENGTH];
};

void generate_password(char password[]) { //function to generate a random password
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        password[i] = rand() % 94 + 33; //generates random ASCII character from ! to ~
    }
}

int main() {
    struct Account accounts[NUM_ACCOUNTS]; //array of accounts
    int i, j, option;
    char temp_password[MAX_LENGTH];

    srand(time(NULL)); //seeds random number generator with time

    for (i = 0; i < NUM_ACCOUNTS; i++) { //generates random passwords for each account
        generate_password(accounts[i].password);
    }

    printf("Welcome to the password manager program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1 - View accounts\n");
        printf("2 - Add account\n");
        printf("3 - Change password\n");
        printf("4 - Quit\n");
        scanf("%d", &option);

        switch(option) {
            case 1: //View accounts
                printf("\nAccounts:\n");
                for (i = 0; i < NUM_ACCOUNTS; i++) {
                    printf("%d. %s\n", i+1, accounts[i].account_name);
                }
                break;
            case 2: //Add account
                for (i = 0; i < NUM_ACCOUNTS; i++) {
                    if (accounts[i].account_name[0] == '\0') { //if account slot is empty
                        printf("\nEnter a name for the new account: ");
                        scanf("%s", accounts[i].account_name);
                        generate_password(accounts[i].password);
                        printf("Password for %s: %s\n", accounts[i].account_name, accounts[i].password);
                        break;
                    }
                }
                if (i == NUM_ACCOUNTS) { //if all account slots are full
                    printf("\nCannot add account - maximum number of accounts reached.\n");
                }
                break;
            case 3: //Change password
                printf("\nSelect an account to change password:\n");
                for (i = 0; i < NUM_ACCOUNTS; i++) {
                    printf("%d. %s\n", i+1, accounts[i].account_name);
                }
                scanf("%d", &j);
                if (j < 1 || j > NUM_ACCOUNTS) {
                    printf("\nInvalid account selection.\n");
                    break;
                }
                printf("Enter new password for %s: ", accounts[j-1].account_name);
                scanf("%s", temp_password);
                if (strlen(temp_password) > MAX_LENGTH) {
                    printf("\nPassword must be %d characters or less.\n", MAX_LENGTH);
                    break;
                }
                strcpy(accounts[j-1].password, temp_password);
                printf("Password for %s changed successfully!\n", accounts[j-1].account_name);
                break;
            case 4: //Quit
                break;
            default:
                printf("\nInvalid option selection. Please try again.\n");
        }
    } while (option != 4);

    printf("\nThank you for using the password manager program!\n");

    return 0;
}