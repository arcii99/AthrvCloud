//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_USERS 5
#define MAX_PASSWORD_LENGTH 20

/* Struct for user data */
typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
} User;

/* Global variables */
pthread_mutex_t mutex;
User users[MAX_USERS];
int num_users = 0;

/* Function to add a new user */
void add_user(char username[], char password[]) {
    pthread_mutex_lock(&mutex);

    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    users[num_users++] = new_user;

    printf("User %s created.\n", new_user.username);

    pthread_mutex_unlock(&mutex);
}

/* Function to change a user's password */
void change_password(char username[], char old_password[], char new_password[]) {
    pthread_mutex_lock(&mutex);

    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, old_password) == 0) {
            strcpy(users[i].password, new_password);
            printf("Password for user %s changed.\n", username);
            pthread_mutex_unlock(&mutex);
            return;
        }
    }

    printf("Error: Invalid username/password combination.\n");

    pthread_mutex_unlock(&mutex);
}

/* Main function */
int main() {
    /* Initialize mutex */
    pthread_mutex_init(&mutex, NULL);

    /* Add some users */
    add_user("john", "password1");
    add_user("jane", "password2");
    add_user("alice", "password3");
    add_user("bob", "password4");
    add_user("dave", "password5");

    /* Change some passwords */
    change_password("john", "password1", "new_password1");
    change_password("jane", "password2", "new_password2");
    change_password("eve", "password3", "new_password3");

    /* Clean up */
    pthread_mutex_destroy(&mutex);

    return 0;
}