//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef struct Node {
    char web_address[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    struct Node* next;
} Node;

Node* head = NULL;
char master_password[MAX_LENGTH];

void encrypt(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] + 1;
    }
}

void decrypt(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] - 1;
    }
}

void add_password() {
    printf("Enter web address: ");
    char web_address[MAX_LENGTH];
    fgets(web_address, MAX_LENGTH, stdin);
    web_address[strcspn(web_address, "\n")] = 0;

    printf("Enter username: ");
    char username[MAX_LENGTH];
    fgets(username, MAX_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    char password[MAX_LENGTH];
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;
    encrypt(password);

    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->web_address, web_address);
    strcpy(new_node->username, username);
    strcpy(new_node->password, password);
    new_node->next = head;
    head = new_node;

    printf("Password has been successfully added!\n\n");
}

void view_passwords() {
    if (head == NULL) {
        printf("No passwords added yet.\n\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("Web address: %s\n", current->web_address);
        printf("Username: %s\n", current->username);
        char password[MAX_LENGTH];
        strcpy(password, current->password);
        decrypt(password);
        printf("Password: %s\n\n", password);
        current = current->next;
    }
}

void delete_password() {
    if (head == NULL) {
        printf("No passwords added yet.\n\n");
        return;
    }

    printf("Enter web address of password to be deleted: ");
    char web_address[MAX_LENGTH];
    fgets(web_address, MAX_LENGTH, stdin);
    web_address[strcspn(web_address, "\n")] = 0;

    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->web_address, web_address) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Password has been successfully deleted!\n\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Password not found for web address '%s'.\n\n", web_address);
}

void change_master_password() {
    printf("Enter current master password: ");
    char current_password[MAX_LENGTH];
    fgets(current_password, MAX_LENGTH, stdin);
    current_password[strcspn(current_password, "\n")] = 0;

    if (strcmp(current_password, master_password) != 0) {
        printf("Invalid password.\n\n");
        return;
    }

    printf("Enter new master password: ");
    char new_password[MAX_LENGTH];
    fgets(new_password, MAX_LENGTH, stdin);
    new_password[strcspn(new_password, "\n")] = 0;

    strcpy(master_password, new_password);
    printf("Master password has been successfully changed!\n\n");
}

int main() {
    strcpy(master_password, "password123");

    while (1) {
        printf("Enter master password: ");
        char input_password[MAX_LENGTH];
        fgets(input_password, MAX_LENGTH, stdin);
        input_password[strcspn(input_password, "\n")] = 0;

        if (strcmp(input_password, master_password) == 0) {
            break;
        }

        printf("Incorrect password. Try again.\n\n");
    }

    while (1) {
        printf("Select from the following options:\n");
        printf("1. Add a password.\n");
        printf("2. View all passwords.\n");
        printf("3. Delete a password.\n");
        printf("4. Change master password.\n");
        printf("5. Exit.\n");
        printf("Enter option (1-5): ");

        int option;
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                change_master_password();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option entered.\n\n");
                break;
        }
    }

    return 0;
}