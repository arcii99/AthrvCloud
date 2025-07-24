//FormAI DATASET v1.0 Category: Password management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[20];
    char password[20];
};

struct User users[] = {
    {"user1", "pass1"},
    {"user2", "pass2"},
    {"user3", "pass3"}
};

int main() {
    int choice;
    printf("Welcome to Password Management System!\n");
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Login\n2. Register\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                printf("Thank you for using Password Management System!\n");
                exit(0);
            default:
                printf("Invalid Choice, please choose again.\n");
        }
    }
    return 0;
}

void login() {
    char username[20];
    char password[20];
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);
    int i;
    for(i = 0; i < sizeof(users)/sizeof(struct User); i++) {
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }
    printf("Invalid username or password, please try again.\n");
}

void registerUser() {
    char username[20];
    char password[20];
    printf("Please enter your desired username: ");
    scanf("%s", username);
    printf("Please enter your desired password: ");
    scanf("%s", password);
    int i;
    for(i = 0; i < sizeof(users)/sizeof(struct User); i++) {
        if(strcmp(username, users[i].username) == 0) {
            printf("Username already exists, please try again.\n");
            return;
        }
    }
    struct User newUser = {username, password};
    users[sizeof(users)/sizeof(struct User)] = newUser;
    printf("User registered successfully!\n");
    printf("Please remember your login details:\nUsername: %s\nPassword: %s\n", username, password);
}