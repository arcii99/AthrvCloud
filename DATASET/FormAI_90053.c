//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 20 // Maximum length of filename
#define MAX_BLOCKS 100 // Number of blocks in the file system
#define BLOCK_SIZE 512 // Size of a block in bytes

typedef struct File {
    char name[MAX_FILENAME];
    int size;
    int start_block;
} File;

char file_system[MAX_BLOCKS * BLOCK_SIZE]; // The file system array
int FAT[MAX_BLOCKS]; // The file allocation table

void init_file_system() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        FAT[i] = -1; // Initialize FAT with -1 to represent that block is empty
    }
}

void create_file(char* filename, int size) {
    int num_blocks_needed = size / BLOCK_SIZE + 1; // Calculate number of blocks needed to store file
    int free_blocks = 0;
    int start_block = -1;

    // Search for free blocks 
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (FAT[i] == -1) {
            free_blocks++;
            if (free_blocks == num_blocks_needed) {
                start_block = i - num_blocks_needed + 1;
                break;
            }
        } else {
            free_blocks = 0;
        }
    }

    // If there is not enough free blocks to store file, return
    if (free_blocks < num_blocks_needed) {
        printf("Not enough free space to create file.\n");
        return;
    }

    // Update FAT to reflect allocated blocks for file
    for (int i = start_block; i < start_block + num_blocks_needed; i++) {
        FAT[i] = i + 1;
    }
    FAT[start_block + num_blocks_needed - 1] = -1;

    // Create new file object and add to file system
    File new_file = {0};
    strcpy(new_file.name, filename);
    new_file.size = size;
    new_file.start_block = start_block;
    memcpy(&file_system[start_block * BLOCK_SIZE], &new_file, sizeof(File));

    printf("File %s created successfully.\n", filename);
}

void delete_file(char* filename) {
    File* file = NULL;

    // Search for file in file system
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (FAT[i] == -1) {
            continue; // Empty block, skip
        }

        File* current_file = (File*) &file_system[i * BLOCK_SIZE];
        if (strcmp(current_file->name, filename) == 0) {
            file = current_file;
            break;
        }
    }

    // If file not found, return
    if (file == NULL) {
        printf("File %s not found.\n", filename);
        return;
    }

    // Update FAT to reflect free blocks
    int current_block = file->start_block;
    while (current_block != -1) {
        int next_block = FAT[current_block];
        FAT[current_block] = -1;
        current_block = next_block;
    }

    printf("File %s deleted successfully.\n", filename);
}

void display_file_system() {
    printf("File system:\n");

    // Print out blocks and their contents
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (i % 10 == 0) {
            printf("\nBLOCK   CONTENT\n");
        }
        printf("%05d   ", i);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%c", file_system[i * BLOCK_SIZE + j]);
        }
        printf("\n");
    }

    // Print out file allocation table
    printf("\nFile allocation table:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("%05d   %05d\n", i, FAT[i]);
    }
}

int main() {
    init_file_system();

    create_file("file1.txt", 1024);
    create_file("file2.txt", 2048);
    create_file("file3.txt", 512);

    display_file_system();

    delete_file("file2.txt");

    display_file_system();

    return 0;
}