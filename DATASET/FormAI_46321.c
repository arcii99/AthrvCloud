//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 // Block size is set to 1 KB
#define NUM_BLOCKS 1000 // Number of blocks available in the file system
#define FILE_NAME_SIZE 20 // Maximum length of a file name

// Struct for a file
typedef struct {
    char name[FILE_NAME_SIZE];
    int start_block;
    int num_blocks;
} file;

// Struct for a block
typedef struct {
    int next_block;
    char data[BLOCK_SIZE];
} block;

// Global variables
file file_table[NUM_BLOCKS];
block disk[NUM_BLOCKS];
int next_block = 0;

// Function to initialize the file system
void init_file_system() {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        disk[i].next_block = -1;
        memset(disk[i].data, '\0', BLOCK_SIZE);
        memset(file_table[i].name, '\0', FILE_NAME_SIZE);
        file_table[i].start_block = -1;
        file_table[i].num_blocks = 0;
    }
}

// Function to create a file
void create_file(char* file_name, int size) {
    if (next_block + size > NUM_BLOCKS) {
        printf("Error: Not enough space to create file.\n");
        return;
    }
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (file_table[i].name[0] == '\0') { // Found an empty slot in file table
            int j;
            int start_block = next_block;
            for (j = 0; j < size; j++) { // Reserve blocks for the file
                disk[next_block].next_block = (next_block + 1) % NUM_BLOCKS;
                next_block++;
            }
            disk[next_block - 1].next_block = -1; // Mark the last block as the end of the file
            strcpy(file_table[i].name, file_name);
            file_table[i].start_block = start_block;
            file_table[i].num_blocks = size;
            return;
        }
    }
    printf("Error: Too many files already exist.\n");
}

// Function to delete a file
void delete_file(char* file_name) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strcmp(file_table[i].name, file_name) == 0) { // Found the file in file table
            int j;
            for (j = file_table[i].start_block; j != -1; j = disk[j].next_block) { // Free blocks occupied by the file
                disk[j].next_block = -1;
                memset(disk[j].data, '\0', BLOCK_SIZE);
            }
            memset(file_table[i].name, '\0', FILE_NAME_SIZE);
            file_table[i].start_block = -1;
            file_table[i].num_blocks = 0;
            return;
        }
    }
    printf("Error: File does not exist.\n");
}

// Function to write data to a file
void write_to_file(char* file_name, char* data, int size) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strcmp(file_table[i].name, file_name) == 0) { // Found the file in file table
            if (file_table[i].num_blocks * BLOCK_SIZE < size) { // Check if file has enough space
                printf("Error: Not enough space in file.\n");
                return;
            }
            int block = file_table[i].start_block;
            int j = 0;
            while (j < size) { // Write data to blocks
                strncpy(disk[block].data, data + j, BLOCK_SIZE);
                j += BLOCK_SIZE;
                block = disk[block].next_block;
            }
            return;
        }
    }
    printf("Error: File does not exist.\n");
}

// Function to read data from a file
void read_from_file(char* file_name, char* data, int size) {
    int i;
    for (i = 0; i < NUM_BLOCKS; i++) {
        if (strcmp(file_table[i].name, file_name) == 0) { // Found the file in file table
            int block = file_table[i].start_block;
            int j = 0;
            while (j < size && block != -1) { // Read data from blocks
                strncat(data, disk[block].data, BLOCK_SIZE);
                j += BLOCK_SIZE;
                block = disk[block].next_block;
            }
            return;
        }
    }
    printf("Error: File does not exist.\n");
}

int main() {
    init_file_system();
    create_file("test.txt", 10);
    write_to_file("test.txt", "hello world", 11);
    char buffer[100];
    memset(buffer, '\0', 100);
    read_from_file("test.txt", buffer, 11);
    printf("%s\n", buffer);
    delete_file("test.txt");
    return 0;
}