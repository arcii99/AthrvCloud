//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Constants
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define NUM_THREADS 3

// User struct
typedef struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

// Password management functions
void setPassword(User *user, char *new_password) {
    strcpy(user->password, new_password);
}

int verifyPassword(User user, char *password) {
    return strcmp(user.password, password);
}

// Thread function for changing password
void *changePassword(void *arg) {
    User *user = (User *)arg;
    char new_password[MAX_PASSWORD_LENGTH];
    printf("Enter new password for user %s: ", user->username);
    fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
    setPassword(user, new_password);
    printf("Password changed successfully for user %s\n", user->username);
    pthread_exit(NULL);
}

int main() {
    // Initialize users
    User users[NUM_THREADS];
    strcpy(users[0].username, "user1");
    strcpy(users[1].username, "user2");
    strcpy(users[2].username, "user3");
    strcpy(users[0].password, "password1");
    strcpy(users[1].password, "password2");
    strcpy(users[2].password, "password3");

    // Initialize threads
    pthread_t threads[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, changePassword, (void *)&users[i]);
    }

    // Wait for threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Verify new passwords
    char password[MAX_PASSWORD_LENGTH];
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Enter password for user %s: ", users[i].username);
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        if (verifyPassword(users[i], password) != 0) {
            printf("Incorrect password for user %s\n", users[i].username);
        } else {
            printf("Password verified for user %s\n", users[i].username);
        }
    }

    return 0;
}