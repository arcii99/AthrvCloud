//FormAI DATASET v1.0 Category: Password management ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_LENGTH 50 // maximum length of passwords
#define MAX_ENTRIES 5 // maximum number of password entries

void print_header(char *header){
    printf("%s\n", header);
    printf("=================================================\n");
}

int main(){
    char passwords[MAX_ENTRIES][MAX_LENGTH]; // array to store passwords
    char password[MAX_LENGTH]; // temporary variable to store password input
    char password_copy[MAX_LENGTH]; // temporary variable to store copied password
    int i,j;

    // initialize all entries to empty string
    for(i=0; i<MAX_ENTRIES; i++){
        strcpy(passwords[i], "");
    }

    // print welcome message
    print_header("Welcome to the Password Manager!");

    // main loop for user input and menu
    while(1){
        // print menu
        printf("Please choose an option:\n");
        printf("  1. Add password entry\n");
        printf("  2. View all password entries\n");
        printf("  3. Copy a password\n");
        printf("  4. Delete a password entry\n");
        printf("  5. Quit\n");

        // get user input
        char choice[10];
        printf("Choose an option: ");
        fgets(choice, 10, stdin);

        // process user input
        switch(atoi(choice)){
            case 1: // add password entry
                print_header("Add Password Entry");

                // get password input
                printf("Enter a password: ");
                fgets(password, MAX_LENGTH, stdin);

                // remove newline character at end of input
                password[strcspn(password, "\n")] = 0;

                // check password length
                if(strlen(password) > MAX_LENGTH){
                    printf("Error: Password length exceeds maximum length of %d characters.\n", MAX_LENGTH);
                    break;
                }

                // check for empty password
                if(strlen(password) == 0){
                    printf("Error: Password cannot be empty.\n");
                    break;
                }

                // check for existing entry
                for(i=0; i<MAX_ENTRIES; i++){
                    if(strcmp(passwords[i], password) == 0){
                        printf("Error: Password entry already exists.\n");
                        break;
                    }
                }

                // add password to array
                for(i=0; i<MAX_ENTRIES; i++){
                    if(strcmp(passwords[i], "") == 0){
                        strcpy(passwords[i], password);
                        printf("Password added successfully.\n");
                        break;
                    }
                }

                // check if array is full
                if(i == MAX_ENTRIES){
                    printf("Error: Maximum number of entries reached.\n");
                }

                break;
            case 2: // view all password entries
                print_header("View All Password Entries");

                // check if there are any entries
                for(i=0; i<MAX_ENTRIES; i++){
                    if(strcmp(passwords[i], "") != 0){
                        break;
                    }
                }

                // print entries
                if(i != MAX_ENTRIES){
                    printf("Password Entries:\n");
                    for(i=0; i<MAX_ENTRIES; i++){
                        if(strcmp(passwords[i], "") != 0){
                            printf("%d. %s\n", i+1, passwords[i]);
                        }
                    }
                }else{
                    printf("No entries found.\n");
                }

                break;
            case 3: // copy a password
                print_header("Copy a Password");

                // get user input
                printf("Enter the number of the password entry to copy: ");
                fgets(choice, 10, stdin);

                // process user input
                j = atoi(choice) - 1;
                if(j >= 0 && j < MAX_ENTRIES){
                    // check if entry exists
                    if(strcmp(passwords[j], "") != 0){
                        // copy password to temporary variable
                        strcpy(password_copy, passwords[j]);

                        // convert password to uppercase
                        for(i=0; i<strlen(password_copy); i++){
                            password_copy[i] = toupper(password_copy[i]);
                        }

                        // print password
                        printf("Password Copied: %s\n", password_copy);
                    }else{
                        printf("Error: Invalid password entry.\n");
                    }
                }else{
                    printf("Error: Invalid input.\n");
                }

                break;
            case 4: // delete a password entry
                print_header("Delete a Password Entry");

                // get user input
                printf("Enter the number of the password entry to delete: ");
                fgets(choice, 10, stdin);

                // process user input
                j = atoi(choice) - 1;
                if(j >= 0 && j < MAX_ENTRIES){
                    // check if entry exists
                    if(strcmp(passwords[j], "") != 0){
                        // delete entry
                        strcpy(passwords[j], "");
                        printf("Password entry deleted successfully.\n");
                    }else{
                        printf("Error: Invalid password entry.\n");
                    }
                }else{
                    printf("Error: Invalid input.\n");
                }

                break;
            case 5: // quit
                print_header("Goodbye!");
                exit(0);
                break;
            default: // invalid input
                printf("Error: Invalid input.\n");
                break;
        }
    }

    return 0;
}