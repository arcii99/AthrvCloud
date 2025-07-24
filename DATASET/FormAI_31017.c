//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50
#define FILENAME "passwords.dat"

//Encryption function using XOR cipher
void encrypt(char *password) {
    int length = strlen(password);
    int key = 0xAB;  //encryption key
    for (int i = 0; i < length; i++) {
        password[i] ^= key;
    }
}

//Decryption function
void decrypt(char *password) {
    encrypt(password); //XOR cipher used for both encryption and decryption
}

//Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int score = 0;
    if (length < 8) { //minimum password length
        return -1;
    }
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        score++; //contains uppercase letters
    }
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
        score++; //contains lowercase letters
    }
    if (strpbrk(password, "0123456789")) {
        score++; //contains numbers
    }
    if (strpbrk(password, "!@#$%^&*()_-+={}[]|\\:;\"'<>,.?/~`")) {
        score++; //contains special characters
    }
    return score;
}

//Function to get a new password from user
void get_new_password(char *password) {
    int score;
    do {
        printf("Enter a new password (at least 8 characters with at least one uppercase letter, one lowercase letter, one number, and one special character): ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = 0; //remove trailing newline character
        score = check_password_strength(password);
        if (score < 4) {
            printf("Password does not meet the requirements. Please try again.\n");
        }
    } while (score < 4);
    encrypt(password); //encrypt the password before storing it
}

//Function to list all saved passwords
void list_passwords(char passwords[][MAX_PASSWORD_LENGTH], int count) {
    printf("You have %d saved passwords:\n", count);
    for (int i = 0; i < count; i++) {
        char password[MAX_PASSWORD_LENGTH];
        strcpy(password, passwords[i]);
        decrypt(password); //decrypt the password for display purposes only
        printf("%d. %s\n", i + 1, password);
    }
    printf("\n");
}

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int count = 0;
    FILE *fp = fopen(FILENAME, "r"); //open the file for reading
    if (fp == NULL) {
        printf("No saved passwords found.\n");
    } else {
        char password[MAX_PASSWORD_LENGTH];
        while (fgets(password, MAX_PASSWORD_LENGTH, fp)) {
            password[strcspn(password, "\n")] = 0; //remove trailing newline character
            strcpy(passwords[count], password);
            count++;
        }
        fclose(fp); //close the file
        printf("Loaded %d saved passwords.\n", count);
    }
    char choice;
    do {
        printf("Enter 'n' to add a new password, 'l' to list existing passwords, or 'q' to quit: ");
        choice = getchar();
        getchar(); //consume newline character
        switch (choice) {
            case 'n':
                if (count < MAX_PASSWORDS) {
                    char password[MAX_PASSWORD_LENGTH];
                    get_new_password(password);
                    strcpy(passwords[count], password);
                    count++;
                    printf("Password saved successfully.\n\n");
                    fp = fopen(FILENAME, "w"); //open the file for writing (overwrite)
                    if (fp != NULL) {
                        for (int i = 0; i < count; i++) {
                            fprintf(fp, "%s\n", passwords[i]); //write passwords to file
                        }
                        fclose(fp); //close the file
                    }
                } else {
                    printf("Maximum number of passwords reached.\n\n");
                }
                break;
            case 'l':
                if (count > 0) {
                    list_passwords(passwords, count);
                } else {
                    printf("No saved passwords.\n\n");
                }
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 'q');
    return 0;
}