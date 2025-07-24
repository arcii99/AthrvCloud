//FormAI DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

struct password {
    char account[20];
    char username[20];
    char password[20];
};

void clear_screen() {
    // Function to clear the console screen
    printf("\033[2J\033[H");
}

int main() {
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    while (1) {
        clear_screen();

        printf("Password Manager\n");
        printf("----------------\n");

        printf("Select an option:\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Quit\n");

        char choice[2];
        printf("Enter your choice: ");
        fgets(choice, 2, stdin);

        switch (choice[0]) {
            case '1':
                if (num_passwords == MAX_PASSWORDS) {
                    printf("Error: maximum number of passwords reached.\n");
                    break;
                }

                printf("Account name: ");
                fgets(passwords[num_passwords].account, 20, stdin);

                printf("Username: ");
                fgets(passwords[num_passwords].username, 20, stdin);

                printf("Password: ");
                fgets(passwords[num_passwords].password, 20, stdin);

                printf("Password added successfully.\n");
                num_passwords++;
                break;

            case '2':
                if (num_passwords == 0) {
                    printf("There are no passwords stored.\n");
                    break;
                }

                printf("Account\t\tUsername\t\tPassword\n");
                printf("-------\t\t--------\t\t--------\n");

                for (int i = 0; i < num_passwords; i++) {
                    printf("%s\t\t%s\t\t%s\n", 
                        passwords[i].account, 
                        passwords[i].username, 
                        passwords[i].password);
                }

                break;

            case '3':
                printf("Quitting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\nPress enter to continue...");
        getchar();
    }

    return 0;
}