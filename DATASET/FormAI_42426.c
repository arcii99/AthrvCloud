//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 100

struct user {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
};

struct user users[MAX_USERS];
int num_users = 0;
pthread_mutex_t users_lock;

// Adds a new user to the database
void add_user(char* username, char* password) {
    pthread_mutex_lock(&users_lock);

    // Check if the user already exists
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User already exists!\n");
            pthread_mutex_unlock(&users_lock);
            return;
        }
    }

    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached!\n");
        pthread_mutex_unlock(&users_lock);
        return;
    }

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;

    printf("User added successfully!\n");
    pthread_mutex_unlock(&users_lock);
}

// Checks whether a user's password is correct
int check_password(char* username, char* password) {
    pthread_mutex_lock(&users_lock);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                pthread_mutex_unlock(&users_lock);
                return 1;
            } else {
                pthread_mutex_unlock(&users_lock);
                return 0;
            }
        }
    }

    pthread_mutex_unlock(&users_lock);
    return 0;
}

void* thread_func(void* arg) {
    char* username = (char*) arg;
    char password[MAX_PASSWORD_LENGTH];

    printf("%s, enter your new password: ", username);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character at end of password
    password[strlen(password) - 1] = '\0';

    add_user(username, password);

    return NULL;
}

int main() {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];

    pthread_mutex_init(&users_lock, NULL);

    // Add some example users
    add_user("bob", "1234");
    add_user("alice", "5678");

    printf("Welcome to the password management program!\n");

    while (1) {
        printf("Enter your username (or 'exit' to quit): ");
        fgets(username, 20, stdin);

        // Remove newline character at end of username
        username[strlen(username) - 1] = '\0';

        if (strcmp(username, "exit") == 0) {
            break;
        }

        printf("Enter your password: ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);

        // Remove newline character at end of password
        password[strlen(password) - 1] = '\0';

        if (check_password(username, password)) {
            printf("Welcome, %s!\n", username);
            pthread_t tid;
            pthread_create(&tid, NULL, thread_func, (void*) username);
            pthread_join(tid, NULL);
        } else {
            printf("Incorrect username or password.\n");
        }
    }

    pthread_mutex_destroy(&users_lock);
    return 0;
}