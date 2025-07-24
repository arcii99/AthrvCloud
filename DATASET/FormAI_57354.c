//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORD_LENGTH 25
#define MAX_USER_COUNT 100

struct user {
    int id;
    char username[25];
    char password[MAX_PASSWORD_LENGTH];
};

struct user_database {
    struct user users[MAX_USER_COUNT];
    int current_user_count;
};

struct user_database password_db;

pthread_mutex_t db_mutex = PTHREAD_MUTEX_INITIALIZER;

void add_user(char *username, char *password) {
    pthread_mutex_lock(&db_mutex);

    // Check if user already exists
    for (int i = 0; i < password_db.current_user_count; i++) {
        if (strcmp(username, password_db.users[i].username) == 0) {
            printf("User already exists\n");
            pthread_mutex_unlock(&db_mutex);
            return;
        }
    }

    // Add user to database
    password_db.users[password_db.current_user_count].id = password_db.current_user_count + 1;
    strcpy(password_db.users[password_db.current_user_count].username, username);
    strcpy(password_db.users[password_db.current_user_count].password, password);
    password_db.current_user_count++;

    pthread_mutex_unlock(&db_mutex);
}

void *password_checker(void *params) {
    struct user *user_data = (struct user *) params;

    pthread_mutex_lock(&db_mutex);

    // Check if user exists in database
    for (int i = 0; i < password_db.current_user_count; i++) {
        if (strcmp(user_data->username, password_db.users[i].username) == 0) {
            // Check if password matches
            if (strcmp(user_data->password, password_db.users[i].password) == 0) {
                printf("User %s authenticated successfully\n", user_data->username);
                pthread_mutex_unlock(&db_mutex);
                return NULL;
            } else {
                printf("User %s provided an incorrect password\n", user_data->username);
                pthread_mutex_unlock(&db_mutex);
                return NULL;
            }
        }
    }

    printf("User %s is not registered in the system\n", user_data->username);
    pthread_mutex_unlock(&db_mutex);

    return NULL;
}

int main() {
    // Initialize database
    password_db.current_user_count = 0;

    // Add some users to the database
    add_user("user1", "password1");
    add_user("user2", "password2");
    add_user("user3", "password3");

    // Attempt to authenticate users in separate threads
    pthread_t threads[3];
    struct user user_data[3];

    strcpy(user_data[0].username, "user1");
    strcpy(user_data[0].password, "password1");
    pthread_create(&threads[0], NULL, password_checker, &user_data[0]);

    strcpy(user_data[1].username, "user2");
    strcpy(user_data[1].password, "password3");
    pthread_create(&threads[1], NULL, password_checker, &user_data[1]);

    strcpy(user_data[2].username, "user4");
    strcpy(user_data[2].password, "password4");
    pthread_create(&threads[2], NULL, password_checker, &user_data[2]);

    // Join threads to wait for their completion
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}