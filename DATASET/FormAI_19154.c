//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <openssl/sha.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

struct password {
    char website[MAX_USERNAME_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct password* next;
};

typedef struct password password_t;

void print_passwords(password_t* head);
void add_password(password_t** head, char website[], char username[], char password[]);
void delete_password(password_t** head, char website[]);
void edit_password(password_t** head, char website[], char new_password[]);
void change_master_password(char* master_password);
void hash_password(char* password, char* hashed_password);

int main() {
    char master_password[MAX_PASSWORD_LENGTH];
    password_t* password_list = NULL;
    int choice;

    printf("Welcome to the Password Manager!\n");
    printf("Please enter your Master Password: ");
    fgets(master_password, MAX_PASSWORD_LENGTH, stdin);
    master_password[strcspn(master_password, "\n")] = '\0';
    hash_password(master_password, master_password);

    do {
        printf("\nPlease choose an option:\n");
        printf("1. View Passwords\n");
        printf("2. Add Password\n");
        printf("3. Delete Password\n");
        printf("4. Edit Password\n");
        printf("5. Change Master Password\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline from input buffer

        switch(choice) {
            case 1:
                print_passwords(password_list);
                break;
            case 2: {
                char website[MAX_USERNAME_LENGTH], username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
                printf("Website: ");
                fgets(website, MAX_USERNAME_LENGTH, stdin);
                website[strcspn(website, "\n")] = '\0';
                printf("Username: ");
                fgets(username, MAX_USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';
                printf("Password: ");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0';
                add_password(&password_list, website, username, password);
                printf("Password added!\n");
                break;
            }
            case 3: {
                char website[MAX_USERNAME_LENGTH];
                printf("Website: ");
                fgets(website, MAX_USERNAME_LENGTH, stdin);
                website[strcspn(website, "\n")] = '\0';
                delete_password(&password_list, website);
                break;
            }
            case 4: {
                char website[MAX_USERNAME_LENGTH], new_password[MAX_PASSWORD_LENGTH];
                printf("Website: ");
                fgets(website, MAX_USERNAME_LENGTH, stdin);
                website[strcspn(website, "\n")] = '\0';
                printf("New Password: ");
                fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
                new_password[strcspn(new_password, "\n")] = '\0';
                edit_password(&password_list, website, new_password);
                break;
            }
            case 5:
                change_master_password(master_password);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}

void print_passwords(password_t* head) {
    if (head == NULL) {
        printf("No passwords to display.\n");
        return;
    }

    password_t* current = head;
    int count = 1;
    printf("Passwords:\n");
    while(current != NULL) {
        printf("%d. Website: %s\tUsername: %s\tPassword: %s\n", count++, current->website, current->username, current->password);
        current = current->next;
    }
}

void add_password(password_t** head, char website[], char username[], char password[]) {
    password_t* new_password = malloc(sizeof(password_t));
    strcpy(new_password->website, website);
    strcpy(new_password->username, username);
    hash_password(password, new_password->password);
    new_password->next = *head;
    *head = new_password;
}

void delete_password(password_t** head, char website[]) {
    if (*head == NULL) {
        printf("No passwords to delete.\n");
        return;
    }

    password_t* current = *head;
    password_t* previous = NULL;
    while(current != NULL) {
        if (strcmp(current->website, website) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Password deleted!\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Password not found.\n");
}

void edit_password(password_t** head, char website[], char new_password[]) {
    if (*head == NULL) {
        printf("No passwords to edit.\n");
        return;
    }

    password_t* current = *head;
    while(current != NULL) {
        if (strcmp(current->website, website) == 0) {
            hash_password(new_password, current->password);
            printf("Password updated!\n");
            return;
        }
        current = current->next;
    }

    printf("Password not found.\n");
}

void change_master_password(char* master_password) {
    char confirm[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    printf("Please enter your new Master Password: ");
    fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
    new_password[strcspn(new_password, "\n")] = '\0';
    printf("Confirm new Master Password: ");
    fgets(confirm, MAX_PASSWORD_LENGTH, stdin);
    confirm[strcspn(confirm, "\n")] = '\0';
    if (strcmp(new_password, confirm) == 0) {
        strcpy(master_password, new_password);
        hash_password(master_password, master_password);
        printf("Master Password changed!\n");
    } else {
        printf("Passwords do not match. Please try again.\n");
    }
}

void hash_password(char* password, char* hashed_password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(password, strlen(password), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashed_password[i] = (char)hash[i];
    }
    hashed_password[SHA256_DIGEST_LENGTH] = '\0';
}