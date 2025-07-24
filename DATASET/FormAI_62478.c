//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_LENGTH 20

typedef struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

typedef struct CredentialStore {
    User users[MAX_USERS];
    int num_users;
} CredentialStore;

void addUser(CredentialStore *store, char *username, char *password) {
    if (store->num_users >= MAX_USERS) {
        printf("Error: Store is full.\n");
        return;
    }

    int i;
    for (i = 0; i < store->num_users; i++) {
        if (strcmp(store->users[i].username, username) == 0) {
            printf("Error: Username already exists.\n");
            return;
        }
    }

    strcpy(store->users[store->num_users].username, username);
    strcpy(store->users[store->num_users].password, password);
    store->num_users++;
    printf("User added successfully.\n");
}

void removeUser(CredentialStore *store, char *username) {
    int i, found = 0;
    for (i = 0; i < store->num_users; i++) {
        if (strcmp(store->users[i].username, username) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Username not found.\n");
        return;
    }

    for (; i < store->num_users-1; i++) {
        store->users[i] = store->users[i+1];
    }

    store->num_users--;
    printf("User removed successfully.\n");
}

int main() {
    CredentialStore store;
    store.num_users = 0;

    addUser(&store, "user1", "password1");
    addUser(&store, "user2", "password2");
    addUser(&store, "user3", "password3");
    removeUser(&store, "user2");
    removeUser(&store, "user4");

    return 0;
}