//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>

#define FILE_COUNT 10
#define FILE_NAME_LENGTH 20
#define BLOCK_SIZE 64
#define BLOCK_COUNT 1024

typedef struct {
    char file_name[FILE_NAME_LENGTH];
    int start_block;
    int block_count;
} File;

char fs[BLOCK_COUNT * BLOCK_SIZE];
File files[FILE_COUNT];

// Set all file entries to empty
void initialize_files() {
    for (int i = 0; i < FILE_COUNT; ++i) {
        files[i].file_name[0] = '\0';
        files[i].start_block = -1;
        files[i].block_count = 0;
    }
}

// Return free block index
int get_free_block() {
    for (int i = 0; i < BLOCK_COUNT; ++i) {
        int offset = i * BLOCK_SIZE;
        if (fs[offset] == 0) {
            // Mark block as used
            fs[offset] = 1;
            return i;
        }
    }
    return -1;
}

// Add file to file system
void add_file(char *file_name, int size) {
    // Determine blocks needed for file
    int block_count = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) block_count++;

    // Get free blocks for file
    int start_block = get_free_block();
    if (start_block == -1) {
        printf("Error: No free blocks available\n");
        return;
    }

    int current_block = start_block;
    for (int i = 1; i < block_count; ++i) {
        int block = get_free_block();
        if (block == -1) {
            printf("Error: No free blocks available\n");
            return;
        }
        // Link blocks
        int offset = current_block * BLOCK_SIZE;
        *(int*)&fs[offset] = block;
        current_block = block;
    }

    // Add file entry
    for (int i = 0; i < FILE_COUNT; ++i) {
        if (files[i].file_name[0] == '\0') {
            // Found empty file entry
            File *file = &files[i];
            strcpy(file->file_name, file_name);
            file->start_block = start_block;
            file->block_count = block_count;
            printf("File %s added\n", file_name);
            return;
        }
    }
    printf("Error: No free file entries available\n");
}

// Remove file from file system
void remove_file(char *file_name) {
    for (int i = 0; i < FILE_COUNT; ++i) {
        File *file = &files[i];
        if (strcmp(file->file_name, file_name) == 0) {
            // Found matching file entry
            int current_block = file->start_block;
            for (int j = 0; j < file->block_count; ++j) {
                // Mark block as free
                int offset = current_block * BLOCK_SIZE;
                fs[offset] = 0;
                current_block = *(int*)&fs[offset];
            }
            // Clear file entry
            file->file_name[0] = '\0';
            file->start_block = -1;
            file->block_count = 0;
            printf("File %s removed\n", file_name);
            return;
        }
    }
    printf("Error: File %s not found\n", file_name);
}

// List all files in file system
void list_files() {
    printf("File System Contents:\n");
    for (int i = 0; i < FILE_COUNT; ++i) {
        File *file = &files[i];
        if (file->file_name[0] != '\0') {
            printf("%s - %d blocks\n", file->file_name, file->block_count);
        }
    }
}

int main() {
    initialize_files();

    add_file("file1", BLOCK_SIZE * 3);
    add_file("file2", BLOCK_SIZE);
    add_file("file3", BLOCK_SIZE * 5);
    list_files();

    remove_file("file2");
    add_file("file4", BLOCK_SIZE * 2);
    list_files();

    add_file("file5", BLOCK_SIZE * 10);
    return 0;
}