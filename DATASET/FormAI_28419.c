//FormAI DATASET v1.0 Category: File system simulation ; Style: protected
#include <stdio.h>
#include <string.h>

// Define constants
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024
#define FILENAME_SIZE 16
#define MAX_FILES 16
#define MAX_USERS 4

// Define structures
typedef struct {
    char name[FILENAME_SIZE];
    int start_block;
    int num_blocks;
    int owner;
    int permissions;
    int encrypted;
} file;

typedef struct {
    char username[16];
    char password[16];
    int files[MAX_FILES];
} user;

// Define global variables
int fat[NUM_BLOCKS];
file files[MAX_FILES];
user users[MAX_USERS];

// Function prototypes
void init_fat();
void init_files();
void init_users();
void login_prompt();
void print_files();
void create_file();
void delete_file();
void edit_file();
void encrypt_file();
int get_block();
void release_blocks(int start_block, int num_blocks);
int authenticate(char username[], char password[]);
void change_password();

// Main function
int main() {
    init_fat();
    init_files();
    init_users();
    login_prompt();
    return 0;
}

// Initialize file allocation table
void init_fat() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        fat[i] = -1;
    }
}

// Initialize file array
void init_files() {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        files[i].name[0] = '\0';
        files[i].start_block = -1;
        files[i].num_blocks = 0;
        files[i].owner = -1;
        files[i].permissions = 0;
        files[i].encrypted = 0;
    }
}

// Initialize user array
void init_users() {
    int i, j;
    for (i = 0; i < MAX_USERS; i++) {
        users[i].username[0] = '\0';
        users[i].password[0] = '\0';
        for (j = 0; j < MAX_FILES; j++) {
            users[i].files[j] = -1;
        }
    }
}

// Prompt user to login with username and password
void login_prompt() {
    char username[16];
    char password[16];
    int auth = 0;
    printf("== Welcome to FileSystem! ==\n");
    while (auth == 0) {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        if (authenticate(username, password) == 1) {
            auth = 1;
        } else {
            printf("Invalid username or password. Please try again.\n");
        }
    }
    printf("== Login successful! ==\n");
    printf("Type 'help' to see available commands.\n");
    while (1) {
        char command[16];
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("create: create a new file\n");
            printf("delete: delete an existing file\n");
            printf("edit: edit an existing file\n");
            printf("encrypt: encrypt or decrypt a file\n");
            printf("files: list all files\n");
            printf("logout: logout of file system\n");
            printf("passwd: change password\n");
            printf("help: show available commands\n");
        } else if (strcmp(command, "create") == 0) {
            create_file();
        } else if (strcmp(command, "delete") == 0) {
            delete_file();
        } else if (strcmp(command, "edit") == 0) {
            edit_file();
        } else if (strcmp(command, "encrypt") == 0) {
            encrypt_file();
        } else if (strcmp(command, "files") == 0) {
            print_files();
        } else if (strcmp(command, "logout") == 0) {
            printf("== Logout successful! ==\n");
            login_prompt();
        } else if (strcmp(command, "passwd") == 0) {
            change_password();
        } else {
            printf("Invalid command. Type 'help' to see available commands.\n");
        }
    }
}

// Print list of files
void print_files() {
    int i;
    printf("Files:\n");
    for (i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0] != '\0') {
            printf("%s\n", files[i].name);
        }
    }
}

// Create new file
void create_file() {
    int i, j;
    char name[FILENAME_SIZE];
    int owner = -1;
    int permissions = 0;
    int encrypted = 0;
    printf("File name: ");
    scanf("%s", name);
    printf("Owner's username: ");
    scanf("%s", users[owner].username);
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, users[owner].username) == 0) {
            owner = i;
            break;
        }
    }
    if (owner == -1) {
        printf("Invalid username.\n");
        return;
    }
    printf("Permissions (rwx): ");
    scanf("%d", &permissions);
    printf("Encrypted? (1 = yes, 0 = no): ");
    scanf("%d", &encrypted);
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }
    int num_blocks;
    printf("Number of blocks: ");
    scanf("%d", &num_blocks);
    int start_block = get_block();
    if (start_block == -1) {
        printf("No free blocks available.\n");
        return;
    }
    files[i].start_block = start_block;
    files[i].num_blocks = num_blocks;
    files[i].owner = owner;
    files[i].permissions = permissions;
    files[i].encrypted = encrypted;
    for (j = 0; j < MAX_FILES; j++) {
        if (users[owner].files[j] == -1) {
            users[owner].files[j] = i;
            break;
        }
    }
    strcpy(files[i].name, name);
    for (j = 0; j < num_blocks; j++) {
        fat[start_block + j] = i;
    }
    printf("File successfully created.\n");
}

// Delete existing file
void delete_file() {
    int i, j;
    char name[FILENAME_SIZE];
    printf("File name: ");
    scanf("%s", name);
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int owner = files[i].owner;
            for (j = 0; j < MAX_FILES; j++) {
                if (users[owner].files[j] == i) {
                    users[owner].files[j] = -1;
                    break;
                }
            }
            release_blocks(files[i].start_block, files[i].num_blocks);
            files[i].name[0] = '\0';
            files[i].start_block = -1;
            files[i].num_blocks = 0;
            files[i].owner = -1;
            files[i].permissions = 0;
            files[i].encrypted = 0;
            printf("File successfully deleted.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// Edit existing file
void edit_file() {
    int i, j;
    char name[FILENAME_SIZE];
    printf("File name: ");
    scanf("%s", name);
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if ((files[i].permissions & 0x4) == 0) {
                printf("This file cannot be edited.\n");
                return;
            }
            char data[BLOCK_SIZE];
            FILE *fptr;
            fptr = fopen(name, "w");
            printf("Enter data (maximum %d characters):\n", BLOCK_SIZE);
            scanf("%s", data);
            fwrite(data, sizeof(data), 1, fptr);
            fclose(fptr);
            printf("File successfully edited.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// Encrypt or decrypt a file
void encrypt_file() {
    int i, j;
    char name[FILENAME_SIZE];
    printf("File name: ");
    scanf("%s", name);
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if ((files[i].permissions & 0x2) == 0) {
                printf("This file cannot be encrypted or decrypted.\n");
                return;
            }
            if (files[i].encrypted == 1) {
                printf("File is already encrypted. Decrypting...\n");
                files[i].encrypted = 0;
            } else {
                printf("File is not encrypted. Encrypting...\n");
                files[i].encrypted = 1;
            }
            printf("File successfully encrypted or decrypted.\n");
            return;
        }
    }
    printf("File not found.\n");
}

// Get first free block and mark it as used in FAT
int get_block() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (fat[i] == -1) {
            fat[i] = -2;
            return i;
        }
    }
    return -1;
}

// Release blocks starting at specified block and number of blocks
void release_blocks(int start_block, int num_blocks) {
    int i;
    for (i = start_block; i < start_block + num_blocks; i++) {
        fat[i] = -1;
    }
}

// Authenticate user with username and password
int authenticate(char username[], char password[]) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if ((strcmp(users[i].username, username) == 0) && (strcmp(users[i].password, password) == 0)) {
            return 1;
        }
    }
    return 0;
}

// Change user's password
void change_password() {
    char username[16];
    char current_password[16];
    char new_password[16];
    int i;
    printf("Username: ");
    scanf("%s", username);
    printf("Current password: ");
    scanf("%s", current_password);
    printf("New password: ");
    scanf("%s", new_password);
    for (i = 0; i < MAX_USERS; i++) {
        if ((strcmp(users[i].username, username) == 0) && (strcmp(users[i].password, current_password) == 0)) {
            strcpy(users[i].password, new_password);
            printf("Password successfully changed.\n");
            return;
        }
    }
    printf("Invalid username or password.\n");
}