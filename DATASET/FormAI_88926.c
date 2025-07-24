//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char user[50];
    char password[50];
    char command[100];

    printf("Welcome to the System Administration Program!\n");
    printf("Please enter your username: ");
    scanf("%s", user);

    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(user, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("\nAccess Granted! What would you like to do?\n");

        while(1) {
            printf("\nEnter a command: ");
            fgets(command, sizeof(command), stdin);

            if (strstr(command, "shutdown")) {
                printf("\nSYSTEM SHUTDOWN INITIATED! Please save all work...\n");
                system("shutdown /s");
            } else if (strstr(command, "restart")) {
                printf("\nSYSTEM RESTART INITIATED! Please save all work...\n");
                system("shutdown /r");
            } else if (strstr(command, "users")) {
                system("net user");
            } else if (strstr(command, "processes")) {
                system("tasklist");
            } else if (strstr(command, "exit")) {
                printf("\nGoodbye, Admin!\n");
                break;
            } else {
                printf("\nUnknown Command!\n");
            }
        }
    } else {
        printf("\nAccess Denied! Incorrect Username or Password...\n");
    }

    return 0;
}