//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold system user information
struct User {
    char username[50];
    char password[50];
    int uid;
};

// A function to add a new user to the system file
void add_user(char *username, char *password, int uid) {
    FILE *system_file = fopen("/etc/system_users", "a+");
    fprintf(system_file, "%s:%s:%d\n", username, password, uid);
    fclose(system_file);
}

// A function to remove a user from the system file
void remove_user(char *username) {
    FILE *system_file = fopen("/etc/system_users", "r");
    FILE *new_file = fopen("/etc/system_users_new", "w");
    char line[100];
    
    while(fgets(line, 100, system_file)) {
        char *found = strstr(line, username);
        if(found == NULL) {
            fputs(line, new_file);
        }
    }
    
    fclose(system_file);
    fclose(new_file);
    
    remove("/etc/system_users");
    rename("/etc/system_users_new", "/etc/system_users");
}

// A function to search for a user by UID and return their username
char *search_user(int uid) {
    FILE *system_file = fopen("/etc/system_users", "r");
    char line[100];
    char *username = NULL;
    
    while(fgets(line, 100, system_file)) {
        char *token = strtok(line, ":");
        if(atoi(token) == uid) {
            username = strtok(NULL, ":");
            break;
        }
    }
    
    fclose(system_file);
    
    return username;
}

// A function to display all users in the system file
void display_users() {
    FILE *system_file = fopen("/etc/system_users", "r");
    char line[100];
    
    printf("%-20s %-20s %-10s\n", "USERNAME", "PASSWORD", "UID");
    printf("---------------------------------------------\n");
    
    while(fgets(line, 100, system_file)) {
        char *token = strtok(line, ":");
        printf("%-20s ", token);
        token = strtok(NULL, ":");
        printf("%-20s ", token);
        token = strtok(NULL, ":");
        printf("%-10s\n", token);
    }
    
    fclose(system_file);
}

int main() {
    int choice;
    char username[50];
    char password[50];
    int uid;
    
    while(1) {
        printf("\nSYSTEM ADMIN MENU\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. Search User by UID\n");
        printf("4. Display All Users\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                printf("Enter UID: ");
                scanf("%d", &uid);
                add_user(username, password, uid);
                printf("User added successfully!\n");
                break;
            case 2:
                printf("\nEnter username: ");
                scanf("%s", username);
                remove_user(username);
                printf("User removed successfully!\n");
                break;
            case 3:
                printf("\nEnter UID: ");
                scanf("%d", &uid);
                printf("Username: %s\n", search_user(uid));
                break;
            case 4:
                display_users();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}