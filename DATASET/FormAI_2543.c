//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 256
#define NUM_BLOCKS 1024
#define FILE_NAME_LENGTH 32

typedef struct {
    char filename[FILE_NAME_LENGTH];
    int file_size;
    int block_index;
} file;

int file_count = 0;

char *disk [NUM_BLOCKS];
int free_blocks[NUM_BLOCKS];

file files[NUM_BLOCKS];

void initialize_disk() {
    // Allocating memory to each block in the disk
    for (int i=0; i<NUM_BLOCKS; i++) {
        disk[i] = malloc(BLOCK_SIZE);
        // Marking all blocks as free
        free_blocks[i] = 1;
    }
}

void display_menu() {
    printf("\n------------------------------\n");
    printf("C File System Simulation\n");
    printf("------------------------------\n");
    printf("1. Create a file\n");
    printf("2. Delete a file\n");
    printf("3. Read a file\n");
    printf("4. Write to a file\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
}

int find_free_block() {
    for (int i=0; i<NUM_BLOCKS; i++) {
        if (free_blocks[i] == 1) {
            return i;
        }
    }
    return -1;
}

void create_file() {
    file new_file;
    printf("Enter file name: ");
    scanf("%s", new_file.filename);
    printf("Enter file size (in bytes): ");
    scanf("%d", &new_file.file_size);
    int num_blocks_required = (new_file.file_size / BLOCK_SIZE) + 1;
    int start_block = find_free_block();
    if (start_block != -1) {
        new_file.block_index = start_block;
        for (int i=start_block; i<(start_block+num_blocks_required); i++) {
            free_blocks[i] = 0;
        }
        files[file_count] = new_file;
        file_count++;
        printf("File created successfully!\n");
    } else {
        printf("Unable to create file. Not enough free space on disk.\n");
    }
}

void delete_file() {
    char filename[FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    int file_index = -1;
    for (int i=0; i<file_count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index != -1) {
        int start_block = files[file_index].block_index;
        int num_blocks_required = (files[file_index].file_size / BLOCK_SIZE) + 1;
        for (int i=start_block; i<(start_block+num_blocks_required); i++) {
            free_blocks[i] = 1;
            memset(disk[i], 0, BLOCK_SIZE);
        }
        printf("File deleted successfully!\n");
        for (int i=file_index; i<(file_count-1); i++) {
            files[i] = files[i+1];
        }
        file_count--;
    } else {
        printf("File not found.\n");
    }
}

void read_file() {
    char filename[FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    int file_index = -1;
    for (int i=0; i<file_count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index != -1) {
        printf("File contents:\n");
        int start_block = files[file_index].block_index;
        int num_blocks_required = (files[file_index].file_size / BLOCK_SIZE) + 1;
        for (int i=start_block; i<(start_block+num_blocks_required); i++) {
            printf("%s", disk[i]);
        }
    } else {
        printf("File not found.\n");
    }
}

void write_file() {
    char filename[FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    int file_index = -1;
    for (int i=0; i<file_count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index != -1) {
        printf("Enter text to write (max %d characters):\n", files[file_index].file_size);
        char input[BLOCK_SIZE];
        int blocks_written = 0;
        while (blocks_written < files[file_index].file_size) {
            int start_block = files[file_index].block_index + blocks_written / BLOCK_SIZE;
            if (start_block < NUM_BLOCKS) {
                // Prompt user for input and write it to disk
                scanf(" %[^\n]", input);
                strncpy(disk[start_block], input, BLOCK_SIZE);
                blocks_written += strlen(input);
            } else {
                printf("Not enough free space on disk.\n");
                break;
            }
        }
        printf("Text written to file successfully!\n");
    } else {
        printf("File not found.\n");
    }
}

int main() {
    initialize_disk();
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                read_file();
                break;
            case 4:
                write_file();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}