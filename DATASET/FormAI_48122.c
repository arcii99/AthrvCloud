//FormAI DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // size of each block
#define DISK_SIZE 10000 // number of blocks in disk
#define MAX_FILES 20 // maximum number of files
#define FILE_NAME_LEN 20 // maximum length of a file name

// define the file struct
typedef struct file_t {
    char name[FILE_NAME_LEN];
    int size;
    int start_block;
} file_t;

// define the disk struct
typedef struct disk_t {
    char data[DISK_SIZE][BLOCK_SIZE];
    int free_blocks;
} disk_t;

// define global variables
disk_t disk;
file_t files[MAX_FILES];
int num_files = 0;

// function to initialize the disk
void init_disk() {
    disk.free_blocks = DISK_SIZE;
    // clear all the blocks
    for (int i = 0; i < DISK_SIZE; i++) {
        memset(disk.data[i], 0, BLOCK_SIZE);
    }
}

// function to allocate a block of memory on the disk
int allocate_block() {
    if (disk.free_blocks == 0) {
        printf("Error: disk is full\n");
        return -1;
    }
    // find the first free block
    for (int i = 0; i < DISK_SIZE; i++) {
        if (strlen(disk.data[i]) == 0) {
            disk.free_blocks--;
            return i;
        }
    }
}

// function to create a new file on the disk
int create_file(char* name, int size) {
    if (num_files == MAX_FILES) {
        printf("Error: maximum number of files reached\n");
        return -1;
    }
    int start_block = allocate_block();
    if (start_block == -1) {
        return -1;
    }
    file_t f;
    strcpy(f.name, name);
    f.size = size;
    f.start_block = start_block;
    files[num_files] = f;
    num_files++;
    return 0;
}

// function to write data to a file on the disk
int write_file(char* name, char* data, int size) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // check if there is enough space on the disk
            if (size > disk.free_blocks * BLOCK_SIZE) {
                printf("Error: not enough space on the disk\n");
                return -1;
            }
            // write the data to the disk
            int block = files[i].start_block;
            int remaining_size = size;
            while (remaining_size > 0) {
                int write_size = remaining_size < BLOCK_SIZE ? remaining_size : BLOCK_SIZE;
                strncpy(disk.data[block], data, write_size);
                remaining_size -= write_size;
                data += write_size;
                block = allocate_block();
                if (block == -1) {
                    return -1;
                }
            }
            // update the file size
            files[i].size = size;
            return 0;
        }
    }
    printf("Error: file not found\n");
    return -1;
}

// function to read data from a file on the disk
int read_file(char* name, char* data, int size) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // check if the requested size is valid
            if (size > files[i].size) {
                printf("Error: requested size is greater than file size\n");
                return -1;
            }
            // read the data from the disk
            int block = files[i].start_block;
            int remaining_size = size;
            while (remaining_size > 0) {
                int read_size = remaining_size < BLOCK_SIZE ? remaining_size : BLOCK_SIZE;
                strncat(data, disk.data[block], read_size);
                remaining_size -= read_size;
                block++;
            }
            return 0;
        }
    }
    printf("Error: file not found\n");
    return -1;
}

int main() {
    // initialize the disk
    init_disk();

    // create a new file on the disk
    create_file("test.txt", 1024);

    // write data to the file
    char data[1024] = "This is a test file.";
    write_file("test.txt", data, strlen(data));

    // read data from the file
    char read_data[1024] = "";
    read_file("test.txt", read_data, strlen(data));
    printf("%s\n", read_data);

    return 0;
}