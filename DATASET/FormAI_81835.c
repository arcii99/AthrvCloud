//FormAI DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 30
#define MAX_FILESYSTEM_SIZE 1000

// structure for each file
typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int starting_block;
} file_t;

file_t file_system[MAX_FILESYSTEM_SIZE]; // array to store all files
int free_blocks[MAX_FILESYSTEM_SIZE]; // array to keep track of free blocks
int num_blocks = 0; // total number of blocks in file system
int num_files = 0; // total number of files in file system

void initialize_file_system() {
    // initialize free block list with all blocks available
    for (int i = 0; i < MAX_FILESYSTEM_SIZE; i++) {
        free_blocks[i] = 1;
    }
    num_blocks = MAX_FILESYSTEM_SIZE;
}

int find_free_block(int size) {
    // find contiguous blocks of free space in the file system
    int count = 0;
    int start_block = -1;
    for (int i = 0; i < num_blocks; i++) {
        if (free_blocks[i] == 1) {
            if (count == 0) {
                start_block = i;
            }
            count++;
        } else {
            count = 0;
            start_block = -1;
        }
        if (count == size) {
            return start_block;
        }
    }
    return -1;
}

void add_file(char* name, int size) {
    int starting_block = find_free_block(size);
    if (starting_block == -1) {
        printf("Error: no free space in file system\n");
        return;
    }
    // mark blocks as used
    for (int i = starting_block; i < starting_block + size; i++) {
        free_blocks[i] = 0;
    }
    // add file to file system
    strcpy(file_system[num_files].name, name);
    file_system[num_files].size = size;
    file_system[num_files].starting_block = starting_block;
    num_files++;
    printf("Added file %s with size %d starting at block %d\n", name, size, starting_block);
}

void delete_file(char* name) {
    int index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: file not found\n");
        return;
    }
    int starting_block = file_system[index].starting_block;
    int size = file_system[index].size;
    // mark blocks as free
    for (int i = starting_block; i < starting_block + size; i++) {
        free_blocks[i] = 1;
    }
    // shift all files after deleted file left by size of deleted file
    for (int i = index; i < num_files - 1; i++) {
        file_system[i] = file_system[i + 1];
    }
    num_files--;
    printf("Deleted file %s\n", name);
}

void print_file_info(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_system[i].name, name) == 0) {
            printf("File %s\n", name);
            printf("Size: %d\n", file_system[i].size);
            printf("Starting block: %d\n", file_system[i].starting_block);
            return;
        }
    }
    printf("Error: file not found\n");
}

void print_file_system_info() {
    printf("File system info:\n");
    printf("Total blocks: %d\n", num_blocks);
    int used_blocks = 0;
    for (int i = 0; i < num_blocks; i++) {
        if (free_blocks[i] == 0) {
            used_blocks++;
        }
    }
    printf("Used blocks: %d\n", used_blocks);
    printf("Free blocks: %d\n", num_blocks - used_blocks);
    printf("Total files: %d\n", num_files);
    for (int i = 0; i < num_files; i++) {
        printf("- %s\n", file_system[i].name);
    }
}

int main() {
    initialize_file_system();
    add_file("fileA.txt", 10);
    add_file("fileB.txt", 5);
    add_file("fileC.txt", 8);
    print_file_system_info();
    delete_file("fileB.txt");
    print_file_system_info();
    print_file_info("fileA.txt");
    return 0;
}