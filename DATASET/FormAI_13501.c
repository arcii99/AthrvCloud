//FormAI DATASET v1.0 Category: Password management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERS 100

typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH + 1];
} User;

User users[MAX_USERS];
int num_users = 0;
pthread_mutex_t lock;


void *add_user(void *arg) {
    char *username = (char *)arg;
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter password for user %s: ", username);
    scanf("%s", password);
    
    pthread_mutex_lock(&lock);
    if (num_users < MAX_USERS) {
        User user;
        strcpy(user.username, username);
        strcpy(user.password, password);
        users[num_users] = user;
        num_users++;
        printf("User %s added successfully!\n", username);
    } else {
        printf("Maximum number of users reached. Cannot add user %s.\n", username);
    }
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void login(char *username, char *password) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            pthread_mutex_unlock(&lock);
            return;
        }
    }
    printf("Invalid username or password. Login failed.\n");
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    while (1) {
        printf("\n1) Add user\n2) Login\n3) Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char username[20];
                printf("Enter username: ");
                scanf("%s", username);
                pthread_create(&tid, NULL, add_user, username);
                break;
            case 2:
                char input_username[20], input_password[MAX_PASSWORD_LENGTH + 1];
                printf("Enter username: ");
                scanf("%s", input_username);
                printf("Enter password: ");
                scanf("%s", input_password);
                login(input_username, input_password);
                break;
            case 3:
                pthread_mutex_destroy(&lock);
                printf("Program exit.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    pthread_exit(NULL);
}