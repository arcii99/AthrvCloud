//FormAI DATASET v1.0 Category: File system simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

#define FILE_SYSTEM_SIZE 4096
#define BLOCK_SIZE 128
#define NUM_BLOCKS (FILE_SYSTEM_SIZE / BLOCK_SIZE)
#define FILE_NAME_SIZE 16
#define MAX_FILES 32

// Structure to represent a file in the file system
typedef struct {
    char name[FILE_NAME_SIZE];
    int size;
    int blocks[8];
    int block_count;
} File;

File files[MAX_FILES]; // Array to hold files in file system
char disk[FILE_SYSTEM_SIZE]; // Array to represent file system disk
int free_blocks[NUM_BLOCKS]; // Array to keep track of free blocks

// Initialize file system by marking all blocks as free and creating root directory
void init_file_system() {
    for(int i=0; i<NUM_BLOCKS; i++) {
        free_blocks[i] = 1; // 1 = free block
    }
    File root;
    strcpy(root.name, "root");
    root.size = 0;
    root.block_count = 0;
    files[0] = root;
}

// Add a new file to file system
void create_file(char* name, int size) {
    // Check if there is space to add new file
    int i=0;
    while(files[i].size > 0 && i<MAX_FILES) {
        i++;
    }
    if(i == MAX_FILES) {
        printf("Cannot create file. Maximum number of files reached.\n");
        return;
    }
    // Check if there is enough free space to store file
    int blocks_needed = (size / BLOCK_SIZE) + ((size % BLOCK_SIZE) != 0);
    int blocks_found = 0;
    int first_block = 0;
    for(int j=0; j<NUM_BLOCKS; j++) {
        if(free_blocks[j] == 1) {
            if(blocks_found == 0) {
                first_block = j;
            }
            blocks_found++;
            if(blocks_found == blocks_needed) {
                break;
            }
        } else {
            blocks_found = 0;
        }
    }
    if(blocks_found < blocks_needed) {
        printf("Cannot create file. Not enough space available.\n");
        return;
    }
    // Add file to file system and allocate blocks to it
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.block_count = blocks_needed;
    int current_block = first_block;
    for(int k=0; k<blocks_needed; k++) {
        free_blocks[current_block] = 0;
        new_file.blocks[k] = current_block;
        current_block++;
    }
    files[i] = new_file;
    printf("File '%s' created with size %d.\n", name, size);
}

// Delete a file from file system
void delete_file(char* name) {
    int i=0;
    while(strcmp(files[i].name, name) != 0 && i<MAX_FILES) {
        i++;
    }
    if(i == MAX_FILES) {
        printf("File '%s' not found.\n", name);
        return;
    }
    for(int j=0; j<files[i].block_count; j++) {
        free_blocks[files[i].blocks[j]] = 1;
    }
    files[i].size = 0;
    printf("File '%s' deleted.\n", name);
}

// List all files in file system
void list_files() {
    printf("Name\t\tSize\n");
    for(int i=0; i<MAX_FILES; i++) {
        if(files[i].size > 0) {
            printf("%s\t\t%d\n", files[i].name, files[i].size);
        }
    }
}

// Main function to run file system simulation
int main() {
    init_file_system();
    while(1) {
        printf("Enter command (create, delete, list): ");
        char command[16];
        scanf("%s", command);
        if(strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            char name[FILE_NAME_SIZE];
            scanf("%s", name);
            printf("Enter file size: ");
            int size;
            scanf("%d", &size);
            create_file(name, size);
        } else if(strcmp(command, "delete") == 0) {
            printf("Enter file name: ");
            char name[FILE_NAME_SIZE];
            scanf("%s", name);
            delete_file(name);
        } else if(strcmp(command, "list") == 0) {
            list_files();
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}