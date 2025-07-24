//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_LENGTH 25

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char choice;
    while(1) {
        printf("Password Management System\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        scanf(" %c", &choice);

        switch(choice) {
            case '1': {
                printf("\nAdd Password\n");
                printf("Enter website: ");
                scanf(" %s", passwords[numPasswords].website);
                printf("Enter username: ");
                scanf(" %s", passwords[numPasswords].username);
                printf("Enter password: ");
                scanf(" %s", passwords[numPasswords].password);
                numPasswords++;
                break;
            }
            case '2': {
                printf("\nView Passwords\n");
                printf("Website\tUsername\tPassword\n");
                for(int i = 0; i < numPasswords; i++) {
                    printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                }
                break;
            }
            case '3': {
                printf("\nExiting...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }

    return 0;
}