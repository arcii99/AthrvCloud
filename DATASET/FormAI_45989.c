//FormAI DATASET v1.0 Category: File system simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILE_COUNT 100
#define MAX_FILE_NAME_LENGTH 20
#define BLOCK_SIZE 512
#define BLOCK_COUNT 2048

// Structs
typedef struct {
    int block_count;
    int block_pointers[10];
} inode;

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int inode_number;
} file_descriptor;

// Global Variables
inode filesystem_blocks[BLOCK_COUNT];
int free_blocks[BLOCK_COUNT];
file_descriptor file_table[MAX_FILE_COUNT];
int file_count = 0;

// Function Prototypes
void format_filesystem();
void create_file(char* filename);
void delete_file(char* filename);
int get_free_block();
inode* get_inode(int inode_number);
int get_file_inode(char* filename);
void list_files();

// Main Function
int main() {
    format_filesystem();

    // Create some files
    create_file("file1.txt");
    create_file("file2.txt");
    create_file("file3.txt");

    // Delete a file
    delete_file("file2.txt");

    // List files
    list_files();

    return 0;
}

// Functions
void format_filesystem() {
    // Clear out all filesystem blocks
    for (int i = 0; i < BLOCK_COUNT; i++) {
        memset(&filesystem_blocks[i], 0, sizeof(inode));
    }

    // Initialize free blocks
    for (int i = 0; i < BLOCK_COUNT; i++) {
        free_blocks[i] = 1;
    }

    // Mark blocks 0-9 as taken (reserved)
    for (int i = 0; i < 10; i++) {
        free_blocks[i] = 0;
    }

    // Initialize root directory inode
    inode* root_inode = get_inode(0);
    root_inode->block_count = 0;
}

void create_file(char* filename) {
    if (file_count >= MAX_FILE_COUNT) {
        printf("Unable to create file - maximum file count exceeded\n");
        return;
    }

    if (get_file_inode(filename) != -1) {
        printf("Unable to create file - file with same name already exists\n");
        return;
    }

    int inode_number = get_free_block();
    if (inode_number == -1) {
        printf("Unable to create file - no free inodes available\n");
        return;
    }

    inode* file_inode = get_inode(inode_number);
    file_inode->block_count = 0;

    file_descriptor new_descriptor;
    strncpy(new_descriptor.name, filename, MAX_FILE_NAME_LENGTH);
    new_descriptor.inode_number = inode_number;

    file_table[file_count++] = new_descriptor;

    printf("File created successfully\n");
}

void delete_file(char* filename) {
    int inode_number = get_file_inode(filename);
    if (inode_number == -1) {
        printf("Unable to delete file - file not found\n");
        return;
    }

    inode* file_inode = get_inode(inode_number);

    for (int i = 0; i < file_inode->block_count; i++) {
        free_blocks[file_inode->block_pointers[i]] = 1;
    }

    free_blocks[inode_number] = 1;

    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].name, filename) == 0) {
            // Found the file descriptor to remove, so shuffle other descriptors back
            for (int j = i + 1; j < file_count; j++) {
                file_table[j - 1] = file_table[j];
            }

            file_count--;

            printf("File deleted successfully\n");
            return;
        }
    }

    printf("Unable to delete file - file descriptor not found\n");
}

int get_free_block() {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        if (free_blocks[i] == 1) {
            free_blocks[i] = 0;
            return i;
        }
    }

    return -1;
}

inode* get_inode(int inode_number) {
    return &filesystem_blocks[inode_number];
}

int get_file_inode(char* filename) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].name, filename) == 0) {
            return file_table[i].inode_number;
        }
    }

    return -1;
}

void list_files() {
    printf("Files:\n");

    for (int i = 0; i < file_count; i++) {
        printf("- %s\n", file_table[i].name);
    }
}