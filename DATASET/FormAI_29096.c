//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 1024
#define MAX_FILENAME_SIZE 30

// Struct for representing a file
typedef struct {
    char filename[MAX_FILENAME_SIZE];
    int start_block;
    int num_blocks;
} File;

// Globals
char *disk[MAX_BLOCKS]; // Array of pointers to disk blocks
File files[MAX_BLOCKS]; // Array of files
int num_files = 0; // Number of files on disk

// Function prototypes
void format_disk();
void create_file(char *filename, char *content);
void delete_file(char *filename);
void display_file(char *filename);
void list_files();
int find_free_block();
int find_file_index(char *filename);

int main() {

    // Initialize disk blocks to NULL
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = NULL;
    }

    // Format disk
    format_disk();

    // Create some sample files
    create_file("file1.txt", "This is file 1!");
    create_file("file2.txt", "This is file 2!");

    // Display all files on disk
    list_files();

    // Delete file2
    delete_file("file2.txt");

    // Display all files on disk again
    list_files();

    // Display contents of file1
    display_file("file1.txt");

    // Clean up memory and exit
    for (int i = 0; i < MAX_BLOCKS; i++) {
        free(disk[i]);
    }
    return 0;
}

// Format the disk by allocating memory for each block
void format_disk() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = malloc(BLOCK_SIZE);
    }
}

// Create a file with the given filename and content
void create_file(char *filename, char *content) {
    // Find a free block
    int start_block = find_free_block();
    if (start_block == -1) {
        printf("Error: no free blocks available\n");
        return;
    }

    // Calculate number of blocks needed for file
    int content_size = strlen(content);
    int num_blocks = content_size / BLOCK_SIZE;
    if (content_size % BLOCK_SIZE != 0) {
        num_blocks++;
    }

    // Check that filename is not already in use
    if (find_file_index(filename) != -1) {
        printf("Error: file %s already exists\n", filename);
        return;
    }

    // Copy filename to file struct
    strcpy(files[num_files].filename, filename);

    // Set start_block and num_blocks in file struct
    files[num_files].start_block = start_block;
    files[num_files].num_blocks = num_blocks;

    // Copy content to disk blocks
    int remaining_content = content_size;
    int current_block = start_block;
    int content_pos = 0;
    while (remaining_content > 0) {
        int copy_size = BLOCK_SIZE;
        if (remaining_content < BLOCK_SIZE) {
            copy_size = remaining_content;
        }
        memcpy(disk[current_block], content + content_pos, copy_size);
        remaining_content -= copy_size;
        current_block++;
        content_pos += copy_size;
    }

    // Increment num_files
    num_files++;
}

// Delete the file with the given filename
void delete_file(char *filename) {
    int file_index = find_file_index(filename);
    if (file_index == -1) {
        printf("Error: file %s does not exist\n", filename);
        return;
    }

    // Free disk blocks and remove file from files array
    int start_block = files[file_index].start_block;
    int num_blocks = files[file_index].num_blocks;
    for (int i = start_block; i < start_block + num_blocks; i++) {
        free(disk[i]);
        disk[i] = NULL;
    }
    for (int i = file_index; i < num_files - 1; i++) {
        files[i] = files[i+1];
    }
    num_files--;
}

// Display the contents of the file with the given filename
void display_file(char *filename) {
    int file_index = find_file_index(filename);
    if (file_index == -1) {
        printf("Error: file %s does not exist\n", filename);
        return;
    }

    // Display contents of each block
    int start_block = files[file_index].start_block;
    int num_blocks = files[file_index].num_blocks;
    for (int i = start_block; i < start_block + num_blocks; i++) {
        printf("%s", disk[i]);
    }
}

// List all files on the disk
void list_files() {
    printf("Files on disk:\n");
    for (int i = 0; i < num_files; i++) {
        printf("  %s\n", files[i].filename);
    }
}

// Find the first free block on the disk
int find_free_block() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (disk[i] == NULL) {
            return i;
        }
    }
    return -1;
}

// Find the index of the file with the given filename in the files array
int find_file_index(char *filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            return i;
        }
    }
    return -1;
}