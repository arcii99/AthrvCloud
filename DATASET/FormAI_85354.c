//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_PASS_LENGTH 20    // Maximum length of password
#define MAX_PASS_TRIES 3      // Maximum number of attempts to enter password

void change_password(char *password);                         // Function to change the password
int check_password(char *password, int tries_left);           // Function to check if password is correct
void encrypt_password(char *password, char *encrypted_pass);  // Function to encrypt the password

int main() {
    char password[MAX_PASS_LENGTH], input_pass[MAX_PASS_LENGTH], encrypted_pass[MAX_PASS_LENGTH];
    int choice, tries = MAX_PASS_TRIES, password_match;
    FILE *fptr;

    printf("\nWelcome to Password Manager!");
    fptr = fopen("password.txt", "r");
    if(fptr == NULL) {  // If password file is not found, create one and exit program
        printf("\nUnable to find password file.");
        printf("\nCreating new password file...");
        fptr = fopen("password.txt", "w");
        if(fptr == NULL) {
            printf("\nError in creating password file!");
            exit(1);
        }
        printf("\nNew password file created successfully!\nExiting...\n");
        fclose(fptr);
        exit(0);
    } else {    // If password file is found, read password from it
        fgets(encrypted_pass, MAX_PASS_LENGTH, fptr);
        decrypt_password(encrypted_pass, password);
        printf("\nPassword has been loaded from file.");
        fclose(fptr);
    }

    while(tries > 0) {  // Loop for entering password with maximum tries allowed
        printf("\nEnter password: ");
        scanf("%s", input_pass);
        password_match = check_password(input_pass, tries);
        if(password_match == 0) {   // If password is correct
            printf("\nPassword is correct!\n");
            break;
        } else {                    // If password is incorrect
            tries--;
            printf("\nPassword is incorrect! You have %d tries left.\n", tries);
        }
    }
    if(tries == 0) {    // If all tries are used up
        printf("\nMaximum number of attempts reached.\n");
        exit(1);
    }

    while(1) {  // Main menu loop
        printf("\nSelect an option:\n");
        printf("1. Get password\n");
        printf("2. Change password\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {   // Get password option
                char website[50], command[100];
                printf("\nEnter website: ");
                scanf("%s", website);
                sprintf(command, "pass %s", website);   // Format string for executing 'pass' command
                system(command);
                break;
            }
            case 2: {   // Change password option
                change_password(password);
                encrypt_password(password, encrypted_pass);
                fptr = fopen("password.txt", "w");
                fprintf(fptr, "%s", encrypted_pass);
                fclose(fptr);
                printf("\nPassword has been changed and saved to file.\n");
                break;
            }
            case 3:     // Exit option
                exit(0);
            default:    // Invalid option entered
                printf("\nInvalid option selected.\n");
                break;
        }
    }

    return 0;
}

void change_password(char *password) {
    char new_pass[MAX_PASS_LENGTH], confirm_pass[MAX_PASS_LENGTH];
    int pass_match;

    printf("\nEnter new password: ");
    scanf("%s", new_pass);
    printf("\nConfirm new password: ");
    scanf("%s", confirm_pass);

    pass_match = strcmp(new_pass, confirm_pass);
    if(pass_match == 0) {   // If passwords match
        strcpy(password, new_pass);
        printf("\nPassword has been changed!\n");
    } else {                // If passwords do not match
        printf("\nPasswords do not match.\n");
        change_password(password);
    }
}

int check_password(char *password, int tries_left) {
    char check_pass[MAX_PASS_LENGTH];
    int pass_match;

    FILE *fptr = fopen("password.txt", "r");
    fgets(check_pass, MAX_PASS_LENGTH, fptr);  // Read encrypted password from file
    fclose(fptr);
    
    decrypt_password(check_pass, check_pass);  // Decrypt encrypted password

    pass_match = strcmp(check_pass, password);
    if(pass_match == 0) {   // If passwords match
        return 0;
    } else {                // If passwords do not match
        if(tries_left == 1) {
            return 1;
        } else {
            return -1;
        }
    }
}

void encrypt_password(char *password, char *encrypted_pass) {
    int i;
    for(i=0; i<strlen(password); i++) {     // Encrypt password by shifting ASCII value by 3
        encrypted_pass[i] = (char)(((int)password[i] + 3 - 97) % 26 + 97);
    }
    encrypted_pass[i] = '\0';   // Add null terminator to end of string
}

void decrypt_password(char *encrypted_pass, char *password) {
    int i;
    for(i=0; i<strlen(encrypted_pass); i++) {     // Decrypt password by shifting ASCII value by -3
        password[i] = (char)(((int)encrypted_pass[i] - 3 - 97 + 26) % 26 + 97);
    }
    password[i] = '\0';     // Add null terminator to end of string
}