//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 30

char *passwords[MAX_PASSWORDS];

void initializePasswords() {
    for(int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = NULL;
    }
}

int passwordLength(char *password) {
    int length = 0;
    while(password[length] != '\0') {
        length++;
    }
    return length;
}

bool validPassword(char *password) {
    int length = passwordLength(password);
    if(length < 8 || length > MAX_PASSWORD_LENGTH) {
        return false;
    }
    bool containsLowercase = false;
    bool containsUppercase = false;
    bool containsDigit = false;
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            containsLowercase = true;
        }
        if(password[i] >= 'A' && password[i] <= 'Z') {
            containsUppercase = true;
        }
        if(password[i] >= '0' && password[i] <= '9') {
            containsDigit = true;
        }
    }
    return containsLowercase && containsUppercase && containsDigit;
}

void setPassword(char *password, int index) {
    if(validPassword(password)) {
        int length = passwordLength(password);
        passwords[index] = malloc(sizeof(char) * (length + 1));
        strcpy(passwords[index], password);
        printf("Password set successfully!\n");
    } else {
        printf("Invalid password! Password must be between 8 and %d characters long and must contain at least one lowercase letter, one uppercase letter, and one digit.\n", MAX_PASSWORD_LENGTH);
    }
}

void deletePassword(int index) {
    if(passwords[index] != NULL) {
        free(passwords[index]);
        passwords[index] = NULL;
        printf("Password deleted successfully!\n");
    } else {
        printf("Password already deleted!\n");
    }
}

void showPasswords() {
    printf("Passwords:\n");
    for(int i = 0; i < MAX_PASSWORDS; i++) {
        if(passwords[i] != NULL) {
            printf("%d. %s\n", i + 1, passwords[i]);
        }
    }
}

int main() {
    initializePasswords();
    while(true) {
        printf("Enter a command (set <index> <password>, delete <index>, show, exit):\n");
        char command[10];
        int index;
        char password[MAX_PASSWORD_LENGTH + 1];
        scanf("%s", command);
        if(strcmp(command, "set") == 0) {
            scanf("%d %s", &index, password);
            if(index < 1 || index > MAX_PASSWORDS) {
                printf("Invalid index! Index must be between 1 and %d.\n", MAX_PASSWORDS);
            } else {
                setPassword(password, index - 1);
            }
        } else if(strcmp(command, "delete") == 0) {
            scanf("%d", &index);
            if(index < 1 || index > MAX_PASSWORDS) {
                printf("Invalid index! Index must be between 1 and %d.\n", MAX_PASSWORDS);
            } else {
                deletePassword(index - 1);
            }
        } else if(strcmp(command, "show") == 0) {
            showPasswords();
        } else if(strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}