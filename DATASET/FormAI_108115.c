//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 20
#define MAX_FILE_SIZE 50
#define MAX_NUM_FILES 10

typedef struct File {
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    int size;
} File;

typedef struct User {
    char username[20];
    int num_files;
    File files[MAX_NUM_FILES];
} User;

User users[2];
int num_users = 2;

void create_file(User *user) {
    if (user->num_files == MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    char name[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", name);
    // Check if file name already exists
    for (int i = 0; i < user->num_files; i++) {
        if (strcmp(user->files[i].name, name) == 0) {
            printf("Error: File name already exists.\n");
            return;
        }
    }
    // Create new file
    strcpy(user->files[user->num_files].name, name);
    user->files[user->num_files].size = 0;
    printf("File created successfully.\n");
    user->num_files++;
}

void write_file(User *user) {
    char name[MAX_FILE_NAME];
    char data[MAX_FILE_SIZE];
    printf("Enter file name: ");
    scanf("%s", name);
    // Find file with given name
    for (int i = 0; i < user->num_files; i++) {
        if (strcmp(user->files[i].name, name) == 0) {
            // Write data to file
            printf("Enter file data: ");
            scanf("%s", data);
            strcpy(user->files[i].data, data);
            user->files[i].size = strlen(data);
            printf("File %s written successfully.\n", name);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void read_file(User *user) {
    char name[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", name);
    // Find file with given name
    for (int i = 0; i < user->num_files; i++) {
        if (strcmp(user->files[i].name, name) == 0) {
            // Read data from file
            printf("File data: %s\n", user->files[i].data);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void delete_file(User *user) {
    char name[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", name);
    // Find file with given name
    for (int i = 0; i < user->num_files; i++) {
        if (strcmp(user->files[i].name, name) == 0) {
            // Delete file
            for (int j = i; j < user->num_files - 1; j++) {
                user->files[j] = user->files[j+1];
            }
            user->num_files--;
            printf("File %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void print_menu(User *user) {
    printf("Welcome %s!\n", user->username);
    printf("1. Create file\n");
    printf("2. Write file\n");
    printf("3. Read file\n");
    printf("4. Delete file\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int main() {
    // Initialize users
    strcpy(users[0].username, "John");
    users[0].num_files = 0;
    strcpy(users[1].username, "Jane");
    users[1].num_files = 0;
    
    // Login
    int user_id;
    printf("Enter user id (0 or 1): ");
    scanf("%d", &user_id);
    User *current_user = &users[user_id];
    
    // Main loop
    int choice;
    do {
        print_menu(current_user);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_file(current_user);
                break;
            case 2:
                write_file(current_user);
                break;
            case 3:
                read_file(current_user);
                break;
            case 4:
                delete_file(current_user);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 5);
    
    return 0;
}