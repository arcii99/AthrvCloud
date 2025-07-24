//FormAI DATASET v1.0 Category: System administration ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    char choice[10];
    char username[20], password[20];
    printf("Welcome to the System Administration Program!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);
    if(strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("Login Successful!\n");
        while(1) {
            printf("\nPlease choose an option: \n");
            printf("1. Check Disk Space\n");
            printf("2. Check System Load\n");
            printf("3. List Running Processes\n");
            printf("4. Exit\n");
            scanf("%s", choice);
            if(strcmp(choice, "1") == 0) {
                strcpy(command, "df");
                system(command);
            }
            else if(strcmp(choice, "2") == 0) {
                strcpy(command, "top -bn1");
                system(command);
            }
            else if(strcmp(choice, "3") == 0) {
                strcpy(command, "ps -aux");
                system(command);
            }
            else if(strcmp(choice, "4") == 0) {
                printf("Exiting System Administration Program...\n");
                break;
            }
            else {
                printf("Invalid Choice! Please try again.\n");
            }
        }
    }
    else {
        printf("Login Failed! Incorrect Username or Password.\n");
    }
    return 0;
}