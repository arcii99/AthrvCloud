//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_NUMBER_OF_PASSWORDS 10

void print_menu();
void print_dash();
void add_password(char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH]);
void view_passwords(char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH]);
void delete_password(char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH]);

int main() {
    char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH];
    int choice;
    int i, j;
    for(i = 0; i < MAX_NUMBER_OF_PASSWORDS; i++) {
        memset(passwords[i], 0, MAX_PASSWORD_LENGTH);
    }

    print_dash();
    printf("\t\tWelcome to Password Manager!\n");
    print_dash();
    printf("\n");
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                add_password(passwords);
                break;

            case 2:
                view_passwords(passwords);
                break;

            case 3:
                delete_password(passwords);
                break;

            case 4:
                printf("Thank you for using Password Manager! Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");

    } while(choice != 4);

    return 0;
}

void print_menu() {
    printf("1. Add a password\n");
    printf("2. View passwords\n");
    printf("3. Delete a password\n");
    printf("4. Exit\n");
}

void print_dash() {
    int i;
    for(i = 0; i < 50; i++) {
        printf("-");
    }
}

void add_password(char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i;
    i = 0;
    while(passwords[i][0] != 0 && i < MAX_NUMBER_OF_PASSWORDS) {
        i++;
    }

    if(i == MAX_NUMBER_OF_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
    } else {
        printf("Enter the password: ");
        scanf("%s", passwords[i]);
        printf("Password added successfully!\n");
    }
}

void view_passwords(char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i;
    for(i = 0; i < MAX_NUMBER_OF_PASSWORDS; i++) {
        if(passwords[i][0] != 0) {
            printf("Password #%d: %s\n", i+1, passwords[i]);
        }
    }
}

void delete_password(char passwords[MAX_NUMBER_OF_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i, j, num;
    view_passwords(passwords);
    printf("Enter the number of the password to be deleted: ");
    scanf("%d", &num);
    printf("\n");

    if(num > MAX_NUMBER_OF_PASSWORDS || passwords[num-1][0] == 0) {
        printf("Invalid password number. Please try again.\n");
    } else {
        for(i = num-1; i < MAX_NUMBER_OF_PASSWORDS-1; i++) {
            strcpy(passwords[i], passwords[i+1]);
        }
        memset(passwords[MAX_NUMBER_OF_PASSWORDS-1], 0, MAX_PASSWORD_LENGTH);
        printf("Password successfully deleted!\n");
    }
}