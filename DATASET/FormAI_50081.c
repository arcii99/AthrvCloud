//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the disk size and the block size
#define DISK_SIZE 1000
#define BLOCK_SIZE 10

// Defining the struct for the file
typedef struct File {
    char name[20];
    int start_block;
    int num_blocks;
} File;

// Defining the disk as a global variable
char disk[DISK_SIZE];

// Defining the function to initialize the disk
void initialize_disk() {
    memset(disk, '-', DISK_SIZE);
}

// Defining the function to print the contents of the disk
void print_disk() {
    printf("DISK CONTENTS:\n");
    for (int i=0; i<DISK_SIZE; i+=BLOCK_SIZE) {
        printf("%.*s ", BLOCK_SIZE, &disk[i]);
    }
    printf("\n");
}

// Defining the function to create a file
void create_file(char name[]) {
    // Checking if the filename already exists
    for (int i=0; i<DISK_SIZE; i+=BLOCK_SIZE) {
        if (memcmp(&disk[i], name, strlen(name)) == 0) {
            printf("Error: File '%s' already exists\n", name);
            return;
        }
    }

    // Finding available blocks to store the file
    int start_block = -1;
    for (int i=0; i<DISK_SIZE; i+=BLOCK_SIZE) {
        if (disk[i] == '-') {
            start_block = i;
            break;
        }
    }
    if (start_block == -1) {
        printf("Error: Disk is full\n");
        return;
    }

    // Calculating the number of blocks necessary for the file
    int num_blocks = (int)(strlen(name) + BLOCK_SIZE - 1) / BLOCK_SIZE;

    // Creating the file
    File new_file;
    strcpy(new_file.name, name);
    new_file.start_block = start_block;
    new_file.num_blocks = num_blocks;

    // Writing the file to the disk
    memcpy(&disk[start_block], name, strlen(name));
    for (int i=start_block+strlen(name); i<start_block+num_blocks*BLOCK_SIZE; i++) {
        disk[i] = '#';
    }

    printf("File '%s' created at block %d\n", name, start_block/BLOCK_SIZE);
}

// Defining the function to delete a file
void delete_file(char name[]) {
    // Finding the file and its location in the disk
    int file_index = -1;
    for (int i=0; i<DISK_SIZE; i+=BLOCK_SIZE) {
        if (memcmp(&disk[i], name, strlen(name)) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: File '%s' not found\n", name);
        return;
    }

    // Clearing and freeing the blocks used by the file
    int start_block = file_index;
    int num_blocks = (int)(strlen(name) + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (int i=start_block; i<start_block+num_blocks*BLOCK_SIZE; i++) {
        disk[i] = '-';
    }

    printf("File '%s' deleted from block %d\n", name, file_index/BLOCK_SIZE);
}

// Defining the main function
int main() {
    // Initializing the disk
    initialize_disk();

    // Creating files
    create_file("file1.txt");
    create_file("file2.txt");
    create_file("file3.txt");
    create_file("file4.txt");
    create_file("file5.txt");

    // Printing the disk contents
    print_disk();

    // Deleting files
    delete_file("file2.txt");
    delete_file("file4.txt");

    // Printing the disk contents again
    print_disk();

    return 0;
}