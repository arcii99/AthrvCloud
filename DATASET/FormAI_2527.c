//FormAI DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define NUM_BLOCKS 128
#define BLOCK_SIZE 512
#define FILENAME_SIZE 20
#define MAX_FILES 16

// define data structures
typedef struct {
    int file_length;
    char file_name[FILENAME_SIZE];
    int starting_block;
} file_entry;

typedef struct {
    char data[BLOCK_SIZE];
    int next_block;
} disk_block;

// initialize global variables
file_entry file_table[MAX_FILES];
disk_block disk[NUM_BLOCKS];
int next_free_block = 0;
int num_files = 0;

// function declarations
void format_disk();
int create_file(char* file_name, int file_length);
int delete_file(char* file_name);
int read_file(char* file_name, int offset, int num_bytes, char* buffer);
int write_file(char* file_name, int offset, int num_bytes, char* buffer);
void print_file_table();

// main function
int main() {
    format_disk();
    create_file("file1.txt", 1024);
    create_file("file2.txt", 2048);
    char buffer[512];
    sprintf(buffer, "Hello, world!");
    write_file("file1.txt", 0, strlen(buffer), buffer);
    read_file("file1.txt", 0, strlen(buffer), buffer);
    printf("%s\n", buffer);
    delete_file("file1.txt");
    print_file_table();
    return 0;
}

// initialize the disk
void format_disk() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        disk[i].next_block = i + 1;
    }
    disk[NUM_BLOCKS - 1].next_block = -1;
}

// create a new file
int create_file(char* file_name, int file_length) {
    // check if file name already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].file_name, file_name) == 0) {
            return -1;  // file name already exists
        }
    }

    // check if there is enough space on the disk
    int required_blocks = (file_length + BLOCK_SIZE - 1) / BLOCK_SIZE;
    if (required_blocks > NUM_BLOCKS - next_free_block) {
        return -2;  // not enough space on disk
    }

    // update file table
    strcpy(file_table[num_files].file_name, file_name);
    file_table[num_files].file_length = file_length;
    file_table[num_files].starting_block = next_free_block;

    // update disk
    int current_block = file_table[num_files].starting_block;
    for (int i = 0; i < required_blocks; i++) {
        disk[current_block].next_block = current_block + 1;
        current_block++;
    }
    disk[current_block - 1].next_block = -1;
    next_free_block = current_block;

    // increment file counter
    num_files++;

    return 0;  // success
}

// delete a file
int delete_file(char* file_name) {
    // find file in file table
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].file_name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        return -1;  // file not found
    }

    // update disk
    int current_block = file_table[file_index].starting_block;
    int next_block;
    while (current_block != -1) {
        next_block = disk[current_block].next_block;
        disk[current_block].next_block = current_block + 1;
        current_block = next_block;
    }

    // update file table
    for (int i = file_index; i < num_files - 1; i++) {
        file_table[i] = file_table[i + 1];
    }
    num_files--;

    return 0;  // success
}

// read from a file
int read_file(char* file_name, int offset, int num_bytes, char* buffer) {
    // find file in file table
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].file_name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        return -1;  // file not found
    }

    // calculate block number and offset within block for starting read
    int current_block = file_table[file_index].starting_block;
    int current_offset = offset % BLOCK_SIZE;
    int num_blocks_to_skip = offset / BLOCK_SIZE;
    for (int i = 0; i < num_blocks_to_skip; i++) {
        current_block = disk[current_block].next_block;
        if (current_block == -1) {
            return -2;  // read extends beyond end of file
        }
    }

    // read data from disk into buffer
    int bytes_left_to_read = num_bytes;
    int buffer_offset = 0;
    while (bytes_left_to_read > 0) {
        for (int i = current_offset; i < BLOCK_SIZE; i++) {
            if (bytes_left_to_read == 0) {
                break;
            }
            buffer[buffer_offset] = disk[current_block].data[i];
            buffer_offset++;
            bytes_left_to_read--;
        }
        if (bytes_left_to_read > 0) {
            current_block = disk[current_block].next_block;
            if (current_block == -1) {
                return -2;  // read extends beyond end of file
            }
            current_offset = 0;
        }
    }

    return 0;  // success
}

// write to a file
int write_file(char* file_name, int offset, int num_bytes, char* buffer) {
    // find file in file table
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_table[i].file_name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        return -1;  // file not found
    }

    // calculate block number and offset within block for starting write
    int current_block = file_table[file_index].starting_block;
    int current_offset = offset % BLOCK_SIZE;
    int num_blocks_to_skip = offset / BLOCK_SIZE;
    for (int i = 0; i < num_blocks_to_skip; i++) {
        current_block = disk[current_block].next_block;
        if (current_block == -1) {
            return -2;  // write extends beyond end of file
        }
    }

    // write data from buffer to disk
    int bytes_left_to_write = num_bytes;
    int buffer_offset = 0;
    while (bytes_left_to_write > 0) {
        for (int i = current_offset; i < BLOCK_SIZE; i++) {
            if (bytes_left_to_write == 0) {
                break;
            }
            disk[current_block].data[i] = buffer[buffer_offset];
            buffer_offset++;
            bytes_left_to_write--;
        }
        if (bytes_left_to_write > 0) {
            if (disk[current_block].next_block == -1) {
                // allocate a new block on the disk
                disk[current_block].next_block = next_free_block;
                next_free_block++;
                if (next_free_block >= NUM_BLOCKS) {
                    return -3;  // disk is full
                }
                disk[next_free_block].next_block = -1;
            }
            current_block = disk[current_block].next_block;
            current_offset = 0;
        }
    }

    // update file length if necessary
    if (file_table[file_index].file_length < offset + num_bytes) {
        file_table[file_index].file_length = offset + num_bytes;
    }

    return 0;  // success
}

// print the file table to stdout
void print_file_table() {
    printf("====================\n");
    printf(" FILE TABLE\n");
    printf("====================\n");
    for (int i = 0; i < num_files; i++) {
        printf("File name: %s\n", file_table[i].file_name);
        printf("File length: %d bytes\n", file_table[i].file_length);
        printf("Starting block: %d\n", file_table[i].starting_block);
        printf("====================\n");
    }
}