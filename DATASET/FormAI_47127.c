//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESYSTEM_SIZE 1024

typedef struct file_t {
    char name[16];
    int start_block;
    int end_block;
    int size;
} file;

typedef struct user_t {
    char username[16];
    int permissions;
} user;

int filesystem[FILESYSTEM_SIZE];
file files[32];
int file_count = 0;
user users[4];
int user_count = 0;

void create_file(char* name, int size, int permissions) {
    if (file_count >= 32) {
        printf("File system is full!\n");
        return;
    }
    int blocks_needed = size / 16;
    if (size % 16 != 0) {
        blocks_needed++;
    }
    int start_block = -1;
    int blocks_found = 0;
    for (int i = 0; i < FILESYSTEM_SIZE; i++) {
        if (filesystem[i] == 0) {
            blocks_found++;
            if (blocks_found == blocks_needed) {
                start_block = i - blocks_needed + 1;
                break;
            }
        } else {
            blocks_found = 0;
        }
    }
    if (start_block == -1) {
        printf("Not enough space in file system!\n");
        return;
    }
    int end_block = start_block + blocks_needed - 1;
    files[file_count].start_block = start_block;
    files[file_count].end_block = end_block;
    files[file_count].size = size;
    strncpy(files[file_count].name, name, 16);
    file_count++;
    for (int i = start_block; i <= end_block; i++) {
        filesystem[i] = file_count;
    }
    printf("File created successfully!\n");
}

void delete_file(char* name) {
    int file_index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("File not found!\n");
        return;
    }
    int start_block = files[file_index].start_block;
    int end_block = files[file_index].end_block;
    for (int i = start_block; i <= end_block; i++) {
        filesystem[i] = 0;
    }
    for (int i = file_index; i < file_count - 1; i++) {
        files[i] = files[i + 1];
    }
    file_count--;
    printf("File deleted successfully!\n");
}

void list_files() {
    printf("File system contents:\n");
    for (int i = 0; i < FILESYSTEM_SIZE; i++) {
        if (filesystem[i] != 0) {
            int file_index = filesystem[i] - 1;
            printf("%s\t%d\n", files[file_index].name, i);
        }
    }
}

void add_user(char* username, int permissions) {
    if (user_count >= 4) {
        printf("Maximum number of users reached!\n");
        return;
    }
    strncpy(users[user_count].username, username, 16);
    users[user_count].permissions = permissions;
    user_count++;
    printf("User added successfully!\n");
}

void remove_user(char* username) {
    int user_index = -1;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user_index = i;
            break;
        }
    }
    if (user_index == -1) {
        printf("User not found!\n");
        return;
    }
    for (int i = user_index; i < user_count - 1; i++) {
        users[i] = users[i + 1];
    }
    user_count--;
    printf("User removed successfully!\n");
}

void run_command(char* command) {
    char* token;
    token = strtok(command, " ");
    if (strcmp(token, "create") == 0) {
        char* name = strtok(NULL, " ");
        int size = atoi(strtok(NULL, " "));
        create_file(name, size, 0);
    } else if (strcmp(token, "delete") == 0) {
        char* name = strtok(NULL, " ");
        delete_file(name);
    } else if (strcmp(token, "list") == 0) {
        list_files();
    } else if (strcmp(token, "adduser") == 0) {
        char* username = strtok(NULL, " ");
        int permissions = atoi(strtok(NULL, " "));
        add_user(username, permissions);
    } else if (strcmp(token, "removeuser") == 0) {
        char* username = strtok(NULL, " ");
        remove_user(username);
    } else {
        printf("Invalid command!\n");
    }
}

int main() {
    // Initialize file system
    for (int i = 0; i < FILESYSTEM_SIZE; i++) {
        filesystem[i] = 0;
    }
    // Initialize users
    add_user("user1", 0);
    add_user("user2", 1);
    add_user("user3", 2);
    add_user("user4", 3);
    // Main loop
    char command[64];
    while (1) {
        printf("> ");
        fgets(command, 64, stdin);
        if (strlen(command) > 0 && command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }
        run_command(command);
    }
    return 0;
}