//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    struct User users[MAX_USERS];
    int userCount = 0;
    char choice[10];

    do {
        printf("\n1. Add User\n2. Remove User\n3. Change Password\n4. Display Users\n5. Exit\nEnter your choice: ");
        fgets(choice, 10, stdin);

        switch (atoi(choice)) {
            case 1:
                if (userCount < MAX_USERS) {
                    printf("\nEnter Username: ");
                    fgets(users[userCount].username, MAX_PASSWORD_LENGTH, stdin);

                    printf("Enter Password: ");
                    fgets(users[userCount].password, MAX_PASSWORD_LENGTH, stdin);

                    users[userCount].username[strcspn(users[userCount].username, "\n")] = 0;
                    users[userCount].password[strcspn(users[userCount].password, "\n")] = 0;

                    printf("User added successfully!\n");
                    userCount++;
                } else {
                    printf("Maximum Users Limit Reached!\n");
                }
                break;

            case 2:
                if (userCount > 0) {
                    char username[MAX_PASSWORD_LENGTH];
                    int index = -1;

                    printf("\nEnter Username: ");
                    fgets(username, MAX_PASSWORD_LENGTH, stdin);
                    username[strcspn(username, "\n")] = 0;

                    for (int i = 0; i < userCount; i++) {
                        if (strcmp(users[i].username, username) == 0) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        printf("User not found!\n");
                    } else {
                        for (int i = index; i < userCount - 1; i++) {
                            users[i] = users[i + 1];
                        }
                        userCount--;
                        printf("User removed successfully!\n");
                    }
                } else {
                    printf("No Users Found!\n");
                }
                break;

            case 3:
                if (userCount > 0) {
                    char username[MAX_PASSWORD_LENGTH];

                    printf("\nEnter Username: ");
                    fgets(username, MAX_PASSWORD_LENGTH, stdin);
                    username[strcspn(username, "\n")] = 0;

                    for (int i = 0; i < userCount; i++) {
                        if (strcmp(users[i].username, username) == 0) {
                            printf("Enter New Password: ");
                            fgets(users[i].password, MAX_PASSWORD_LENGTH, stdin);
                            users[i].password[strcspn(users[i].password, "\n")] = 0;
                            printf("Password Changed Successfully!\n");
                            break;
                        }
                    }
                } else {
                    printf("No Users Found!\n");
                }
                break;

            case 4:
                if (userCount > 0) {
                    printf("\nUsername\tPassword\n");
                    for (int i = 0; i < userCount; i++) {
                        printf("%s\t\t%s\n", users[i].username, users[i].password);
                    }
                } else {
                    printf("No Users Found!\n");
                }
                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try Again.\n");
        }
    } while (1);

    return 0;
}